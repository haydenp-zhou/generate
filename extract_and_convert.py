#!/usr/bin/env python3
"""
Advanced LeetCode C++ solution extractor with test data generation
"""

import os
import re
import random
import string
from pathlib import Path
from typing import List, Dict, Tuple, Optional


class AdvancedLeetCodeExtractor:
    """Extract and convert LeetCode solutions with intelligent test generation"""

    def __init__(self, repos_base: str):
        self.repos_base = Path(repos_base)
        self.used_names = set()
        self.extracted_count = 0

    def generate_function_name(self) -> str:
        """Generate unique function name"""
        while True:
            chars = string.ascii_letters + string.digits
            suffix = ''.join(random.choices(chars, k=16))
            name = f"fun_{suffix}"
            if name not in self.used_names:
                self.used_names.add(name)
                return name

    def count_code_lines(self, code: str) -> int:
        """Count actual code lines (non-empty, non-comment)"""
        lines = code.split('\n')
        count = 0
        in_comment = False

        for line in lines:
            stripped = line.strip()
            if not stripped:
                continue
            if '/*' in line:
                in_comment = True
            if '*/' in line:
                in_comment = False
                continue
            if in_comment or stripped.startswith('//'):
                continue
            count += 1

        return count

    def extract_solution_class(self, content: str) -> Optional[Tuple[str, str]]:
        """Extract Solution class and its method"""
        # Find class Solution { ... }
        class_pattern = r'class\s+Solution\s*\{(.*?)\};'
        class_match = re.search(class_pattern, content, re.DOTALL)

        if not class_match:
            return None

        class_body = class_match.group(1)

        # Find the main public method
        method_pattern = r'((?:vector|string|int|bool|double|void|ListNode\*|TreeNode\*)[^{]*\([^)]*\)\s*\{(?:[^{}]|\{[^{}]*\})*\})'
        methods = re.findall(method_pattern, class_body, re.DOTALL)

        if not methods:
            return None

        # Get the longest method (usually the main solution)
        main_method = max(methods, key=len)

        return class_body, main_method

    def detect_return_type(self, method: str) -> str:
        """Detect return type from method signature"""
        match = re.match(r'\s*([\w:<>,\*]+)\s+\w+\s*\(', method)
        if match:
            return match.group(1)
        return "auto"

    def detect_method_name(self, class_body: str) -> str:
        """Detect main public method name"""
        # Look for public methods
        public_section = re.search(r'public:\s*(.*)', class_body, re.DOTALL)
        if not public_section:
            return "solve"

        public_code = public_section.group(1)

        # Find first method definition (not a keyword)
        keywords = {'if', 'for', 'while', 'switch', 'return', 'break', 'continue'}
        method_pattern = r'(\w+)\s*\('

        for match in re.finditer(method_pattern, public_code):
            method_name = match.group(1)
            if method_name not in keywords and not method_name.startswith('_'):
                return method_name

        return "solve"

    def generate_test_data(self, class_body: str) -> Tuple[str, str]:
        """Generate appropriate test data and parameter call"""

        test_data = []
        param_call = []

        # Detect parameter types from method signatures
        if 'vector<int>' in class_body:
            test_data.append('vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};')
            param_call.append('nums')

        if 'vector<vector<int>>' in class_body:
            test_data.append('vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};')
            if 'matrix' not in param_call:
                param_call.append('matrix')

        if 'vector<string>' in class_body:
            test_data.append('vector<string> strs = {"hello", "world", "test", "code"};')
            if not param_call or 'vector<int>' not in class_body:
                param_call.append('strs')

        if 'string&' in class_body or 'string ' in class_body:
            if 'vector<string>' not in class_body:
                test_data.append('string s = "abcdefghijklmnop";')
                if not param_call:
                    param_call.append('s')

        if 'int target' in class_body or 'int k' in class_body or 'int n' in class_body:
            test_data.append('int n = 15;')
            if 'vector' not in class_body and not param_call:
                param_call.append('n')

        # Default if nothing detected
        if not test_data:
            test_data.append('int testValue = 42;')
            param_call.append('testValue')

        return '\n    '.join(test_data), ', '.join(param_call)

    def create_standalone_function(
        self,
        func_name: str,
        class_body: str,
        method: str,
        problem_name: str
    ) -> str:
        """Create standalone function with test harness"""

        return_type = self.detect_return_type(method)
        method_name = self.detect_method_name(class_body)
        test_data, param_call = self.generate_test_data(class_body)

        # Indent class body
        indented_class = '\n'.join(
            '    ' + line if line.strip() else ''
            for line in class_body.split('\n')
        )

        cpp = f"""#include "{func_name}.hpp"

int {func_name}() {{
    // LeetCode Problem: {problem_name}

    // Solution class
    class Solution {{
{indented_class}
    }};

    // Create test instance
    Solution sol;

    // Generate test data
    {test_data}

    // Execute solution
    try {{
        volatile auto result = sol.{method_name}({param_call});

        // Print result to prevent optimization
        cout << "{func_name}: Executed {method_name}() from {problem_name}" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    }} catch (const exception& e) {{
        cout << "{func_name}: Exception during execution: " << e.what() << endl;
        return 0;
    }}
}}
"""
        return cpp

    def create_header(self, func_name: str, has_vector: bool, has_queue: bool, has_map: bool) -> str:
        """Create header file"""
        guard = f"{func_name.upper()}_HPP"

        includes = ['#include <iostream>']

        if has_vector:
            includes.append('#include <vector>')
        if has_queue:
            includes.append('#include <queue>')
        if has_map:
            includes.append('#include <unordered_map>')
            includes.append('#include <map>')

        includes.extend([
            '#include <string>',
            '#include <algorithm>',
            '#include <exception>'
        ])

        includes_str = '\n'.join(includes)

        return f"""#ifndef {guard}
#define {guard}

{includes_str}

using namespace std;

int {func_name}();

#endif // {guard}
"""

    def detect_includes_needed(self, code: str) -> Tuple[bool, bool, bool]:
        """Detect which includes are needed"""
        has_vector = 'vector<' in code
        has_queue = 'queue<' in code or 'priority_queue<' in code
        has_map = 'map<' in code or 'unordered_map<' in code
        return has_vector, has_queue, has_map

    def extract_problem_name(self, file_path: Path) -> str:
        """Extract problem name from file path"""
        name = file_path.stem
        # Convert CamelCase or snake_case to readable name
        name = re.sub(r'([A-Z])', r' \1', name).strip()
        name = name.replace('_', ' ').replace('-', ' ')
        return name.title()

    def process_file(self, file_path: Path) -> Optional[Dict]:
        """Process a single C++ file"""
        try:
            content = file_path.read_text(encoding='utf-8', errors='ignore')
        except:
            return None

        # Extract solution
        result = self.extract_solution_class(content)
        if not result:
            return None

        class_body, main_method = result

        # Count lines in solution
        line_count = self.count_code_lines(class_body)

        # Filter by line count (we want substantial functions)
        if line_count < 20 or line_count > 200:
            return None

        # Generate function name
        func_name = self.generate_function_name()
        problem_name = self.extract_problem_name(file_path)

        # Detect includes
        has_vector, has_queue, has_map = self.detect_includes_needed(content)

        # Create files
        header = self.create_header(func_name, has_vector, has_queue, has_map)
        implementation = self.create_standalone_function(
            func_name, class_body, main_method, problem_name
        )

        return {
            'func_name': func_name,
            'header': header,
            'implementation': implementation,
            'line_count': line_count,
            'problem_name': problem_name,
            'source_file': str(file_path)
        }

    def extract_batch(
        self,
        repo_names: List[str],
        output_dir: str,
        max_count: int = 3000
    ) -> List[Dict]:
        """Extract functions in batch"""

        output_path = Path(output_dir)
        src_dir = output_path / 'src'
        inc_dir = output_path / 'include'

        src_dir.mkdir(parents=True, exist_ok=True)
        inc_dir.mkdir(parents=True, exist_ok=True)

        results = []
        processed = 0
        skipped = 0

        print(f"\n🚀 Starting extraction from {len(repo_names)} repositories")
        print(f"📁 Output: {output_dir}")
        print(f"🎯 Target: {max_count} functions\n")

        for repo_name in repo_names:
            if len(results) >= max_count:
                break

            repo_path = self.repos_base / repo_name
            if not repo_path.exists():
                print(f"⚠️  Repository not found: {repo_name}")
                continue

            print(f"📦 Processing: {repo_name}")

            # Find all C++ files
            cpp_files = list(repo_path.glob('**/*.cpp'))
            cpp_files.extend(repo_path.glob('**/*.cc'))

            print(f"   Found {len(cpp_files)} C++ files")

            for cpp_file in cpp_files:
                if len(results) >= max_count:
                    break

                processed += 1

                result = self.process_file(cpp_file)

                if result:
                    # Write files
                    hpp_path = inc_dir / f"{result['func_name']}.hpp"
                    cpp_path = src_dir / f"{result['func_name']}.cpp"

                    hpp_path.write_text(result['header'])
                    cpp_path.write_text(result['implementation'])

                    results.append(result)

                    if len(results) % 50 == 0:
                        print(f"   ✓ {len(results)}/{max_count} extracted...")
                else:
                    skipped += 1

            print(f"   ✅ Extracted {len(results)} functions from {repo_name}\n")

        # Print summary
        print(f"\n{'='*60}")
        print(f"📊 EXTRACTION SUMMARY")
        print(f"{'='*60}")
        print(f"Files processed:      {processed}")
        print(f"Functions extracted:  {len(results)}")
        print(f"Files skipped:        {skipped}")
        print(f"Success rate:         {len(results)/processed*100:.1f}%")

        if results:
            lines = [r['line_count'] for r in results]
            print(f"\n📈 Line Count Statistics:")
            print(f"Average:  {sum(lines)/len(lines):.1f} lines")
            print(f"Min:      {min(lines)} lines")
            print(f"Max:      {max(lines)} lines")
            print(f"Median:   {sorted(lines)[len(lines)//2]} lines")

        return results


def main():
    import argparse

    parser = argparse.ArgumentParser(description='Extract LeetCode C++ solutions')
    parser.add_argument('--repos', default='.', help='Repos directory')
    parser.add_argument('--output', default='./extracted_leetcode', help='Output directory')
    parser.add_argument('--count', type=int, default=3000, help='Max functions')

    args = parser.parse_args()

    repos = ['leetcode', 'LeetCode-Solutions', 'codedecks-leetcode']

    extractor = AdvancedLeetCodeExtractor(args.repos)
    results = extractor.extract_batch(repos, args.output, args.count)

    # Save metadata
    if results:
        metadata_file = Path(args.output) / 'extraction_log.txt'
        with open(metadata_file, 'w') as f:
            f.write("# Extracted LeetCode Functions\n\n")
            for i, r in enumerate(results, 1):
                f.write(f"{i}. {r['func_name']}\n")
                f.write(f"   Problem: {r['problem_name']}\n")
                f.write(f"   Lines: {r['line_count']}\n")
                f.write(f"   Source: {r['source_file']}\n\n")

        print(f"\n📝 Metadata saved to: {metadata_file}")

    print(f"\n✅ Extraction complete!\n")


if __name__ == '__main__':
    main()
