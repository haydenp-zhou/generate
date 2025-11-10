#!/usr/bin/env python3
"""
Create FuncRunner class for all extracted functions
"""

from pathlib import Path
from typing import List


def create_funcrunner(src_dir: str, output_dir: str):
    """Generate FuncRunner class"""

    src_path = Path(src_dir)
    output_path = Path(output_dir)

    # Find all function source files
    cpp_files = sorted(src_path.glob('fun_*.cpp'))
    func_names = [f.stem for f in cpp_files]

    print(f"Found {len(func_names)} functions")

    # Create FuncRunner.hpp
    hpp_content = """#ifndef FUNCRUNNER_HPP
#define FUNCRUNNER_HPP

class FuncRunner {
public:
    static void initFuncRunner();
};

#endif // FUNCRUNNER_HPP
"""

    # Create FuncRunner.cpp
    includes = '\n'.join([f'#include "{name}.hpp"' for name in func_names])
    calls = '\n    '.join([f'{name}();' for name in func_names])

    cpp_content = f"""#include <iostream>
#include "FuncRunner.hpp"
{includes}

void FuncRunner::initFuncRunner() {{
    std::cout << "=== FuncRunner: Starting execution of {len(func_names)} functions ===" << std::endl;

    {calls}

    std::cout << "=== FuncRunner: Completed execution of all functions ===" << std::endl;
}}
"""

    # Write files
    inc_dir = output_path / 'include'
    src_dir_out = output_path / 'src'

    inc_dir.mkdir(parents=True, exist_ok=True)
    src_dir_out.mkdir(parents=True, exist_ok=True)

    (inc_dir / 'FuncRunner.hpp').write_text(hpp_content)
    (src_dir_out / 'FuncRunner.cpp').write_text(cpp_content)

    print(f"✓ Created FuncRunner.hpp")
    print(f"✓ Created FuncRunner.cpp")
    print(f"✓ Includes {len(func_names)} function calls")

    return func_names


def create_cmake(func_names: List[str], project_dir: str, project_name: str = "LeetCodeLibrary"):
    """Generate CMakeLists.txt"""

    project_path = Path(project_dir)

    sources = '\n'.join([f'    src/{name}.cpp' for name in func_names])

    cmake = f"""cmake_minimum_required(VERSION 3.10)
project({project_name} CXX)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra)
endif()

# Include directories
include_directories(${{CMAKE_SOURCE_DIR}}/include)

# Source files
set(SOURCES
    src/FuncRunner.cpp
{sources}
)

# Create static library
add_library({project_name} STATIC ${{SOURCES}})

# Test executable
add_executable({project_name}_test main.cpp)
target_link_libraries({project_name}_test {project_name})

# Installation
install(TARGETS {project_name} DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
"""

    (project_path / 'CMakeLists.txt').write_text(cmake)
    print(f"✓ Created CMakeLists.txt")


def create_main_cpp(project_dir: str):
    """Generate main.cpp"""

    main_content = """#include <iostream>
#include "FuncRunner.hpp"

int main() {
    std::cout << "LeetCode Functions Library - Test Runner" << std::endl;
    std::cout << "========================================" << std::endl;

    try {
        FuncRunner::initFuncRunner();
        std::cout << "\\n✓ All functions executed successfully!" << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "\\n✗ Error: " << e.what() << std::endl;
        return 1;
    }
}
"""

    (Path(project_dir) / 'main.cpp').write_text(main_content)
    print(f"✓ Created main.cpp")


def create_readme(project_dir: str, func_count: int):
    """Generate README.md"""

    readme = f"""# LeetCode C++ Functions Library

Extracted and converted LeetCode solutions into standalone C++ functions.

## Statistics

- **Total Functions**: {func_count}
- **Source**: LeetCode problems from multiple repositories
- **Format**: Standalone functions with test harnesses
- **Standard**: C++17

## Building

```bash
mkdir build && cd build
cmake ..
make -j8
```

## Running

```bash
./LeetCodeLibrary_test
```

## Structure

```
.
├── include/          # Header files ({func_count} functions + FuncRunner)
├── src/              # Implementation files
├── CMakeLists.txt    # Build configuration
├── main.cpp          # Test driver
└── README.md         # This file
```

## Function Naming

All functions follow the pattern: `fun_[16 random chars]()`

Examples:
- fun_A1b2C3d4E5f6G7h8()
- fun_X9y8Z7w6V5u4T3s2()

## Notes

- All functions are self-contained
- Uses only C++17 standard library
- No external dependencies
- Each function has built-in test data
- Anti-optimization measures (cout + volatile)
"""

    (Path(project_dir) / 'README.md').write_text(readme)
    print(f"✓ Created README.md")


def main():
    import argparse

    parser = argparse.ArgumentParser(description='Create FuncRunner for extracted functions')
    parser.add_argument('--input', required=True, help='Input directory with src/ folder')
    parser.add_argument('--output', help='Output directory (default: same as input)')

    args = parser.parse_args()

    input_dir = Path(args.input)
    output_dir = Path(args.output) if args.output else input_dir

    src_dir = input_dir / 'src'

    if not src_dir.exists():
        print(f"Error: {src_dir} does not exist")
        return 1

    print(f"\n🔨 Creating FuncRunner...")
    print(f"📁 Input: {input_dir}")
    print(f"📁 Output: {output_dir}\n")

    func_names = create_funcrunner(str(src_dir), str(output_dir))
    create_cmake(func_names, str(output_dir))
    create_main_cpp(str(output_dir))
    create_readme(str(output_dir), len(func_names))

    print(f"\n✅ FuncRunner creation complete!")
    print(f"\n📝 Next steps:")
    print(f"   cd {output_dir}")
    print(f"   mkdir build && cd build")
    print(f"   cmake ..")
    print(f"   make -j8")
    print(f"   ./LeetCodeLibrary_test\n")


if __name__ == '__main__':
    main()
