#include "fun_qu1mqArgjxGVG44w.hpp"

int fun_qu1mqArgjxGVG44w() {
    // AI-Generated: Linear Search

    // Linear Search with statistics
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
    cout << "Comparisons: " << compCount << ", Range: [" << minVal << ", " << maxVal << "]" << endl;

    return 0;
}
