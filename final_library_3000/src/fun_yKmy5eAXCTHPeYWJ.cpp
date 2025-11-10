#include "fun_yKmy5eAXCTHPeYWJ.hpp"

int fun_yKmy5eAXCTHPeYWJ() {
    // AI-Generated: Insertion Sort

    // Insertion Sort implementation
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
    cout << "Sample: " << data[0] << " " << data[n/2] << " " << data[n-1] << endl;

    return 0;
}
