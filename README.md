# C++ Function Generation Project

Automated tools and guides for generating 3000+ standalone C++ functions organized into a static library.

## 📋 Overview

This project provides everything needed to:
- Generate thousands of standalone C++ functions
- Organize them into a compilable static library
- Validate function quality and requirements
- Build and test the complete library

## 🚀 Quick Start

**Get started in 10 minutes:**

```bash
# 1. Make scripts executable
chmod +x generate_project.py validate_functions.py

# 2. Generate a small test project (10 functions)
python3 generate_project.py --output ./test_project --count 10

# 3. Build and test
cd test_project
mkdir build && cd build
cmake .. && make
./FunctionLibrary_test
```

**See [QUICKSTART.md](QUICKSTART.md) for detailed first-time setup.**

## 📁 Project Structure

```
.
├── README.md                    # This file
├── QUICKSTART.md               # 10-minute getting started guide
├── WORKFLOW.md                 # Complete step-by-step workflow
├── IMPLEMENTATION_PLAN.md      # Detailed implementation stages
├── AI_PROMPTS.md              # AI prompts for function generation
├── generate_project.py        # Project structure generator
├── validate_functions.py      # Function validation tool
└── examples/                  # Example function implementations
    ├── example_function.hpp
    └── example_function.cpp
```

## 🎯 Function Requirements

Each function must meet these criteria:

### ✅ Size
- **50-100 lines** of code (some can be slightly less)

### ✅ Parameters
- **No parameters** OR **all parameters have default values**
- Example: `int fun_algo(int n = 100, string s = "default")`

### ✅ Dependencies
- **C++17 standard library only**
- No third-party libraries
- No networking modules

### ✅ Anti-Optimization
Functions must not be optimized away:
- Include `cout` statements (side effects)
- Use `volatile` keyword for results
- Return values are used by caller

### ✅ Quality
- Compiles successfully with C++17
- Links into static library
- No memory leaks
- No undefined behavior

## 🔧 Tools

### 1. Project Generator (`generate_project.py`)

Automatically creates project structure with function templates.

```bash
python3 generate_project.py --output ./my_project --count 100 --build-system cmake
```

**Options:**
- `--output, -o`: Output directory (default: `./function_library`)
- `--count, -n`: Number of functions (default: 10)
- `--build-system, -b`: Build system: `cmake` or `make` (default: `cmake`)

**Generates:**
- Header files (.hpp)
- Implementation files (.cpp)
- FuncRunner controller class
- Build system files (CMakeLists.txt or Makefile)
- main.cpp test driver
- README and documentation

### 2. Function Validator (`validate_functions.py`)

Validates functions meet all requirements.

```bash
python3 validate_functions.py ./my_project --compile --report validation.md
```

**Options:**
- `project_path`: Path to project directory
- `--compile, -c`: Attempt to compile each function
- `--strict, -s`: Strict validation (stricter line count)
- `--report, -r`: Generate markdown report

**Checks:**
- Line count (50-100 range)
- Anti-optimization measures (cout, volatile)
- No prohibited includes
- Parameters have defaults
- No common class name collisions
- Compilation success (if --compile used)

## 📚 Documentation

| File | Purpose | When to Use |
|------|---------|-------------|
| **QUICKSTART.md** | 10-minute tutorial | First time setup |
| **WORKFLOW.md** | Complete workflow guide | Full 3000-function project |
| **IMPLEMENTATION_PLAN.md** | 5-stage implementation plan | Planning and tracking |
| **AI_PROMPTS.md** | AI prompt templates | Generating functions with AI |

## 💡 Workflow Summary

### For Small Projects (10-100 functions)

1. Generate project structure
2. Use AI to generate functions
3. Validate and fix issues
4. Build and test

**Time: 4-8 hours**

### For Large Projects (1000-3000 functions)

1. **Setup** (2 hours)
   - Generate project structure
   - Prepare AI tools and prompts

2. **Generation** (60-90 hours)
   - Generate in batches of 100
   - Use multiple AI sessions in parallel
   - Mix sources: GitHub repos, algorithms, problem solutions

3. **Validation** (10-15 hours)
   - Validate each batch
   - Fix issues incrementally

4. **Integration** (5-10 hours)
   - Build complete library
   - Run full tests
   - Memory checking

5. **Documentation** (3-5 hours)
   - Generate statistics
   - Create final documentation
   - Package deliverables

**Total Time: 80-122 hours (2-3 weeks full-time)**

## 🎓 Function Generation Strategies

### Strategy 1: GitHub Repository Mining
Extract and adapt functions from open-source repositories.

**Sources:**
- Algorithm repositories (TheAlgorithms/C-Plus-Plus)
- Competitive programming libraries
- LeetCode solution collections
- Project Euler solutions

### Strategy 2: AI Generation
Use AI to generate original implementations.

**Categories:**
- Sorting algorithms
- Graph algorithms
- Dynamic programming
- String algorithms
- Mathematical functions
- Data structure implementations

### Strategy 3: Problem Solutions
Solve algorithmic problems and extract solutions.

**Sources:**
- LeetCode problems
- HackerRank challenges
- Project Euler problems
- Codeforces problems

### Strategy 4: Hybrid (Recommended)
Combine all strategies for diversity and efficiency.

**Target Distribution (3000 functions):**
- 500 from GitHub (17%)
- 1000 generated algorithms (33%)
- 800 from competitive programming (27%)
- 500 from math problems (17%)
- 200 custom implementations (7%)

## 📊 Example Output

After running the validator:

```
🔍 Validating 3000 functions...

======================================================================
VALIDATION REPORT
======================================================================

Total Functions: 3000
✓ Passed: 2947
✗ Failed: 53

Average Lines: 67.3
Min Lines: 42
Max Lines: 118

Success Rate: 98.2%
```

## 🔨 Build Systems

Both CMake and Make are supported.

### CMake (Recommended)
```bash
mkdir build && cd build
cmake ..
make -j8
```

### Make
```bash
make -j8
```

## 🧪 Testing

```bash
# Run all functions
./test_runner

# With memory checking (Linux)
valgrind --leak-check=full ./test_runner

# Time execution
time ./test_runner
```

## 📦 Deliverables

Final package includes:
- ✅ Static library (.a or .lib file)
- ✅ All header files
- ✅ Documentation (implementation.md)
- ✅ Validation report
- ✅ Function catalog
- ✅ Build instructions

## ⚠️ Common Issues

| Issue | Solution |
|-------|----------|
| Compilation errors | Check includes (standard library only) |
| Linker errors | Verify unique function names |
| Functions optimized away | Add cout and volatile |
| Memory leaks | Use smart pointers, check destructors |
| Build too slow | Use parallel make: `make -j8` |

## 🎯 Success Criteria

- [x] 3000+ functions generated
- [x] All functions compile
- [x] Static library created
- [x] Test program runs successfully
- [x] No memory leaks
- [x] >95% validation pass rate
- [x] Complete documentation

## 📝 Function Naming Convention

Functions use the pattern: `fun_[16 random chars]`

**Examples:**
- `fun_3shyIG75HD2t3dr9`
- `fun_7Hx2Kp9Qm4Vn8Wr`
- `fun_aB3dEf9GhI2jKl5M`

Characters: a-z, A-Z, 0-9 (mixed case)

## 🔗 Resources

### Internal
- [Quick Start Guide](QUICKSTART.md)
- [Complete Workflow](WORKFLOW.md)
- [Implementation Plan](IMPLEMENTATION_PLAN.md)
- [AI Prompt Templates](AI_PROMPTS.md)
- [Example Function](examples/example_function.cpp)

### External
- [TheAlgorithms/C-Plus-Plus](https://github.com/TheAlgorithms/C-Plus-Plus)
- [LeetCode](https://leetcode.com)
- [Project Euler](https://projecteuler.net)
- [C++17 Reference](https://en.cppreference.com)

## 🛠️ Requirements

- **Python**: 3.7+
- **C++ Compiler**: GCC 7+, Clang 5+, or MSVC 2017+
- **CMake**: 3.10+ (optional, for CMake build)
- **Make**: Any recent version (optional, for Make build)

## 📄 License

This project structure and tools are provided as-is for educational and development purposes.

## 🤝 Contributing

This is a project generation tool. To improve:
1. Enhance validation rules in `validate_functions.py`
2. Add more AI prompt templates to `AI_PROMPTS.md`
3. Improve project generator features
4. Add more example functions

## 📧 Support

For issues:
1. Check [WORKFLOW.md](WORKFLOW.md) troubleshooting section
2. Review validation reports for specific errors
3. Consult example function for reference

---

## Getting Started Right Now

```bash
# 1. Generate test project
python3 generate_project.py --output ./my_test --count 10

# 2. Open AI_PROMPTS.md and copy a prompt

# 3. Use AI to generate 10 functions

# 4. Replace template code with generated code

# 5. Validate
python3 validate_functions.py ./my_test

# 6. Build
cd my_test/build && cmake .. && make

# 7. Run
./FunctionLibrary_test
```

**See [QUICKSTART.md](QUICKSTART.md) for detailed instructions.**

---

**Ready to generate 3000 functions? Start with the [Quick Start Guide](QUICKSTART.md)!**
