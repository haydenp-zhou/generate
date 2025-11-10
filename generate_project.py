#!/usr/bin/env python3
"""
C++ Function Project Generator
Automatically generates project structure for standalone C++ functions
"""

import os
import random
import string
import argparse
from pathlib import Path
from typing import List, Tuple


class FunctionNameGenerator:
    """Generate unique function names with format: fun_XXXXXXXXXXXXXXXX"""

    def __init__(self):
        self.used_names = set()

    def generate(self) -> str:
        """Generate a unique function name"""
        while True:
            # Generate 16 random characters (letters and digits)
            chars = string.ascii_letters + string.digits
            suffix = ''.join(random.choices(chars, k=16))
            name = f"fun_{suffix}"

            if name not in self.used_names:
                self.used_names.add(name)
                return name

    def generate_batch(self, count: int) -> List[str]:
        """Generate multiple unique function names"""
        return [self.generate() for _ in range(count)]


class FileTemplateGenerator:
    """Generate .hpp and .cpp file templates"""

    @staticmethod
    def generate_hpp(func_name: str, includes: List[str] = None) -> str:
        """Generate header file content"""
        guard = f"{func_name.upper()}_HPP"

        default_includes = [
            "#include <iostream>",
            "#include <vector>",
            "#include <string>",
            "#include <algorithm>"
        ]

        if includes:
            include_lines = '\n'.join(includes)
        else:
            include_lines = '\n'.join(default_includes)

        template = f"""#ifndef {guard}
#define {guard}

{include_lines}

using namespace std;

// Function declaration
int {func_name}();

#endif // {guard}
"""
        return template

    @staticmethod
    def generate_cpp(func_name: str, implementation: str = None) -> str:
        """Generate implementation file content"""

        if implementation is None:
            implementation = f"""    // TODO: Implement function logic here (50-100 lines)

    // Example implementation:
    vector<int> data = {{1, 2, 3, 4, 5}};
    int sum = 0;
    for (int x : data) {{
        sum += x;
    }}

    volatile int result = sum;
    cout << "{func_name}: result = " << result << endl;

    return 0;"""

        template = f"""#include "{func_name}.hpp"

int {func_name}() {{
{implementation}
}}
"""
        return template


class FuncRunnerGenerator:
    """Generate FuncRunner controller class"""

    @staticmethod
    def generate_hpp() -> str:
        """Generate FuncRunner.hpp"""
        return """#ifndef FUNCRUNNER_HPP
#define FUNCRUNNER_HPP

class FuncRunner {
public:
    static void initFuncRunner();
};

#endif // FUNCRUNNER_HPP
"""

    @staticmethod
    def generate_cpp(func_names: List[str]) -> str:
        """Generate FuncRunner.cpp with all function includes and calls"""

        includes = '\n'.join([f'#include "{name}.hpp"' for name in func_names])
        calls = '\n    '.join([f'{name}();' for name in func_names])

        template = f"""#include <iostream>
#include "FuncRunner.hpp"
{includes}

void FuncRunner::initFuncRunner() {{
    std::cout << "=== FuncRunner: Starting function execution ===" << std::endl;

    {calls}

    std::cout << "=== FuncRunner: All functions executed ===" << std::endl;
}}
"""
        return template


class BuildSystemGenerator:
    """Generate build system configuration files"""

    @staticmethod
    def generate_cmake(func_names: List[str], project_name: str = "FunctionLibrary") -> str:
        """Generate CMakeLists.txt"""

        sources = []
        for name in func_names:
            sources.append(f"    src/{name}.cpp")

        sources_str = '\n'.join(sources)

        cmake = f"""cmake_minimum_required(VERSION 3.10)
project({project_name} CXX)

# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Include directories
include_directories(${{CMAKE_SOURCE_DIR}}/include)

# Source files
set(SOURCES
    src/FuncRunner.cpp
{sources_str}
)

# Create static library
add_library({project_name} STATIC ${{SOURCES}})

# Optional: Create test executable
add_executable({project_name}_test main.cpp)
target_link_libraries({project_name}_test {project_name})

# Installation
install(TARGETS {project_name} DESTINATION lib)
install(DIRECTORY include/ DESTINATION include)
"""
        return cmake

    @staticmethod
    def generate_makefile(func_names: List[str]) -> str:
        """Generate Makefile"""

        objects = ' '.join([f'obj/{name}.o' for name in func_names])

        makefile = f"""# Makefile for Function Library

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Iinclude
AR = ar
ARFLAGS = rcs

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
LIB_DIR = lib

# Target library
TARGET = $(LIB_DIR)/libfunctions.a

# Object files
OBJS = $(OBJ_DIR)/FuncRunner.o {objects}

# Default target
all: directories $(TARGET) test

# Create directories
directories:
\t@mkdir -p $(OBJ_DIR) $(LIB_DIR)

# Build static library
$(TARGET): $(OBJS)
\t$(AR) $(ARFLAGS) $@ $^
\t@echo "Static library created: $(TARGET)"

# Compile source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.hpp
\t$(CXX) $(CXXFLAGS) -c $< -o $@

# Build test executable
test: $(TARGET) main.cpp
\t$(CXX) $(CXXFLAGS) main.cpp -o test_runner -L$(LIB_DIR) -lfunctions
\t@echo "Test executable created: test_runner"

# Clean build artifacts
clean:
\t rm -rf $(OBJ_DIR) $(LIB_DIR) test_runner

.PHONY: all directories test clean
"""
        return makefile

    @staticmethod
    def generate_main_cpp() -> str:
        """Generate main.cpp for testing"""
        return """#include <iostream>
#include "FuncRunner.hpp"

int main() {
    std::cout << "Starting Function Library Test" << std::endl;
    std::cout << "===============================" << std::endl;

    FuncRunner::initFuncRunner();

    std::cout << "===============================" << std::endl;
    std::cout << "Test completed successfully!" << std::endl;

    return 0;
}
"""


class ProjectStructureGenerator:
    """Main project structure generator"""

    def __init__(self, base_path: str, num_functions: int = 10):
        self.base_path = Path(base_path)
        self.num_functions = num_functions
        self.name_generator = FunctionNameGenerator()
        self.file_generator = FileTemplateGenerator()
        self.runner_generator = FuncRunnerGenerator()
        self.build_generator = BuildSystemGenerator()

    def create_directories(self):
        """Create project directory structure"""
        dirs = ['src', 'include', 'obj', 'lib']
        for dir_name in dirs:
            (self.base_path / dir_name).mkdir(parents=True, exist_ok=True)
        print(f"✓ Created directory structure in {self.base_path}")

    def generate_functions(self) -> List[str]:
        """Generate function files"""
        func_names = self.name_generator.generate_batch(self.num_functions)

        for func_name in func_names:
            # Generate .hpp file
            hpp_content = self.file_generator.generate_hpp(func_name)
            hpp_path = self.base_path / 'include' / f'{func_name}.hpp'
            hpp_path.write_text(hpp_content)

            # Generate .cpp file
            cpp_content = self.file_generator.generate_cpp(func_name)
            cpp_path = self.base_path / 'src' / f'{func_name}.cpp'
            cpp_path.write_text(cpp_content)

        print(f"✓ Generated {len(func_names)} function pairs (.hpp/.cpp)")
        return func_names

    def generate_func_runner(self, func_names: List[str]):
        """Generate FuncRunner controller"""
        # FuncRunner.hpp
        hpp_content = self.runner_generator.generate_hpp()
        hpp_path = self.base_path / 'include' / 'FuncRunner.hpp'
        hpp_path.write_text(hpp_content)

        # FuncRunner.cpp
        cpp_content = self.runner_generator.generate_cpp(func_names)
        cpp_path = self.base_path / 'src' / 'FuncRunner.cpp'
        cpp_path.write_text(cpp_content)

        print("✓ Generated FuncRunner controller")

    def generate_build_files(self, func_names: List[str], build_system: str = 'cmake'):
        """Generate build system files"""
        if build_system == 'cmake':
            cmake_content = self.build_generator.generate_cmake(func_names)
            cmake_path = self.base_path / 'CMakeLists.txt'
            cmake_path.write_text(cmake_content)
            print("✓ Generated CMakeLists.txt")

        elif build_system == 'make':
            makefile_content = self.build_generator.generate_makefile(func_names)
            makefile_path = self.base_path / 'Makefile'
            makefile_path.write_text(makefile_content)
            print("✓ Generated Makefile")

        # Generate main.cpp
        main_content = self.build_generator.generate_main_cpp()
        main_path = self.base_path / 'main.cpp'
        main_path.write_text(main_content)
        print("✓ Generated main.cpp")

    def generate_readme(self, func_names: List[str]):
        """Generate README.md"""
        readme = f"""# C++ Function Library

Auto-generated project containing {len(func_names)} standalone C++ functions.

## Project Structure

```
.
├── include/          # Header files (.hpp)
├── src/              # Implementation files (.cpp)
├── obj/              # Object files (generated during build)
├── lib/              # Static library (generated during build)
├── CMakeLists.txt    # CMake configuration
├── Makefile          # Alternative build system
└── main.cpp          # Test driver
```

## Building

### Using CMake:
```bash
mkdir build && cd build
cmake ..
make
./FunctionLibrary_test
```

### Using Make:
```bash
make
./test_runner
```

## Functions

This library contains {len(func_names)} functions:

"""
        for i, name in enumerate(func_names, 1):
            readme += f"{i}. `{name}()`\n"

        readme += """
## Requirements

- C++17 compiler (GCC 7+, Clang 5+, MSVC 2017+)
- CMake 3.10+ (if using CMake)
- Make (if using Makefile)

## Usage

```cpp
#include "FuncRunner.hpp"

int main() {
    // Execute all functions
    FuncRunner::initFuncRunner();
    return 0;
}
```

## Notes

- All functions are standalone and self-contained
- Uses only C++17 standard library
- No external dependencies
- Functions have side effects (cout) to prevent optimization
"""

        readme_path = self.base_path / 'README.md'
        readme_path.write_text(readme)
        print("✓ Generated README.md")

    def generate_function_list(self, func_names: List[str]):
        """Generate function list file for reference"""
        list_content = "# Generated Function Names\n\n"
        for i, name in enumerate(func_names, 1):
            list_content += f"{i:4d}. {name}\n"

        list_path = self.base_path / 'function_list.txt'
        list_path.write_text(list_content)
        print(f"✓ Generated function_list.txt")

    def generate_all(self, build_system: str = 'cmake'):
        """Generate complete project structure"""
        print(f"\n🚀 Generating C++ Function Library Project")
        print(f"📁 Base path: {self.base_path}")
        print(f"🔢 Number of functions: {self.num_functions}")
        print(f"🔨 Build system: {build_system}\n")

        self.create_directories()
        func_names = self.generate_functions()
        self.generate_func_runner(func_names)
        self.generate_build_files(func_names, build_system)
        self.generate_readme(func_names)
        self.generate_function_list(func_names)

        print(f"\n✅ Project generation complete!")
        print(f"\n📝 Next steps:")
        print(f"   1. cd {self.base_path}")
        print(f"   2. Implement function logic in src/*.cpp files")
        if build_system == 'cmake':
            print(f"   3. mkdir build && cd build && cmake .. && make")
        else:
            print(f"   3. make")
        print(f"   4. Run test executable\n")


def main():
    parser = argparse.ArgumentParser(
        description='Generate C++ function library project structure'
    )
    parser.add_argument(
        '--output', '-o',
        default='./function_library',
        help='Output directory path (default: ./function_library)'
    )
    parser.add_argument(
        '--count', '-n',
        type=int,
        default=10,
        help='Number of functions to generate (default: 10)'
    )
    parser.add_argument(
        '--build-system', '-b',
        choices=['cmake', 'make'],
        default='cmake',
        help='Build system to use (default: cmake)'
    )

    args = parser.parse_args()

    generator = ProjectStructureGenerator(args.output, args.count)
    generator.generate_all(args.build_system)


if __name__ == '__main__':
    main()
