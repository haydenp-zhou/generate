# Complete Workflow Guide

## Overview
This document provides a step-by-step guide for generating 3000+ C++ functions and organizing them into a static library.

---

## Phase 1: Setup and Preparation

### Step 1.1: Verify Tools
```bash
# Check required tools
python3 --version  # Should be 3.7+
g++ --version      # Should support C++17
cmake --version    # Optional, for CMake build
make --version     # Optional, for Makefile build

# Make scripts executable
chmod +x generate_project.py
chmod +x validate_functions.py
```

### Step 1.2: Choose Your AI Tool
Recommended options:
- **ChatGPT** (GPT-4 or GPT-4 Turbo)
- **Claude** (Claude 3 Opus or Sonnet)
- **GitHub Copilot** (for code completion)
- **Local LLM** (with sufficient context window)

---

## Phase 2: Function Generation

### Strategy 1: GitHub Repository Mining

#### 2.1.1: Find Repositories
Search GitHub for:
```
- "competitive programming" + C++
- "algorithm implementations" + C++
- "leetcode solutions" + C++
- "project euler" + C++
- "data structures" + C++
```

Good sources:
- https://github.com/TheAlgorithms/C-Plus-Plus
- https://github.com/kth-competitive-programming/kactl
- LeetCode solution repositories
- Codeforces gym problem solutions

#### 2.1.2: Extract Functions
For each repository:

1. **Clone the repository**
```bash
git clone <repo-url>
cd <repo-name>
```

2. **Find candidate files**
```bash
find . -name "*.cpp" -o -name "*.hpp" | head -50
```

3. **Use AI to extract functions**
   - Copy source code
   - Use prompt from `AI_PROMPTS.md` → "Prompt Template for Function Extraction"
   - AI will convert functions to required format

4. **Batch process**
   - Process 10 functions at a time
   - Save each as `fun_tempname_N.cpp/hpp`
   - Later rename with random suffixes

### Strategy 2: Algorithm Generation from Scratch

#### 2.2.1: Use Category-based Generation
```bash
# Create a tracking file
echo "Algorithm Generation Progress" > generation_progress.txt
```

For each category (from `AI_PROMPTS.md`):
1. Sorting algorithms (10 functions)
2. Graph algorithms (20 functions)
3. Dynamic programming (20 functions)
4. String algorithms (15 functions)
5. Mathematical algorithms (20 functions)
6. Tree algorithms (15 functions)
7. Searching algorithms (10 functions)
8. Backtracking (10 functions)
9. Greedy algorithms (10 functions)
10. Data structures (20 functions)

**Process:**
```
1. Copy prompt from AI_PROMPTS.md for category
2. Generate batch of 10 functions
3. Save each function pair (.hpp/.cpp)
4. Validate with validate_functions.py
5. If issues found, regenerate problematic functions
6. Repeat until batch passes validation
```

#### 2.2.2: Example Generation Session
```
You to AI:
"Generate 10 sorting algorithm functions following the template in AI_PROMPTS.md"

AI Response:
- fun_mergesort.cpp/.hpp
- fun_quicksort.cpp/.hpp
- ... (8 more)

You:
1. Save each file
2. Run: python3 validate_functions.py ./temp_functions
3. Fix any issues
4. Move validated functions to main project
```

### Strategy 3: Problem Solution Generation

#### 2.3.1: LeetCode/HackerRank Problems
```
Workflow:
1. Find 100 medium-difficulty problems
2. For each problem:
   - Copy problem description
   - Ask AI: "Solve this problem following requirements in AI_PROMPTS.md"
   - AI generates solution as standalone function
   - Save function pair
3. Validate batch
```

#### 2.3.2: Project Euler Problems
```
Same as above but:
- Focus on mathematical problems (more self-contained)
- Usually 50-100 lines naturally
- Perfect for this project
```

### Strategy 4: Hybrid Approach (Recommended)

**Target Distribution for 3000 functions:**
- 500 from GitHub repositories (extracted and adapted)
- 1000 generated from algorithm categories
- 800 from LeetCode/competitive programming
- 500 from Project Euler and math problems
- 200 custom implementations (data structures, etc.)

---

## Phase 3: Project Organization

### Step 3.1: Generate Initial Project Structure
```bash
# Generate project with templates for 3000 functions
python3 generate_project.py --output ./function_library --count 3000 --build-system cmake

# This creates:
# function_library/
#   ├── include/        (3000 .hpp files + FuncRunner.hpp)
#   ├── src/            (3000 .cpp files + FuncRunner.cpp)
#   ├── CMakeLists.txt
#   ├── Makefile
#   └── main.cpp
```

### Step 3.2: Fill Functions with Generated Code

**Option A: Manual Replacement**
```bash
# For each generated function:
# 1. Open the template file
# 2. Replace TODO section with generated code
# 3. Save
```

**Option B: Automated Script** (create if needed)
```python
# replace_functions.py
# Takes directory of generated functions
# Replaces corresponding template functions
```

### Step 3.3: Batch Processing
```bash
# Process in batches of 100
for batch in {1..30}; do
    echo "Processing batch $batch (functions $((($batch-1)*100+1)) to $(($batch*100)))"

    # Generate 100 functions using AI
    # Save to batch_$batch/

    # Validate
    python3 validate_functions.py ./batch_$batch --strict

    # If passed, copy to main project
    if [ $? -eq 0 ]; then
        cp batch_$batch/src/*.cpp function_library/src/
        cp batch_$batch/include/*.hpp function_library/include/
    fi
done
```

---

## Phase 4: Validation and Quality Control

### Step 4.1: Validate Individual Batches
```bash
# After generating each batch of 100 functions
python3 validate_functions.py ./batch_01 --strict --report validation_batch01.md

# Review report
cat validation_batch01.md

# Fix issues
# Re-validate until batch passes
```

### Step 4.2: Compile Testing
```bash
# Test compilation of batch
cd function_library
mkdir -p build && cd build
cmake ..
make -j8  # Parallel compilation

# If errors occur:
# 1. Note which functions fail
# 2. Fix those specific functions
# 3. Re-compile
```

### Step 4.3: Full Project Validation
```bash
# Once all 3000 functions are in place
python3 validate_functions.py ./function_library --compile --report final_validation.md

# This will:
# 1. Check all 3000 functions
# 2. Attempt to compile each
# 3. Generate comprehensive report
```

---

## Phase 5: Build and Test

### Step 5.1: Build Static Library

**Using CMake:**
```bash
cd function_library
mkdir build && cd build
cmake ..
make -j8

# Output: lib/libFunctionLibrary.a
```

**Using Make:**
```bash
cd function_library
make -j8

# Output: lib/libfunctions.a
```

### Step 5.2: Test Execution
```bash
# Run test program
./test_runner

# This will call FuncRunner::initFuncRunner()
# which executes all 3000 functions

# Watch for:
# - Crashes
# - Infinite loops (timeout after 10 minutes)
# - Memory issues
```

### Step 5.3: Memory Check (Optional but Recommended)
```bash
# Install valgrind if needed
# macOS: brew install valgrind
# Linux: apt-get install valgrind

# Run with memory checker
valgrind --leak-check=full --show-leak-kinds=all ./test_runner

# Should show "no leaks are possible"
```

### Step 5.4: Performance Test
```bash
# Time the execution
time ./test_runner

# Should complete in reasonable time (< 30 minutes for 3000 functions)
# If too slow, some functions might have infinite loops or inefficiencies
```

---

## Phase 6: Documentation and Delivery

### Step 6.1: Generate Statistics
```bash
# Count total lines
find function_library/src -name "fun_*.cpp" -exec wc -l {} + | tail -1

# Count functions
ls function_library/src/fun_*.cpp | wc -l

# Generate function catalog
ls function_library/src/fun_*.cpp | sed 's/.*\///;s/.cpp//' > function_catalog.txt
```

### Step 6.2: Create Implementation Documentation
```bash
# Create implementation.md
cat > implementation.md << 'EOF'
# C++ Function Library - Implementation Documentation

## Overview
Static library containing 3000+ standalone C++ functions.

## Statistics
- **Total Functions:** [COUNT]
- **Total Lines of Code:** [LOC]
- **Average Function Size:** [AVG] lines
- **Build System:** CMake + Makefile
- **C++ Standard:** C++17
- **Dependencies:** Standard library only

## Library Usage

### Linking
\`\`\`bash
g++ -std=c++17 your_program.cpp -L./lib -lfunctions -o your_program
\`\`\`

### Code Example
\`\`\`cpp
#include "FuncRunner.hpp"

int main() {
    // Execute all functions
    FuncRunner::initFuncRunner();
    return 0;
}
\`\`\`

## Function Categories
[List categories and counts]

## Build Instructions
[Include from README]

## Quality Assurance
- All functions compile successfully
- No memory leaks detected
- Full test execution completed
- Validation report: [Link to validation report]

EOF
```

### Step 6.3: Package Deliverables
```bash
# Create deliverables directory
mkdir -p deliverables

# Copy library
cp function_library/lib/*.a deliverables/

# Copy headers
cp -r function_library/include deliverables/

# Copy documentation
cp implementation.md deliverables/
cp final_validation.md deliverables/
cp function_catalog.txt deliverables/

# Create archive
tar -czf function_library_3000.tar.gz deliverables/

# ZIP for Windows users
zip -r function_library_3000.zip deliverables/
```

---

## Phase 7: Maintenance and Expansion

### Adding More Functions
```bash
# Generate additional 100 functions
python3 generate_project.py --output ./expansion_batch --count 100

# Generate code for new functions
# ... use AI prompts ...

# Validate
python3 validate_functions.py ./expansion_batch

# Merge into main project
cp expansion_batch/src/*.cpp function_library/src/
cp expansion_batch/include/*.hpp function_library/include/

# Regenerate FuncRunner
# ... update FuncRunner.cpp with new includes and calls ...

# Rebuild
cd function_library/build
cmake ..
make
```

### Quality Improvements
```bash
# Re-validate periodically
python3 validate_functions.py ./function_library --compile --strict

# Profile performance
perf record ./test_runner
perf report

# Optimize slow functions if needed
```

---

## Troubleshooting

### Common Issues

#### 1. Compilation Errors
```
Problem: Function won't compile
Solution:
- Check includes (only standard library allowed)
- Verify syntax with C++17 standard
- Check for name collisions
- Look for undefined references
```

#### 2. Linker Errors
```
Problem: Multiple definition errors
Solution:
- Ensure function names are unique
- Check for duplicate files
- Verify include guards in .hpp files
```

#### 3. Functions Get Optimized Away
```
Problem: Function seems to be skipped
Solution:
- Add more cout statements
- Use volatile keyword on results
- Ensure return value is used by caller
```

#### 4. Memory Leaks
```
Problem: Valgrind reports leaks
Solution:
- Check for missing delete/free
- Use smart pointers (unique_ptr, shared_ptr)
- Ensure destructors clean up resources
```

#### 5. Build Too Slow
```
Problem: Compilation takes too long
Solution:
- Use parallel make: make -j8
- Use ccache for caching
- Split into multiple static libraries
- Use precompiled headers
```

---

## Advanced Topics

### Splitting Into Multiple Libraries
If 3000 functions in one library is unwieldy:

```bash
# Split into 10 libraries of 300 functions each
for i in {1..10}; do
    mkdir -p lib_$i/{src,include}
    # Move 300 functions to each library
    # Generate separate CMakeLists.txt
done
```

### Continuous Integration
```yaml
# .github/workflows/build.yml
name: Build and Test
on: [push]
jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v2
      - name: Install dependencies
        run: sudo apt-get install g++ cmake
      - name: Build
        run: |
          mkdir build && cd build
          cmake ..
          make -j4
      - name: Test
        run: ./test_runner
```

---

## Timeline Estimate

For generating 3000 functions:

| Phase | Estimated Time | Notes |
|-------|---------------|-------|
| Setup | 1-2 hours | One-time setup |
| Generate first 100 | 4-6 hours | Learning curve |
| Generate 100-1000 | 20-30 hours | Getting faster |
| Generate 1000-3000 | 40-60 hours | Bulk generation |
| Validation | 10-15 hours | Per batch validation |
| Integration & Build | 5-10 hours | Debugging issues |
| Documentation | 3-5 hours | Final docs |
| **Total** | **83-128 hours** | ~2-3 weeks full-time |

**Optimization Tips:**
- Use multiple AI sessions in parallel
- Batch process aggressively (100+ functions at once)
- Automate validation and fixing
- Use templates for common patterns
- Cache validated functions

---

## Success Criteria Checklist

- [ ] 3000+ functions generated
- [ ] All functions compile individually
- [ ] All functions compile together
- [ ] Static library successfully created
- [ ] Test program executes all functions
- [ ] No memory leaks detected
- [ ] No undefined behavior
- [ ] All functions 50-100 lines (with some exceptions)
- [ ] All functions have cout output
- [ ] No third-party dependencies
- [ ] No networking code
- [ ] Parameters have defaults (or no params)
- [ ] Validation report shows >95% pass rate
- [ ] Documentation complete
- [ ] Deliverables packaged

---

## Resources

### AI Prompts
- See `AI_PROMPTS.md` for detailed prompts
- Customize prompts based on your needs
- Keep successful prompts for reuse

### Code Sources
- GitHub: TheAlgorithms/C-Plus-Plus
- LeetCode Solutions
- Project Euler
- Codeforces Gym
- HackerRank Archives

### Tools
- Python scripts: `generate_project.py`, `validate_functions.py`
- Implementation plan: `IMPLEMENTATION_PLAN.md`
- This workflow guide

---

## Contact and Support

For issues or questions:
1. Check troubleshooting section above
2. Review validation reports for specific errors
3. Consult C++17 standard documentation
4. Check compiler error messages carefully

---

**Good luck with your function generation project!**
