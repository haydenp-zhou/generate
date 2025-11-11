#!/usr/bin/env python3
"""
Generic C++ function extractor for TheAlgorithms and similar repositories
Converts standalone algorithm files to our function format
"""

import os
import re
import random
import string
from pathlib import Path
from typing import List, Dict, Tuple, Optional


class GenericAlgorithmExtractor:
    """Extract and convert C++ algorithms to our function format"""

    def __init__(self, repo_path: str):
        self.repo_path = Path(repo_path)
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

    def extract_includes(self, content: str) -> List[str]:
        """Extract all #include statements"""
        includes = []
        for line in content.split('\n'):
            if line.strip().startswith('#include'):
                includes.append(line.strip())
        return includes

    def is_standard_library(self, include: str) -> bool:
        """Check if include is from standard library"""
        std_headers = [
            'iostream', 'vector', 'string', 'algorithm', 'map', 'set',
            'unordered_map', 'unordered_set', 'queue', 'stack', 'deque',
            'list', 'array', 'memory', 'utility', 'functional', 'numeric',
            'random', 'cmath', 'cstdlib', 'cstring', 'cstdio', 'cassert',
            'climits', 'cfloat', 'cctype', 'ctime', 'sstream', 'fstream',
            'iomanip', 'bitset', 'tuple', 'chrono', 'thread', 'mutex',
            'condition_variable', 'atomic', 'future', 'exception', 'stdexcept'
        ]

        for header in std_headers:
            if f'<{header}>' in include or f'<c{header}>' in include:
                return True
        return False

    def extract_namespace_content(self, content: str) -> str:
        """Extract content from namespace declarations"""
        # Remove namespace wrapper but keep the content
        namespace_pattern = r'namespace\s+\w+\s*\{(.*?)\}(?:\s*//.*)?'
        matches = re.findall(namespace_pattern, content, re.DOTALL)
        if matches:
            return '\n'.join(matches)
        return content

    def wrap_as_function(
        self,
        content: str,
        func_name: str,
        algorithm_name: str
    ) -> Tuple[str, str]:
        """Wrap algorithm code as a standalone function"""

        # Extract includes
        includes = self.extract_includes(content)
        std_includes = [inc for inc in includes if self.is_standard_library(inc)]

        # Remove all #include and comments at the beginning
        code_without_includes = re.sub(r'#include\s+[<"][^>"]+[>"]', '', content)
        code_without_includes = re.sub(r'/\*\*.*?\*/', '', code_without_includes, flags=re.DOTALL)

        # Extract namespace content
        code_without_includes = self.extract_namespace_content(code_without_includes)

        # Remove test() and main() functions
        code_without_includes = re.sub(
            r'static\s+void\s+test\s*\([^)]*\)\s*\{.*?\}',
            '',
            code_without_includes,
            flags=re.DOTALL
        )
        code_without_includes = re.sub(
            r'int\s+main\s*\([^)]*\)\s*\{.*?\}',
            '',
            code_without_includes,
            flags=re.DOTALL
        )

        # Clean up the code
        code_lines = []
        for line in code_without_includes.split('\n'):
            stripped = line.strip()
            if stripped and not stripped.startswith('//'):
                code_lines.append(line)

        function_body = '\n'.join(code_lines)

        # Add test call if there are functions defined
        if 'void ' in function_body or 'int ' in function_body or 'uint' in function_body:
            # Extract function names to create sample calls
            func_pattern = r'(?:uint\d+_t|int|double|float)\s+(\w+)\s*\([^)]*\)'
            func_names = re.findall(func_pattern, function_body)

            test_calls = []
            if func_names:
                # Use the first function found for testing
                first_func = func_names[0]
                test_calls.append(f'\n        // Test the algorithm implementation')
                test_calls.append(f'        cout << "Testing {algorithm_name}..." << endl;')
                # Add sample execution based on common patterns
                if 'sort' in algorithm_name.lower():
                    test_calls.append(f'        vector<int> test_arr = {{5, 2, 8, 1, 9}};')
                elif 'search' in algorithm_name.lower():
                    test_calls.append(f'        vector<int> test_arr = {{1, 2, 3, 4, 5}};')
                elif 'power' in algorithm_name.lower() or 'exp' in algorithm_name.lower():
                    test_calls.append(f'        auto result = {first_func}(2, 10, 1000);')
                    test_calls.append(f'        cout << "Result: " << result << endl;')
                else:
                    test_calls.append(f'        cout << "Algorithm functions available" << endl;')

            function_body += '\n' + '\n'.join(test_calls)

        # Create header file
        header = f"""#ifndef {func_name.upper()}_HPP
#define {func_name.upper()}_HPP

"""

        # Add unique includes
        for inc in sorted(set(std_includes)):
            header += f"{inc}\n"

        header += f"""
using namespace std;

int {func_name}();

#endif // {func_name.upper()}_HPP
"""

        # Create implementation file
        implementation = f"""#include "{func_name}.hpp"

// Original algorithm: {algorithm_name}
int {func_name}() {{
    try {{
{self.indent_code(function_body, 8)}

        volatile int status = 1;
        cout << "{func_name}: {algorithm_name} executed" << endl;
        return const_cast<const int&>(status);
    }} catch (const exception& e) {{
        cout << "{func_name}: Exception - " << e.what() << endl;
        return 0;
    }}
}}
"""

        return header, implementation

    def indent_code(self, code: str, spaces: int) -> str:
        """Indent code by specified spaces"""
        indent = ' ' * spaces
        lines = code.split('\n')
        return '\n'.join(indent + line if line.strip() else '' for line in lines)

    def process_file(self, cpp_file: Path) -> Optional[Dict]:
        """Process a single C++ file"""

        try:
            content = cpp_file.read_text(encoding='utf-8', errors='ignore')
        except Exception as e:
            return None

        # Skip files with non-standard library dependencies
        includes = self.extract_includes(content)
        for inc in includes:
            if not self.is_standard_library(inc) and '#include' in inc:
                # Check if it's a local include
                if '"' in inc:
                    return None

        # Count lines
        line_count = self.count_code_lines(content)

        # Skip files that are too short (less than 10 lines)
        if line_count < 10:
            return None

        # Generate function name
        func_name = self.generate_function_name()

        # Get algorithm name from file path
        algorithm_name = cpp_file.stem.replace('_', ' ').title()

        # Wrap as function
        header, implementation = self.wrap_as_function(content, func_name, algorithm_name)

        # Count lines in the generated implementation
        impl_line_count = self.count_code_lines(implementation)

        return {
            'func_name': func_name,
            'algorithm_name': algorithm_name,
            'header': header,
            'implementation': implementation,
            'line_count': impl_line_count,
            'source_file': str(cpp_file.relative_to(self.repo_path))
        }

    def extract_batch(
        self,
        output_dir: str,
        max_count: int = 1000
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

        print(f"\n🚀 Starting extraction from TheAlgorithms repository")
        print(f"📁 Repository: {self.repo_path}")
        print(f"📁 Output: {output_dir}")
        print(f"🎯 Target: {max_count} functions\n")

        # Find all C++ files
        cpp_files = list(self.repo_path.glob('**/*.cpp'))
        cpp_files.extend(self.repo_path.glob('**/*.cc'))

        print(f"📦 Found {len(cpp_files)} C++ files\n")

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

                if len(results) % 25 == 0:
                    print(f"   ✓ {len(results)}/{max_count} extracted...")
            else:
                skipped += 1

        # Print summary
        print(f"\n{'='*60}")
        print(f"📊 EXTRACTION SUMMARY")
        print(f"{'='*60}")
        print(f"Files processed:      {processed}")
        print(f"Functions extracted:  {len(results)}")
        print(f"Files skipped:        {skipped}")

        if processed > 0:
            print(f"Success rate:         {len(results)/processed*100:.1f}%")

        if results:
            lines = [r['line_count'] for r in results]
            print(f"\n📈 Line Count Statistics:")
            print(f"Average:  {sum(lines)/len(lines):.1f} lines")
            print(f"Min:      {min(lines)} lines")
            print(f"Max:      {max(lines)} lines")

        return results


def main():
    import argparse

    parser = argparse.ArgumentParser(description='Extract C++ algorithms')
    parser.add_argument('--repo', required=True, help='Repository path')
    parser.add_argument('--output', default='./algorithms_extracted', help='Output directory')
    parser.add_argument('--count', type=int, default=1000, help='Max functions')

    args = parser.parse_args()

    extractor = GenericAlgorithmExtractor(args.repo)
    results = extractor.extract_batch(args.output, args.count)

    # Save metadata
    if results:
        metadata_file = Path(args.output) / 'extraction_log.txt'
        with open(metadata_file, 'w') as f:
            f.write("# Extracted Algorithm Functions\n\n")
            for i, r in enumerate(results, 1):
                f.write(f"{i}. {r['func_name']}\n")
                f.write(f"   Algorithm: {r['algorithm_name']}\n")
                f.write(f"   Lines: {r['line_count']}\n")
                f.write(f"   Source: {r['source_file']}\n\n")

        print(f"\n📝 Metadata saved to: {metadata_file}")

    print(f"\n✅ Extraction complete!\n")
    print(f"📊 Total extracted: {len(results)} functions")


if __name__ == '__main__':
    main()
