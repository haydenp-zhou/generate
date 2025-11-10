# Quick Start Guide

Get started generating C++ functions in 10 minutes.

## Prerequisites

```bash
# Required
python3 --version  # 3.7+
g++ --version      # C++17 support

# Make scripts executable
chmod +x generate_project.py validate_functions.py
```

## Step 1: Generate Project Structure (2 minutes)

```bash
# Start small - generate project for 10 functions
python3 generate_project.py --output ./my_functions --count 10 --build-system cmake

# This creates:
# my_functions/
#   ├── include/     (10 .hpp templates + FuncRunner.hpp)
#   ├── src/         (10 .cpp templates + FuncRunner.cpp)
#   ├── CMakeLists.txt
#   └── main.cpp
```

## Step 2: Generate First Function (3 minutes)

**Open your AI assistant (ChatGPT, Claude, etc.) and use this prompt:**

```
Generate a C++ function implementing merge sort that meets these requirements:

1. 50-100 lines of code
2. No parameters (generate test data inside function)
3. C++17 standard library only
4. Include cout statements to print results
5. Mark result as volatile to prevent optimization

Provide both .hpp and .cpp files with this structure:

Header (fun_mergesort.hpp):
- Include guard
- Standard library includes
- Function declaration: int fun_mergesort();

Implementation (fun_mergesort.cpp):
- Generate test data (vector of random integers)
- Implement merge sort algorithm
- Print results with cout
- Use volatile for result
- Return 0

Format as complete, ready-to-compile code.
```

**Copy the generated code into the first function files in your project.**

## Step 3: Test Your Function (2 minutes)

```bash
cd my_functions

# Build
mkdir build && cd build
cmake ..
make

# Run
./FunctionLibrary_test

# You should see output from your merge sort function!
```

## Step 4: Validate (1 minute)

```bash
cd ..  # Back to my_functions directory
python3 ../validate_functions.py . --compile

# Check the validation report
# Fix any issues reported
```

## Step 5: Generate More Functions (2 minutes)

**Use the prompt templates in `AI_PROMPTS.md`:**

For example, to generate 10 algorithm functions:

```
Generate 10 C++ functions implementing different algorithms:
1. Quick sort
2. Binary search
3. Dijkstra's shortest path
4. Depth-first search
5. Breadth-first search
6. Knapsack problem (dynamic programming)
7. Longest common subsequence
8. String pattern matching (KMP)
9. Heap sort
10. Radix sort

Each function should:
- Be 50-100 lines
- Have no parameters (generate test data inside)
- Use only C++17 standard library
- Include cout for output
- Use volatile for results
- Be self-contained

Provide complete .hpp and .cpp files for each function.
```

---

## What You've Accomplished

✅ Created project structure
✅ Generated your first function
✅ Compiled and tested it
✅ Validated the code
✅ Know how to generate more

## Next Steps

### Scale to 100 Functions

```bash
# Generate project for 100 functions
python3 generate_project.py --output ./functions_100 --count 100

# Use AI to generate functions in batches:
# - Batch 1: Sorting algorithms (10 functions)
# - Batch 2: Graph algorithms (10 functions)
# - Batch 3: Dynamic programming (10 functions)
# - ... continue for 10 batches
```

### Scale to 3000 Functions

Follow the complete workflow in `WORKFLOW.md`:
1. Generate project structure
2. Use multiple AI prompts from `AI_PROMPTS.md`
3. Generate in batches of 100
4. Validate each batch
5. Build final static library

---

## Common Commands Reference

```bash
# Generate project
python3 generate_project.py --output ./project --count N

# Validate functions
python3 validate_functions.py ./project

# Validate with compilation
python3 validate_functions.py ./project --compile

# Generate validation report
python3 validate_functions.py ./project --report report.md

# Build with CMake
cd project && mkdir build && cd build && cmake .. && make

# Build with Make
cd project && make

# Run tests
./test_runner  # or ./FunctionLibrary_test
```

---

## Example AI Conversation

**You:** Generate a C++ function that implements quicksort following the template in this repository.

**AI:** Here's a quicksort implementation...

**You:** [Copy code to `my_functions/src/fun_1A2b3C4d5E6f7G8h.cpp` and corresponding .hpp]

**You:** [Update `FuncRunner.cpp` to include and call this function]

**You:** [Build and test]

**You:** Generate 9 more sorting variations...

---

## Tips for Fast Generation

1. **Use batch prompts**: Ask AI for 10 functions at once
2. **Reuse successful prompts**: Save prompts that work well
3. **Validate frequently**: Don't wait until you have 100 functions
4. **Automate naming**: Use the random naming scheme from start
5. **Test incrementally**: Build after each batch of 10-20 functions

---

## Troubleshooting

### Function won't compile
- Check includes (only standard library)
- Verify C++17 compatibility
- Look at error message carefully

### Validation fails
- Read the validation report
- Most common: missing cout or volatile
- Fix and re-validate

### Build is slow
- Use parallel make: `make -j8`
- Build incrementally, not all at once

---

## Resources

- **Detailed workflow**: `WORKFLOW.md`
- **AI prompts**: `AI_PROMPTS.md`
- **Implementation plan**: `IMPLEMENTATION_PLAN.md`
- **Function examples**: Check generated templates in `my_functions/`

---

## Ready to Scale?

Once you're comfortable with 10 functions:

1. **Generate 100 functions** (1-2 days)
   - Use `AI_PROMPTS.md` templates
   - Work in batches of 10
   - Validate each batch

2. **Generate 1000 functions** (1 week)
   - Mix different sources (GitHub, algorithms, problems)
   - Automate validation
   - Build incrementally

3. **Generate 3000 functions** (2-3 weeks)
   - Follow complete workflow
   - Process in parallel
   - Maintain quality throughout

---

**Start generating now!**

```bash
python3 generate_project.py --output ./my_first_library --count 10
```
