#include "fun_zViY9i7YagsCPdfV.hpp"

int fun_zViY9i7YagsCPdfV() {
    // LeetCode Problem: Count The Number Of Houses At A Certain Distance Ii

    // Solution class
    class Solution {

    public:
        vector<long long> countOfPairs(int n, int x, int y) {
            --x, --y;
            if (x > y) {
                swap(x, y);
            }
            vector<long long> diff(n);
            for (int i = 0; i < n; ++i) {
                diff[0] += 1 + 1;                                                  // i -> two routes begin
                ++diff[min(abs(i - x), abs(i - y) + 1)];                           // i -> x -> y, fork one route at x to y
                ++diff[min(abs(i - y), abs(i - x) + 1)];                           // i -> y -> x, fork one route at y to x
                --diff[min(abs(i - 0), abs(i - y) + 1 + abs(x - 0))];              // i -> 0, one route ends
                --diff[min(abs(i - (n - 1)), abs(i - x) + 1 + abs(y - (n - 1)))];  // i -> n-1, one route ends
                --diff[max(x - i, 0) + max(i - y, 0) + ((y - x) + 0) / 2];         // i -> x -> ((y-x)+0)//2 <- x, one route ends
                --diff[max(x - i, 0) + max(i - y, 0) + ((y - x) + 1) / 2];         // i -> y -> ((y-x)+1)//2 <- y, one route ends
            }
            for (int i = 0; i + 1 < n; ++i) {
                diff[i + 1] += diff[i];
            }
            return diff;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.countOfPairs();

        // Print result to prevent optimization
        cout << "fun_zViY9i7YagsCPdfV: Executed countOfPairs() from Count The Number Of Houses At A Certain Distance Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_zViY9i7YagsCPdfV: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
