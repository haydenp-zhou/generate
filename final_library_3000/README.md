# LeetCode C++ Functions Library

Extracted and converted LeetCode solutions into standalone C++ functions.

## Statistics

- **Total Functions**: 3000
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
├── include/          # Header files (3000 functions + FuncRunner)
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
