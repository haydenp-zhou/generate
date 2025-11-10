#include "example_function.hpp"

int fun_example_quicksort() {
    // Initialize random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10000);

    // Generate test data - 80 random integers
    const int ARRAY_SIZE = 80;
    vector<int> arr(ARRAY_SIZE);

    cout << "\n=== fun_example_quicksort: Starting ===" << endl;
    cout << "Generating " << ARRAY_SIZE << " random integers..." << endl;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = dis(gen);
    }

    // Print first 10 elements before sorting
    cout << "Original array (first 10): ";
    for (int i = 0; i < 10 && i < ARRAY_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // QuickSort implementation using lambda for recursion
    auto startTime = chrono::high_resolution_clock::now();

    function<void(vector<int>&, int, int)> quickSort;
    quickSort = [&](vector<int>& a, int low, int high) {
        if (low < high) {
            // Partition step
            int pivot = a[high];
            int i = low - 1;

            for (int j = low; j < high; j++) {
                if (a[j] < pivot) {
                    i++;
                    swap(a[i], a[j]);
                }
            }
            swap(a[i + 1], a[high]);
            int partitionIndex = i + 1;

            // Recursively sort left and right partitions
            quickSort(a, low, partitionIndex - 1);
            quickSort(a, partitionIndex + 1, high);
        }
    };

    // Perform the sort
    quickSort(arr, 0, ARRAY_SIZE - 1);

    auto endTime = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(endTime - startTime);

    // Print first 10 elements after sorting
    cout << "Sorted array (first 10):   ";
    for (int i = 0; i < 10 && i < ARRAY_SIZE; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Verify the array is actually sorted
    bool isSorted = true;
    for (int i = 1; i < ARRAY_SIZE; i++) {
        if (arr[i] < arr[i-1]) {
            isSorted = false;
            break;
        }
    }

    // Additional verification: use STL is_sorted
    bool stlVerified = is_sorted(arr.begin(), arr.end());

    // Calculate some statistics
    long long sum = 0;
    int minVal = arr[0];
    int maxVal = arr[0];

    for (int val : arr) {
        sum += val;
        minVal = min(minVal, val);
        maxVal = max(maxVal, val);
    }

    double average = static_cast<double>(sum) / ARRAY_SIZE;

    // Print statistics
    cout << "Statistics:" << endl;
    cout << "  - Array size: " << ARRAY_SIZE << endl;
    cout << "  - Min value: " << minVal << endl;
    cout << "  - Max value: " << maxVal << endl;
    cout << "  - Average: " << fixed << average << endl;
    cout << "  - Sorting time: " << duration.count() << " microseconds" << endl;

    // Mark results as volatile to prevent optimization
    volatile bool sortSuccess = isSorted && stlVerified;
    volatile int elementCount = ARRAY_SIZE;
    volatile double avgValue = average;

    // Final output with volatile values (prevents compiler optimization)
    cout << "Verification: ";
    if (const_cast<const bool&>(sortSuccess)) {
        cout << "✓ PASSED" << endl;
    } else {
        cout << "✗ FAILED" << endl;
    }

    cout << "fun_example_quicksort: Processed " << const_cast<const int&>(elementCount)
         << " elements with average " << const_cast<const double&>(avgValue) << endl;
    cout << "=== fun_example_quicksort: Complete ===" << endl << endl;

    return 0;
}
