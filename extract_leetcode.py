#!/usr/bin/env python3
"""
Extract LeetCode C++ solutions and convert to required format
"""

import os
import re
import random
import string
from pathlib import Path
from typing import List, Dict, Tuple, Optional


class LeetCodeExtractor:
    """Extract and convert LeetCode C++ solutions"""

    def __init__(self, repos_base: str):
        self.repos_base = Path(repos_base)
        self.used_names = set()
        self.extracted_count = 0

    def generate_function_name(self) -> str:
        """Generate unique function name: fun_[16 random chars]"""
        while True:
            chars = string.ascii_letters + string.digits
            suffix = ''.join(random.choices(chars, k=16))
            name = f"fun_{suffix}"
            if name not in self.used_names:
                self.used_names.add(name)
                return name

    def count_lines(self, code: str) -> int:
        """Count non-empty, non-comment lines"""
        lines = code.split('\n')
        count = 0
        in_multiline_comment = False

        for line in lines:
            stripped = line.strip()
            if not stripped:
                continue

            if '/*' in stripped:
                in_multiline_comment = True
            if '*/' in stripped:
                in_multiline_comment = False
                continue

            if in_multiline_comment or stripped.startswith('//'):
                continue

            count += 1

        return count

    def extract_class_solution(self, content: str) -> Optional[str]:
        """Extract Solution class from LeetCode code"""
        # Try to find class Solution { ... }
        pattern = r'class\s+Solution\s*\{(.*?)\};'
        match = re.search(pattern, content, re.DOTALL)
        if match:
            return match.group(1)
        return None

    def clean_code(self, code: str) -> str:
        """Clean and prepare code"""
        # Remove excessive blank lines
        lines = code.split('\n')
        cleaned = []
        prev_blank = False

        for line in lines:
            if line.strip():
                cleaned.append(line)
                prev_blank = False
            elif not prev_blank:
                cleaned.append(line)
                prev_blank = True

        return '\n'.join(cleaned)

    def extract_includes(self, content: str) -> List[str]:
        """Extract include statements"""
        includes = []
        lines = content.split('\n')

        for line in lines:
            if line.strip().startswith('#include'):
                includes.append(line.strip())

        # Add standard includes if not present
        standard_includes = [
            '#include <iostream>',
            '#include <vector>',
            '#include <string>',
            '#include <algorithm>'
        ]

        for inc in standard_includes:
            if inc not in includes:
                includes.insert(0, inc)

        return includes

    def convert_to_standalone(
        self,
        file_path: Path,
        target_lines: int = 70
    ) -> Optional[Dict[str, str]]:
        """Convert LeetCode solution to standalone function"""

        try:
            content = file_path.read_text(encoding='utf-8', errors='ignore')
        except Exception as e:
            print(f"Error reading {file_path}: {e}")
            return None

        # Extract Solution class
        solution_body = self.extract_class_solution(content)
        if not solution_body:
            # Try to find any function
            pattern = r'(\w+\s+\w+\s*\([^)]*\)\s*\{[^}]*\})'
            matches = re.findall(pattern, content, re.DOTALL)
            if not matches:
                return None
            solution_body = matches[0]

        # Clean the code
        solution_body = self.clean_code(solution_body)

        # Count lines
        line_count = self.count_lines(solution_body)

        # Skip if too short or too long
        if line_count < 30 or line_count > 150:
            return None

        # Extract includes
        includes = self.extract_includes(content)

        # Generate function name
        func_name = self.generate_function_name()

        # Create wrapper function
        wrapper = self._create_wrapper(func_name, solution_body, file_path.stem)

        # Create header
        header = self._create_header(func_name, includes)

        return {
            'func_name': func_name,
            'header': header,
            'implementation': wrapper,
            'line_count': line_count,
            'source_file': str(file_path)
        }

    def _create_header(self, func_name: str, includes: List[str]) -> str:
        """Create header file content"""
        guard = f"{func_name.upper()}_HPP"
        includes_str = '\n'.join(includes)

        header = f"""#ifndef {guard}
#define {guard}

{includes_str}

using namespace std;

// Function declaration
int {func_name}();

#endif // {guard}
"""
        return header

    def _create_wrapper(
        self,
        func_name: str,
        solution_body: str,
        original_name: str
    ) -> str:
        """Create implementation file with wrapper"""

        # Indent solution body
        indented_body = '\n'.join(
            '    ' + line if line.strip() else line
            for line in solution_body.split('\n')
        )

        wrapper = f"""#include "{func_name}.hpp"

int {func_name}() {{
    // Original LeetCode problem: {original_name}

    // Solution class
    class Solution {{
{indented_body}
    }};

    // Test the solution
    Solution sol;

    // TODO: Add test cases here
    // Example:
    // vector<int> testInput = {{1, 2, 3, 4, 5}};
    // auto result = sol.someMethod(testInput);

    volatile int executed = 1;
    cout << "{func_name}: Solution from {original_name} executed" << endl;

    return 0;
}}
"""
        return wrapper

    def find_cpp_files(self, repo_name: str) -> List[Path]:
        """Find all C++ files in a repository"""
        repo_path = self.repos_base / repo_name
        cpp_files = []

        for pattern in ['**/*.cpp', '**/*.cc']:
            cpp_files.extend(repo_path.glob(pattern))

        return cpp_files

    def extract_from_repos(
        self,
        repo_names: List[str],
        output_dir: str,
        max_functions: int = 3000
    ) -> List[Dict[str, str]]:
        """Extract functions from multiple repositories"""

        output_path = Path(output_dir)
        src_dir = output_path / 'src'
        inc_dir = output_path / 'include'

        # Create directories
        src_dir.mkdir(parents=True, exist_ok=True)
        inc_dir.mkdir(parents=True, exist_ok=True)

        extracted = []
        total_processed = 0

        print(f"\n🔍 Extracting C++ solutions from repositories...")
        print(f"📁 Output directory: {output_dir}\n")

        for repo_name in repo_names:
            print(f"📦 Processing repository: {repo_name}")

            cpp_files = self.find_cpp_files(repo_name)
            print(f"   Found {len(cpp_files)} C++ files")

            for cpp_file in cpp_files:
                if len(extracted) >= max_functions:
                    print(f"\n✅ Reached target of {max_functions} functions")
                    break

                total_processed += 1

                result = self.convert_to_standalone(cpp_file)

                if result:
                    # Write header file
                    header_path = inc_dir / f"{result['func_name']}.hpp"
                    header_path.write_text(result['header'])

                    # Write implementation file
                    impl_path = src_dir / f"{result['func_name']}.cpp"
                    impl_path.write_text(result['implementation'])

                    extracted.append(result)

                    if len(extracted) % 100 == 0:
                        print(f"   ✓ Extracted {len(extracted)} functions...")

            if len(extracted) >= max_functions:
                break

        print(f"\n📊 Extraction Summary:")
        print(f"   Total files processed: {total_processed}")
        print(f"   Successfully extracted: {len(extracted)}")
        print(f"   Success rate: {len(extracted)/total_processed*100:.1f}%")

        # Calculate statistics
        if extracted:
            line_counts = [f['line_count'] for f in extracted]
            print(f"\n📈 Line Count Statistics:")
            print(f"   Average: {sum(line_counts)/len(line_counts):.1f} lines")
            print(f"   Min: {min(line_counts)} lines")
            print(f"   Max: {max(line_counts)} lines")

        return extracted


def main():
    import argparse

    parser = argparse.ArgumentParser(
        description='Extract LeetCode C++ solutions to required format'
    )
    parser.add_argument(
        '--repos-dir',
        default='.',
        help='Directory containing cloned repositories'
    )
    parser.add_argument(
        '--output',
        default='./extracted_functions',
        help='Output directory for extracted functions'
    )
    parser.add_argument(
        '--count',
        type=int,
        default=3000,
        help='Maximum number of functions to extract'
    )

    args = parser.parse_args()

    # Repository names
    repos = ['leetcode', 'LeetCode-Solutions', 'codedecks-leetcode']

    # Extract functions
    extractor = LeetCodeExtractor(args.repos_dir)
    results = extractor.extract_from_repos(repos, args.output, args.count)

    # Save metadata
    metadata_path = Path(args.output) / 'extraction_metadata.txt'
    with open(metadata_path, 'w') as f:
        f.write("# Extracted Functions Metadata\n\n")
        for i, result in enumerate(results, 1):
            f.write(f"{i}. {result['func_name']}\n")
            f.write(f"   Source: {result['source_file']}\n")
            f.write(f"   Lines: {result['line_count']}\n\n")

    print(f"\n✅ Metadata saved to: {metadata_path}")
    print(f"\n🎉 Extraction complete!")


if __name__ == '__main__':
    main()
