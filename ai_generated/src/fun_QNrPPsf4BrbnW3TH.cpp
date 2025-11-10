#include "fun_QNrPPsf4BrbnW3TH.hpp"

int fun_QNrPPsf4BrbnW3TH() {
    // AI-Generated: Selection Sort

    // Selection Sort implementation
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
    cout << "Range: [" << minVal << ", " << maxVal << "], Avg: " << average << endl;

    return 0;
}
