#!/usr/bin/env python3
"""
Function Validator
Validates generated C++ functions meet all requirements
"""

import re
import subprocess
import argparse
from pathlib import Path
from typing import List, Dict, Tuple
from dataclasses import dataclass


@dataclass
class ValidationResult:
    """Result of validating a single function"""
    func_name: str
    passed: bool
    issues: List[str]
    warnings: List[str]
    line_count: int


class FunctionValidator:
    """Validates C++ functions against requirements"""

    # Prohibited includes (third-party libraries)
    PROHIBITED_INCLUDES = [
        'boost/', 'eigen/', 'opencv', 'tensorflow',
        'curl/', 'sqlite', 'mysql', 'postgres',
        'zmq', 'grpc', 'protobuf'
    ]

    # Required patterns for anti-optimization
    ANTI_OPT_PATTERNS = [
        r'cout\s*<<',  # cout usage
        r'volatile\s+',  # volatile keyword
        r'std::cout\s*<<',  # std::cout usage
    ]

    # Common problematic class names (as outer classes)
    PROBLEMATIC_NAMES = [
        r'\bclass\s+Node\b',
        r'\bstruct\s+Node\b',
        r'\bclass\s+TreeNode\b',
        r'\bstruct\s+TreeNode\b',
        r'\bclass\s+ListNode\b',
        r'\bstruct\s+ListNode\b',
    ]

    def __init__(self, strict: bool = False):
        self.strict = strict

    def count_lines(self, content: str) -> int:
        """Count non-empty, non-comment lines"""
        lines = content.split('\n')
        code_lines = 0

        in_multiline_comment = False
        for line in lines:
            stripped = line.strip()

            # Skip empty lines
            if not stripped:
                continue

            # Handle multi-line comments
            if '/*' in stripped:
                in_multiline_comment = True
            if '*/' in stripped:
                in_multiline_comment = False
                continue

            if in_multiline_comment:
                continue

            # Skip single-line comments
            if stripped.startswith('//'):
                continue

            code_lines += 1

        return code_lines

    def extract_function_body(self, cpp_content: str, func_name: str) -> str:
        """Extract function body from cpp file"""
        # Find function definition
        pattern = rf'{func_name}\s*\([^)]*\)\s*{{(.*?)}}(?:\s*(?:;|\n|$))'
        match = re.search(pattern, cpp_content, re.DOTALL)

        if match:
            return match.group(1)
        return cpp_content

    def check_includes(self, hpp_content: str) -> Tuple[bool, List[str]]:
        """Check for prohibited includes"""
        issues = []

        for prohibited in self.PROHIBITED_INCLUDES:
            if prohibited in hpp_content.lower():
                issues.append(f"Prohibited include found: {prohibited}")

        return len(issues) == 0, issues

    def check_anti_optimization(self, cpp_content: str) -> Tuple[bool, List[str]]:
        """Check for anti-optimization measures"""
        issues = []

        found_any = False
        for pattern in self.ANTI_OPT_PATTERNS:
            if re.search(pattern, cpp_content):
                found_any = True
                break

        if not found_any:
            issues.append("No anti-optimization measures found (need cout or volatile)")

        return found_any, issues

    def check_problematic_names(self, content: str) -> Tuple[bool, List[str]]:
        """Check for problematic class names"""
        warnings = []

        for pattern in self.PROBLEMATIC_NAMES:
            if re.search(pattern, content):
                match = re.search(pattern, content)
                warnings.append(f"Problematic class/struct name found: {match.group()}")

        return len(warnings) == 0, warnings

    def check_parameters(self, cpp_content: str, func_name: str) -> Tuple[bool, List[str]]:
        """Check function parameters have defaults or none"""
        issues = []

        # Find function signature
        pattern = rf'{func_name}\s*\(([^)]*)\)'
        match = re.search(pattern, cpp_content)

        if match:
            params = match.group(1).strip()

            # Empty parameters is OK
            if not params:
                return True, []

            # Check each parameter has default value
            param_list = [p.strip() for p in params.split(',')]
            for param in param_list:
                if param and '=' not in param:
                    issues.append(f"Parameter without default value: {param}")

        return len(issues) == 0, issues

    def check_static_global_vars(self, cpp_content: str) -> Tuple[bool, List[str]]:
        """Check for global or static variables"""
        warnings = []

        # Check for global variables (outside any function)
        lines = cpp_content.split('\n')
        in_function = False
        brace_count = 0

        for line in lines:
            stripped = line.strip()

            # Track if we're inside a function
            if '{' in line:
                brace_count += line.count('{')
                if brace_count > 0:
                    in_function = True

            if '}' in line:
                brace_count -= line.count('}')
                if brace_count == 0:
                    in_function = False

            # Check for static/global variables outside functions
            if not in_function and not stripped.startswith('//'):
                if re.search(r'\bstatic\s+\w+\s+\w+\s*[=;]', stripped):
                    warnings.append(f"Static variable found outside function: {stripped[:50]}")
                elif re.search(r'^(?:int|double|float|long|char|string|vector|map)\s+\w+\s*[=;]', stripped):
                    # Likely a global variable
                    if not '#include' in stripped and not 'using' in stripped:
                        warnings.append(f"Possible global variable: {stripped[:50]}")

        return True, warnings  # Warnings only, not failures

    def validate_function(self, func_name: str, base_path: Path) -> ValidationResult:
        """Validate a single function"""
        issues = []
        warnings = []

        cpp_path = base_path / 'src' / f'{func_name}.cpp'
        hpp_path = base_path / 'include' / f'{func_name}.hpp'

        # Check files exist
        if not cpp_path.exists():
            issues.append(f"CPP file not found: {cpp_path}")
            return ValidationResult(func_name, False, issues, warnings, 0)

        if not hpp_path.exists():
            issues.append(f"HPP file not found: {hpp_path}")
            return ValidationResult(func_name, False, issues, warnings, 0)

        # Read file contents
        cpp_content = cpp_path.read_text()
        hpp_content = hpp_path.read_text()

        # 1. Check line count
        function_body = self.extract_function_body(cpp_content, func_name)
        line_count = self.count_lines(function_body)

        if line_count < 40:
            warnings.append(f"Function is short ({line_count} lines, prefer 50-100)")
        elif line_count < 50:
            warnings.append(f"Function is slightly short ({line_count} lines)")
        elif line_count > 120:
            warnings.append(f"Function is long ({line_count} lines, prefer 50-100)")

        if line_count < 30 and self.strict:
            issues.append(f"Function too short ({line_count} lines)")

        # 2. Check prohibited includes
        passed, inc_issues = self.check_includes(hpp_content)
        if not passed:
            issues.extend(inc_issues)

        # 3. Check anti-optimization
        passed, opt_issues = self.check_anti_optimization(cpp_content)
        if not passed:
            issues.extend(opt_issues)

        # 4. Check problematic names
        passed, name_warnings = self.check_problematic_names(cpp_content + hpp_content)
        if not passed:
            warnings.extend(name_warnings)

        # 5. Check parameters
        passed, param_issues = self.check_parameters(cpp_content, func_name)
        if not passed:
            issues.extend(param_issues)

        # 6. Check static/global variables (warning only)
        _, var_warnings = self.check_static_global_vars(cpp_content)
        warnings.extend(var_warnings)

        passed = len(issues) == 0
        return ValidationResult(func_name, passed, issues, warnings, line_count)

    def compile_function(self, func_name: str, base_path: Path) -> Tuple[bool, str]:
        """Try to compile a single function"""
        cpp_path = base_path / 'src' / f'{func_name}.cpp'
        obj_path = base_path / 'obj' / f'{func_name}.o'

        # Create obj directory if needed
        obj_path.parent.mkdir(parents=True, exist_ok=True)

        cmd = [
            'g++', '-std=c++17', '-c',
            '-I', str(base_path / 'include'),
            '-o', str(obj_path),
            str(cpp_path)
        ]

        try:
            result = subprocess.run(
                cmd,
                capture_output=True,
                text=True,
                timeout=30
            )

            if result.returncode == 0:
                return True, "Compilation successful"
            else:
                return False, result.stderr

        except subprocess.TimeoutExpired:
            return False, "Compilation timeout"
        except Exception as e:
            return False, str(e)


class ProjectValidator:
    """Validates entire project"""

    def __init__(self, base_path: str, strict: bool = False):
        self.base_path = Path(base_path)
        self.strict = strict
        self.validator = FunctionValidator(strict)

    def find_functions(self) -> List[str]:
        """Find all function names in project"""
        src_dir = self.base_path / 'src'
        if not src_dir.exists():
            return []

        func_names = []
        for cpp_file in src_dir.glob('fun_*.cpp'):
            func_name = cpp_file.stem
            if func_name != 'FuncRunner':
                func_names.append(func_name)

        return sorted(func_names)

    def validate_all(self, compile_check: bool = False) -> Dict[str, ValidationResult]:
        """Validate all functions in project"""
        func_names = self.find_functions()
        results = {}

        print(f"\n🔍 Validating {len(func_names)} functions...\n")

        for i, func_name in enumerate(func_names, 1):
            print(f"[{i}/{len(func_names)}] Validating {func_name}...", end=' ')

            result = self.validator.validate_function(func_name, self.base_path)
            results[func_name] = result

            if result.passed:
                print("✓")
            else:
                print("✗")

            # Optional compilation check
            if compile_check and result.passed:
                compiled, msg = self.validator.compile_function(func_name, self.base_path)
                if not compiled:
                    result.passed = False
                    result.issues.append(f"Compilation failed: {msg[:100]}")

        return results

    def print_report(self, results: Dict[str, ValidationResult]):
        """Print validation report"""
        passed = sum(1 for r in results.values() if r.passed)
        failed = len(results) - passed

        print("\n" + "=" * 70)
        print("VALIDATION REPORT")
        print("=" * 70)

        print(f"\nTotal Functions: {len(results)}")
        print(f"✓ Passed: {passed}")
        print(f"✗ Failed: {failed}")

        # Statistics
        line_counts = [r.line_count for r in results.values()]
        if line_counts:
            avg_lines = sum(line_counts) / len(line_counts)
            print(f"\nAverage Lines: {avg_lines:.1f}")
            print(f"Min Lines: {min(line_counts)}")
            print(f"Max Lines: {max(line_counts)}")

        # Failed functions
        if failed > 0:
            print("\n" + "-" * 70)
            print("FAILED FUNCTIONS:")
            print("-" * 70)

            for func_name, result in results.items():
                if not result.passed:
                    print(f"\n❌ {func_name} ({result.line_count} lines)")
                    for issue in result.issues:
                        print(f"   - {issue}")

        # Warnings
        warnings_exist = any(r.warnings for r in results.values())
        if warnings_exist:
            print("\n" + "-" * 70)
            print("WARNINGS:")
            print("-" * 70)

            for func_name, result in results.items():
                if result.warnings:
                    print(f"\n⚠️  {func_name}")
                    for warning in result.warnings:
                        print(f"   - {warning}")

        print("\n" + "=" * 70 + "\n")

    def generate_markdown_report(self, results: Dict[str, ValidationResult], output_path: str):
        """Generate markdown report"""
        passed = sum(1 for r in results.values() if r.passed)
        failed = len(results) - passed

        md = "# Function Validation Report\n\n"
        md += f"**Generated:** {subprocess.check_output(['date']).decode().strip()}\n\n"

        md += "## Summary\n\n"
        md += f"- **Total Functions:** {len(results)}\n"
        md += f"- **Passed:** {passed} ✓\n"
        md += f"- **Failed:** {failed} ✗\n"
        md += f"- **Success Rate:** {passed/len(results)*100:.1f}%\n\n"

        # Statistics
        line_counts = [r.line_count for r in results.values()]
        if line_counts:
            md += "## Statistics\n\n"
            md += f"- **Average Lines:** {sum(line_counts)/len(line_counts):.1f}\n"
            md += f"- **Min Lines:** {min(line_counts)}\n"
            md += f"- **Max Lines:** {max(line_counts)}\n\n"

        # Failed functions
        if failed > 0:
            md += "## Failed Functions\n\n"
            for func_name, result in results.items():
                if not result.passed:
                    md += f"### {func_name}\n\n"
                    md += f"**Lines:** {result.line_count}\n\n"
                    md += "**Issues:**\n"
                    for issue in result.issues:
                        md += f"- {issue}\n"
                    md += "\n"

        # Write report
        Path(output_path).write_text(md)
        print(f"📄 Markdown report generated: {output_path}")


def main():
    parser = argparse.ArgumentParser(
        description='Validate C++ function library project'
    )
    parser.add_argument(
        'project_path',
        help='Path to project directory'
    )
    parser.add_argument(
        '--compile', '-c',
        action='store_true',
        help='Also attempt to compile each function'
    )
    parser.add_argument(
        '--strict', '-s',
        action='store_true',
        help='Enable strict validation (stricter line count requirements)'
    )
    parser.add_argument(
        '--report', '-r',
        help='Generate markdown report at specified path'
    )

    args = parser.parse_args()

    validator = ProjectValidator(args.project_path, args.strict)
    results = validator.validate_all(args.compile)
    validator.print_report(results)

    if args.report:
        validator.generate_markdown_report(results, args.report)


if __name__ == '__main__':
    main()
