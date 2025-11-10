# AI Prompts for C++ Function Generation

## Table of Contents
1. [Prompt Template for Function Extraction](#prompt-template-for-function-extraction)
2. [Prompt for Algorithm Function Generation](#prompt-for-algorithm-function-generation)
3. [Prompt for Math Library Functions](#prompt-for-math-library-functions)
4. [Prompt for Data Structure Functions](#prompt-for-data-structure-functions)
5. [Validation Prompt](#validation-prompt)

---

## Prompt Template for Function Extraction

### From GitHub Repository
```
I need you to extract standalone C++ functions from a codebase and convert them into independent functions following strict requirements.

**Source Code:**
[Paste the source code here]

**Requirements:**

1. **Function Size**: 50-100 lines of code (some functions can be slightly less, but aim for this range)

2. **Parameters**:
   - Prefer no parameters
   - If parameters needed, provide default values
   - Example: `int myFunc(int n = 10, string s = "default")`

3. **Dependencies**:
   - Use ONLY C++17 standard library
   - No third-party libraries
   - No networking modules
   - No file I/O unless absolutely necessary

4. **Variables**:
   - Prefer local variables
   - Can use class member variables if creating a helper class
   - Avoid global and static variables
   - If creating custom classes, avoid common names like "Node", "TreeNode", "ListNode"
   - Use unique names like "GraphVertex", "BSTElement", etc.

5. **Prevent Optimization** (CRITICAL):
   - Add `cout` statements to print intermediate or final results
   - Mark return values as `volatile` if they might be optimized away
   - Ensure the function has side effects (output to console)
   - Example:
     ```cpp
     volatile int result = computation();
     cout << "Function result: " << result << endl;
     ```

6. **Execution Requirements**:
   - Function must be executable
   - Must compile with C++17
   - Must link successfully
   - No memory leaks
   - No undefined behavior

**Output Format:**

For each extracted function, provide:

1. **Header file** (.hpp):
```cpp
#ifndef FUN_XXXXXXXXXXXXXXXX_HPP
#define FUN_XXXXXXXXXXXXXXXX_HPP

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// ... other standard library includes

using namespace std;

// Helper classes if needed
class HelperClassName {
    // ...
};

// Function declaration
int fun_XXXXXXXXXXXXXXXX();

#endif // FUN_XXXXXXXXXXXXXXXX_HPP
```

2. **Implementation file** (.cpp):
```cpp
#include "fun_XXXXXXXXXXXXXXXX.hpp"

int fun_XXXXXXXXXXXXXXXX() {
    // Implementation here (50-100 lines)

    volatile auto result = someComputation();
    cout << "fun_XXXXXXXXXXXXXXXX: result = " << result << endl;
    return 0;
}
```

**Please extract up to 10 functions from the provided source code.**
```

---

## Prompt for Algorithm Function Generation

### Generate New Algorithm Functions
```
Generate C++ functions implementing various algorithms. Each function must meet strict requirements for a static library project.

**Generate 10 functions covering different categories:**
1. Sorting algorithms (merge sort, quick sort variations)
2. Searching algorithms (binary search variations, pattern matching)
3. Graph algorithms (DFS, BFS, shortest path)
4. Dynamic programming (knapsack, longest subsequence variations)
5. String algorithms (palindrome, anagram, substring search)
6. Mathematical algorithms (prime numbers, GCD, combinatorics)
7. Array manipulation (rotation, partitioning, rearrangement)
8. Tree algorithms (traversals, construction, validation)
9. Backtracking algorithms (permutations, combinations, n-queens)
10. Greedy algorithms (interval scheduling, huffman coding)

**STRICT Requirements:**

1. **Size**: 50-100 lines per function (body only, excluding helper classes)

2. **No Parameters OR Default Parameters**:
   ```cpp
   // Good examples:
   int fun_algo1();  // No parameters
   int fun_algo2(int n = 100);  // Default value
   int fun_algo3(vector<int> arr = {1,2,3,4,5});  // Default container
   ```

3. **Self-Contained**:
   - Generate test data inside the function
   - Use C++17 standard library only
   - Include: <iostream>, <vector>, <string>, <algorithm>, <queue>, <stack>, <map>, <set>, <unordered_map>, <unordered_set>, <numeric>, <cmath>, <random>
   - NO external libraries, NO networking, NO file I/O

4. **Custom Classes**:
   - If needed, define inside the same file
   - Use unique names: avoid "Node", "TreeNode", "ListNode"
   - Good names: "GraphVertex", "QueueElement", "BSTNodeElement", "LinkedElement"

5. **Anti-Optimization (CRITICAL)**:
   ```cpp
   int fun_example() {
       // Generate test data
       vector<int> data = {5, 2, 8, 1, 9};

       // Algorithm implementation (50-100 lines)
       // ... algorithm code ...

       // Prevent optimization with volatile + cout
       volatile int result = computedValue;
       cout << "fun_example: result = " << result << endl;

       // Or print intermediate steps:
       cout << "fun_example: processed " << data.size() << " elements" << endl;

       return 0;
   }
   ```

6. **Memory Safety**:
   - No memory leaks
   - Proper resource management
   - Use RAII principles
   - Prefer smart pointers if dynamic allocation needed

**Output Format:**

For each function provide BOTH files:

**fun_[NAME].hpp:**
```cpp
#ifndef FUN_[NAME]_HPP
#define FUN_[NAME]_HPP

#include <iostream>
#include <vector>
// ... other includes

using namespace std;

// Helper classes if needed (with unique names)

int fun_[NAME]();

#endif
```

**fun_[NAME].cpp:**
```cpp
#include "fun_[NAME].hpp"

int fun_[NAME]() {
    // Implementation (50-100 lines)

    volatile auto result = computation();
    cout << "fun_[NAME]: " << result << endl;
    return 0;
}
```

**Generate 10 complete functions now.**
```

---

## Prompt for Math Library Functions

### Generate Mathematical Functions
```
Generate C++ functions implementing mathematical algorithms and computations. Focus on numerical methods, computational geometry, statistics, and linear algebra.

**Generate 10 mathematical functions:**

1. **Numerical Methods**: Newton-Raphson, numerical integration, root finding
2. **Linear Algebra**: Matrix operations, determinant, eigenvalue approximation
3. **Statistics**: Mean, variance, standard deviation, regression
4. **Computational Geometry**: Convex hull, point-line distance, polygon area
5. **Number Theory**: Prime factorization, modular arithmetic, Chinese remainder
6. **Combinatorics**: Permutation counting, binomial coefficients, partition
7. **Optimization**: Gradient descent, simplex method (simple version)
8. **Signal Processing**: FFT, convolution, filtering
9. **Probability**: Monte Carlo simulation, random walks, distributions
10. **Cryptographic Math**: RSA components, modular exponentiation

**Requirements:**

1. **Size**: 50-100 lines per function

2. **Self-Contained with Test Data**:
   ```cpp
   int fun_math_example() {
       // Generate test data inside function
       vector<double> data = {1.5, 2.7, 3.2, 4.8, 5.1};
       int n = 100;

       // Mathematical computation (50-100 lines)
       double result = 0.0;
       // ... implementation ...

       volatile double volatileResult = result;
       cout << "fun_math_example: computed value = " << volatileResult << endl;
       return 0;
   }
   ```

3. **Standard Library Only**:
   - <cmath>, <random>, <numeric>, <algorithm>
   - <vector>, <array>, <complex>
   - NO external math libraries (no Eigen, no BLAS)

4. **No Parameters or Default Parameters**:
   ```cpp
   int fun_integrate(double a = 0.0, double b = 1.0, int steps = 1000);
   ```

5. **Precision and Output**:
   - Use `double` or `long double` for precision
   - Print results with reasonable precision
   - Include validation/verification output

6. **Anti-Optimization**:
   ```cpp
   volatile double finalResult = computation();
   cout << "Result: " << fixed << setprecision(6) << finalResult << endl;
   ```

**Output Format:** Provide complete .hpp and .cpp files for each function.

**Generate 10 mathematical functions now.**
```

---

## Prompt for Data Structure Functions

### Generate Data Structure Implementations
```
Generate C++ functions that implement or manipulate various data structures. Each function should demonstrate a complete operation on a data structure.

**Generate 10 data structure functions:**

1. **Trees**: AVL tree operations, Red-Black tree operations, B-tree operations
2. **Heaps**: Min-heap operations, max-heap operations, k-way heap
3. **Graphs**: Adjacency list operations, graph traversals, cycle detection
4. **Hashing**: Hash table with chaining, open addressing, bloom filter
5. **Advanced Lists**: Skip list, self-organizing list, unrolled linked list
6. **Tries**: Standard trie, compressed trie, suffix tree
7. **Segment Trees**: Range query, range update operations
8. **Union-Find**: Disjoint set with path compression
9. **Priority Queues**: Custom priority queue implementations
10. **Caches**: LRU cache, LFU cache implementations

**Requirements:**

1. **Complete Implementation in One Function**:
   ```cpp
   int fun_data_structure() {
       // Define custom class inside if needed
       class MyCustomTree {
           struct TreeNode {  // OK to use TreeNode as inner class
               int val;
               TreeNode* left;
               TreeNode* right;
               TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
           };

           TreeNode* root;
       public:
           MyCustomTree() : root(nullptr) {}
           // ... operations ...
       };

       // Create instance and perform operations (50-100 lines)
       MyCustomTree tree;
       // ... test the data structure ...

       cout << "fun_data_structure: operations completed" << endl;
       return 0;
   }
   ```

2. **Memory Management**:
   - Proper cleanup in destructors
   - No memory leaks
   - Use smart pointers when appropriate

3. **Test Cases Inside**:
   - Generate test data in the function
   - Perform operations (insert, delete, search, etc.)
   - Validate correctness with assertions or output

4. **Avoid Common Names**:
   - DON'T use: Node, TreeNode, ListNode, GraphNode (as outer class)
   - DO use: BSTElement, AVLVertex, GraphElement, ListElement

5. **Anti-Optimization**:
   ```cpp
   volatile int operationCount = performOperations();
   cout << "Performed " << operationCount << " operations" << endl;
   ```

**Output Format:** Complete .hpp and .cpp files for each function.

**Generate 10 data structure functions now.**
```

---

## Validation Prompt

### Validate Generated Functions
```
Review the following C++ function and validate it meets ALL requirements. Fix any issues.

**Function to Validate:**
[Paste function code here]

**Validation Checklist:**

1. ✅ Size: 50-100 lines (approximately)
2. ✅ No parameters OR all parameters have default values
3. ✅ Uses ONLY C++17 standard library (no third-party libs)
4. ✅ No global or static variables (unless absolutely necessary)
5. ✅ Custom classes avoid common names (Node, TreeNode, etc.)
6. ✅ Has `cout` output (side effects)
7. ✅ Return values marked `volatile` if needed
8. ✅ Will compile with C++17
9. ✅ No memory leaks
10. ✅ No undefined behavior

**If any requirement is NOT met, fix the function and provide the corrected version.**

**Also provide:**
- Brief description of what the function does
- Any edge cases handled
- Computational complexity (if applicable)
```

---

## Batch Generation Strategy

### Generate Functions in Batches
```
I need you to generate 100 C++ functions for a static library project. Generate them in batches of 10.

**Current Batch: [1-10] / [11-20] / [21-30] / etc.**

**Category for this batch:** [Algorithm/Math/Data Structure/String Processing/etc.]

Use the appropriate prompt template above based on the category.

**After generating each batch:**
1. Number the functions sequentially (batch1_func1, batch1_func2, etc.)
2. Ensure no duplicate logic across functions
3. Vary the complexity and approach
4. Mix different problem types

**Provide all functions in the specified format with complete .hpp and .cpp files.**
```

---

## Function Naming Convention

When generating functions, use this naming pattern:
- **Temporary name**: `fun_description` (e.g., `fun_quicksort`, `fun_dijkstra`)
- **Final name**: `fun_3shyIG75HD2t3dr9` (16 random characters)
  - Characters: a-z, A-Z, 0-9
  - Example: `fun_7Hx2Kp9Qm4Vn8Wr`

A separate script will rename all functions to the final format.

---

## Example Complete Output

```cpp
// fun_quicksort_example.hpp
#ifndef FUN_QUICKSORT_EXAMPLE_HPP
#define FUN_QUICKSORT_EXAMPLE_HPP

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

int fun_quicksort_example();

#endif

// fun_quicksort_example.cpp
#include "fun_quicksort_example.hpp"

int fun_quicksort_example() {
    // Generate random test data
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);

    vector<int> arr(50);
    for (int& x : arr) {
        x = dis(gen);
    }

    cout << "Original array (first 10): ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // QuickSort implementation
    function<void(vector<int>&, int, int)> quickSort;
    quickSort = [&](vector<int>& a, int low, int high) {
        if (low < high) {
            int pivot = a[high];
            int i = low - 1;

            for (int j = low; j < high; j++) {
                if (a[j] < pivot) {
                    i++;
                    swap(a[i], a[j]);
                }
            }
            swap(a[i + 1], a[high]);
            int pi = i + 1;

            quickSort(a, low, pi - 1);
            quickSort(a, pi + 1, high);
        }
    };

    quickSort(arr, 0, arr.size() - 1);

    // Verify sorted
    bool isSorted = is_sorted(arr.begin(), arr.end());
    volatile int sortedFlag = isSorted ? 1 : 0;

    cout << "Sorted array (first 10): ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "fun_quicksort_example: Sort successful = " << sortedFlag << endl;

    return 0;
}
```

---

## Tips for AI Generation

1. **Vary the algorithms**: Don't generate 100 sorting functions; mix different categories
2. **Test data diversity**: Use different data types (int, double, string, custom objects)
3. **Complexity range**: Mix simple (50 lines) and complex (100 lines) functions
4. **Real-world scenarios**: Implement practical algorithms, not just textbook examples
5. **Edge cases**: Handle empty inputs, single elements, large datasets
6. **Output verbosity**: More `cout` statements = harder to optimize away

---

## Automated Validation Script Requirements

Create a script that validates each generated function:
```bash
# For each function:
# 1. Check line count (50-100 range)
# 2. Check for cout statements (anti-optimization)
# 3. Verify no third-party includes
# 4. Compile individually
# 5. Check for memory leaks with valgrind/sanitizers
# 6. Verify function signature (no params or default params)
```
