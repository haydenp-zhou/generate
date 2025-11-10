#include "fun_MZId3ctWoRFYkxnS.hpp"

int fun_MZId3ctWoRFYkxnS() {
    // LeetCode Problem: Ugly Number Ii

    // Solution class
    class Solution {

    public:
        int nthUglyNumber(int n) {
            vector<int> uglies(n);
            uglies[0] = 1;

            int f2 = 2, f3 = 3, f5 = 5;
            int idx2 = 0, idx3 = 0, idx5 = 0;

            for (int i = 1; i < n; ++i) {
                int min_val = min(min(f2, f3), f5);
                uglies[i] = min_val;

                if (min_val == f2) {
                    f2 = 2 * uglies[++idx2];
                }
                if (min_val == f3) {
                    f3 = 3 * uglies[++idx3];
                }
                if (min_val == f5) {
                    f5 = 5 * uglies[++idx5];
                }
            }

            return uglies[n - 1];
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.nthUglyNumber(nums);

        // Print result to prevent optimization
        cout << "fun_MZId3ctWoRFYkxnS: Executed nthUglyNumber() from Ugly Number Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_MZId3ctWoRFYkxnS: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
