#!/usr/bin/env python3
"""
AI Function Generator
Automatically generates C++ functions based on templates and algorithms
"""

import random
import string
from pathlib import Path
from typing import List, Tuple


class AIFunctionGenerator:
    """Generate C++ functions using predefined algorithm templates"""

    def __init__(self, output_dir: str):
        self.output_dir = Path(output_dir)
        self.src_dir = self.output_dir / 'src'
        self.inc_dir = self.output_dir / 'include'
        self.used_names = set()

        # Create directories
        self.src_dir.mkdir(parents=True, exist_ok=True)
        self.inc_dir.mkdir(parents=True, exist_ok=True)

    def generate_function_name(self) -> str:
        """Generate unique function name"""
        while True:
            chars = string.ascii_letters + string.digits
            suffix = ''.join(random.choices(chars, k=16))
            name = f"fun_{suffix}"
            if name not in self.used_names:
                self.used_names.add(name)
                return name

    def create_header(self, func_name: str, includes: List[str]) -> str:
        """Create header file"""
        guard = f"{func_name.upper()}_HPP"
        includes_str = '\n'.join(includes)

        return f"""#ifndef {guard}
#define {guard}

{includes_str}

using namespace std;

int {func_name}();

#endif // {guard}
"""

    def generate_sorting_function(self) -> Tuple[str, str, str]:
        """Generate a sorting algorithm function"""
        func_name = self.generate_function_name()

        algorithms = [
            # Bubble Sort
            ("""    // Bubble Sort implementation
    vector<int> arr(50);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);

    for (int& x : arr) {
        x = dis(gen);
    }

    cout << "Original array (first 10): ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Bubble sort algorithm
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    cout << "Sorted array (first 10): ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    volatile bool sorted = is_sorted(arr.begin(), arr.end());
    cout << func_name << ": Bubble sort completed, sorted=" << sorted << endl;""", "Bubble Sort"),

            # Insertion Sort
            ("""    // Insertion Sort implementation
    vector<int> data(60);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 500);

    for (int& val : data) {
        val = dis(gen);
    }

    int n = data.size();

    // Insertion sort algorithm
    for (int i = 1; i < n; i++) {
        int key = data[i];
        int j = i - 1;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }

    // Verify sorting
    volatile bool isSorted = true;
    for (int i = 1; i < n; i++) {
        if (data[i] < data[i-1]) {
            isSorted = false;
            break;
        }
    }

    cout << func_name << ": Insertion sort completed, verified=" << isSorted << endl;
    cout << "Sample: " << data[0] << " " << data[n/2] << " " << data[n-1] << endl;""", "Insertion Sort"),

            # Selection Sort
            ("""    // Selection Sort implementation
    const int SIZE = 55;
    vector<int> numbers(SIZE);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 999);

    for (int i = 0; i < SIZE; i++) {
        numbers[i] = dis(gen);
    }

    // Selection sort algorithm
    for (int i = 0; i < SIZE - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (numbers[j] < numbers[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(numbers[i], numbers[minIdx]);
        }
    }

    // Calculate statistics
    int minVal = numbers[0];
    int maxVal = numbers[SIZE-1];
    long long sum = 0;
    for (int val : numbers) {
        sum += val;
    }
    double avg = static_cast<double>(sum) / SIZE;

    volatile double average = avg;
    cout << func_name << ": Selection sort done" << endl;
    cout << "Range: [" << minVal << ", " << maxVal << "], Avg: " << average << endl;""", "Selection Sort"),
        ]

        impl, algo_name = random.choice(algorithms)

        includes = [
            '#include <iostream>',
            '#include <vector>',
            '#include <algorithm>',
            '#include <random>'
        ]

        header = self.create_header(func_name, includes)

        cpp = f"""#include "{func_name}.hpp"

int {func_name}() {{
    // AI-Generated: {algo_name}

{impl}

    return 0;
}}
"""

        return func_name, header, cpp

    def generate_search_function(self) -> Tuple[str, str, str]:
        """Generate a search algorithm function"""
        func_name = self.generate_function_name()

        algorithms = [
            # Binary Search
            ("""    // Binary Search implementation
    vector<int> sortedArr(80);
    for (int i = 0; i < 80; i++) {
        sortedArr[i] = i * 2 + 1;  // Odd numbers
    }

    int target = 77;
    int left = 0;
    int right = sortedArr.size() - 1;
    int result = -1;

    // Binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (sortedArr[mid] == target) {
            result = mid;
            break;
        } else if (sortedArr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    volatile int foundIndex = result;
    cout << func_name << ": Binary search for " << target;
    if (foundIndex != -1) {
        cout << " found at index " << foundIndex << endl;
    } else {
        cout << " not found" << endl;
    }""", "Binary Search"),

            # Linear Search with Statistics
            ("""    // Linear Search with statistics
    vector<int> data(100);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 200);

    for (int& x : data) {
        x = dis(gen);
    }

    int searchTarget = 50;
    int comparisons = 0;
    int foundIndex = -1;

    // Linear search
    for (int i = 0; i < data.size(); i++) {
        comparisons++;
        if (data[i] == searchTarget) {
            foundIndex = i;
            break;
        }
    }

    // Statistics
    int minElement = *min_element(data.begin(), data.end());
    int maxElement = *max_element(data.begin(), data.end());

    volatile int compCount = comparisons;
    volatile int minVal = minElement;
    volatile int maxVal = maxElement;

    cout << func_name << ": Linear search completed" << endl;
    cout << "Comparisons: " << compCount << ", Range: [" << minVal << ", " << maxVal << "]" << endl;""", "Linear Search"),
        ]

        impl, algo_name = random.choice(algorithms)

        includes = [
            '#include <iostream>',
            '#include <vector>',
            '#include <algorithm>',
            '#include <random>'
        ]

        header = self.create_header(func_name, includes)

        cpp = f"""#include "{func_name}.hpp"

int {func_name}() {{
    // AI-Generated: {algo_name}

{impl}

    return 0;
}}
"""

        return func_name, header, cpp

    def generate_math_function(self) -> Tuple[str, str, str]:
        """Generate a mathematical function"""
        func_name = self.generate_function_name()

        algorithms = [
            # Prime Number Sieve
            ("""    // Sieve of Eratosthenes
    const int N = 100;
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // Count and collect primes
    vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    volatile int primeCount = primes.size();
    cout << func_name << ": Found " << primeCount << " primes up to " << N << endl;
    cout << "First 5 primes: ";
    for (int i = 0; i < min(5, (int)primes.size()); i++) {
        cout << primes[i] << " ";
    }
    cout << endl;""", "Sieve of Eratosthenes"),

            # Fibonacci Sequence
            ("""    // Fibonacci sequence calculation
    const int N = 30;
    vector<long long> fib(N);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i < N; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Calculate sum and ratio
    long long sum = 0;
    for (long long val : fib) {
        sum += val;
    }

    double goldenRatio = static_cast<double>(fib[N-1]) / fib[N-2];

    volatile long long fibSum = sum;
    volatile double ratio = goldenRatio;

    cout << func_name << ": Fibonacci sequence calculated" << endl;
    cout << "Sum of first " << N << " terms: " << fibSum << endl;
    cout << "Golden ratio approximation: " << ratio << endl;
    cout << "Last term: " << fib[N-1] << endl;""", "Fibonacci Sequence"),

            # GCD and LCM
            ("""    // GCD and LCM calculations
    vector<pair<int, int>> testPairs = {
        {48, 18}, {100, 35}, {17, 19}, {144, 60}, {81, 27}
    };

    auto gcd = [](int a, int b) -> int {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    };

    auto lcm = [&gcd](int a, int b) -> int {
        return (a * b) / gcd(a, b);
    };

    int totalGcd = 0;
    long long totalLcm = 0;

    for (const auto& p : testPairs) {
        int g = gcd(p.first, p.second);
        int l = lcm(p.first, p.second);
        totalGcd += g;
        totalLcm += l;
        cout << "GCD(" << p.first << ", " << p.second << ") = " << g;
        cout << ", LCM = " << l << endl;
    }

    volatile int sumGcd = totalGcd;
    volatile long long sumLcm = totalLcm;

    cout << func_name << ": Processed " << testPairs.size() << " pairs" << endl;
    cout << "Total GCD sum: " << sumGcd << ", Total LCM sum: " << sumLcm << endl;""", "GCD and LCM"),
        ]

        impl, algo_name = random.choice(algorithms)

        includes = [
            '#include <iostream>',
            '#include <vector>',
            '#include <algorithm>',
            '#include <utility>'
        ]

        header = self.create_header(func_name, includes)

        cpp = f"""#include "{func_name}.hpp"

int {func_name}() {{
    // AI-Generated: {algo_name}

{impl}

    return 0;
}}
"""

        return func_name, header, cpp

    def generate_string_function(self) -> Tuple[str, str, str]:
        """Generate a string processing function"""
        func_name = self.generate_function_name()

        algorithms = [
            # Palindrome Check
            ("""    // Palindrome checking
    vector<string> testStrings = {
        "racecar", "hello", "madam", "world", "noon",
        "python", "level", "algorithm", "radar", "programming"
    };

    auto isPalindrome = [](const string& s) -> bool {
        int left = 0;
        int right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    };

    int palindromeCount = 0;
    vector<string> palindromes;

    for (const string& s : testStrings) {
        if (isPalindrome(s)) {
            palindromeCount++;
            palindromes.push_back(s);
        }
    }

    volatile int count = palindromeCount;
    cout << func_name << ": Found " << count << " palindromes" << endl;
    cout << "Palindromes: ";
    for (const string& p : palindromes) {
        cout << p << " ";
    }
    cout << endl;""", "Palindrome Check"),

            # String Reversal
            ("""    // String reversal and manipulation
    vector<string> words = {
        "algorithm", "computer", "programming", "software",
        "development", "engineering", "technology", "innovation"
    };

    vector<string> reversed;
    int totalChars = 0;

    for (const string& word : words) {
        string rev = word;
        reverse(rev.begin(), rev.end());
        reversed.push_back(rev);
        totalChars += word.length();
    }

    // Find longest word
    string longest = *max_element(words.begin(), words.end(),
        [](const string& a, const string& b) {
            return a.length() < b.length();
        });

    volatile int charCount = totalChars;
    volatile int longestLen = longest.length();

    cout << func_name << ": Reversed " << words.size() << " words" << endl;
    cout << "Total characters: " << charCount << endl;
    cout << "Longest word: " << longest << " (length: " << longestLen << ")" << endl;""", "String Reversal"),
        ]

        impl, algo_name = random.choice(algorithms)

        includes = [
            '#include <iostream>',
            '#include <string>',
            '#include <vector>',
            '#include <algorithm>'
        ]

        header = self.create_header(func_name, includes)

        cpp = f"""#include "{func_name}.hpp"

int {func_name}() {{
    // AI-Generated: {algo_name}

{impl}

    return 0;
}}
"""

        return func_name, header, cpp

    def generate_data_structure_function(self) -> Tuple[str, str, str]:
        """Generate a data structure function"""
        func_name = self.generate_function_name()

        algorithms = [
            # Stack Operations
            ("""    // Stack implementation and operations
    vector<int> data = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    vector<int> stack;

    // Push operations
    for (int val : data) {
        stack.push_back(val);
    }

    int pushCount = stack.size();

    // Pop operations
    int popSum = 0;
    int popCount = 0;
    while (!stack.empty()) {
        int top = stack.back();
        popSum += top;
        stack.pop_back();
        popCount++;
        if (popCount >= 5) break;
    }

    volatile int pushed = pushCount;
    volatile int popped = popCount;
    volatile int sum = popSum;

    cout << func_name << ": Stack operations completed" << endl;
    cout << "Pushed: " << pushed << ", Popped: " << popped << ", Sum: " << sum << endl;""", "Stack Operations"),

            # Queue Operations
            ("""    // Queue implementation using vector
    vector<int> queue;
    vector<int> inputs = {10, 20, 30, 40, 50, 60, 70, 80};

    // Enqueue
    for (int val : inputs) {
        queue.push_back(val);
    }

    // Dequeue and process
    int processedSum = 0;
    int processedCount = 0;
    int front = 0;

    while (front < queue.size() && processedCount < 6) {
        processedSum += queue[front];
        front++;
        processedCount++;
    }

    volatile int queueSize = queue.size();
    volatile int processed = processedCount;
    volatile int total = processedSum;

    cout << func_name << ": Queue operations completed" << endl;
    cout << "Queue size: " << queueSize << ", Processed: " << processed;
    cout << ", Total: " << total << endl;""", "Queue Operations"),
        ]

        impl, algo_name = random.choice(algorithms)

        includes = [
            '#include <iostream>',
            '#include <vector>',
            '#include <algorithm>'
        ]

        header = self.create_header(func_name, includes)

        cpp = f"""#include "{func_name}.hpp"

int {func_name}() {{
    // AI-Generated: {algo_name}

{impl}

    return 0;
}}
"""

        return func_name, header, cpp

    def generate_function(self, category: str) -> Tuple[str, str, str]:
        """Generate a function based on category"""
        generators = {
            'sorting': self.generate_sorting_function,
            'search': self.generate_search_function,
            'math': self.generate_math_function,
            'string': self.generate_string_function,
            'data_structure': self.generate_data_structure_function,
        }

        return generators[category]()

    def generate_batch(self, count: int) -> List[str]:
        """Generate a batch of functions"""
        categories = ['sorting', 'search', 'math', 'string', 'data_structure']
        func_names = []

        print(f"\n🤖 Generating {count} AI functions...")

        for i in range(count):
            category = categories[i % len(categories)]
            func_name, header, cpp = self.generate_function(category)

            # Write files
            hpp_path = self.inc_dir / f"{func_name}.hpp"
            cpp_path = self.src_dir / f"{func_name}.cpp"

            hpp_path.write_text(header)
            cpp_path.write_text(cpp)

            func_names.append(func_name)

            if (i + 1) % 100 == 0:
                print(f"   ✓ Generated {i + 1}/{count} functions...")

        print(f"\n✅ Generated {count} AI functions successfully!")
        return func_names


def main():
    import argparse

    parser = argparse.ArgumentParser(description='Generate AI C++ functions')
    parser.add_argument('--output', default='./ai_generated', help='Output directory')
    parser.add_argument('--count', type=int, default=100, help='Number of functions')

    args = parser.parse_args()

    generator = AIFunctionGenerator(args.output)
    func_names = generator.generate_batch(args.count)

    print(f"\n📊 Summary:")
    print(f"   Total functions: {len(func_names)}")
    print(f"   Output directory: {args.output}")
    print(f"\n📁 Files created:")
    print(f"   Headers: {args.output}/include/")
    print(f"   Sources: {args.output}/src/")


if __name__ == '__main__':
    main()
