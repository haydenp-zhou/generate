#include "fun_3zgkuB1mDISRjGSX.hpp"

int fun_3zgkuB1mDISRjGSX() {
    // LeetCode Problem: Kth Smallest Instructions

    // Solution class
    class Solution {

    public:
        string kthSmallestPath(vector<int>& destination, int k) {
            int r = destination[0], c = destination[1];
            string result;
            while (r + c) {
                int count = nCr(r + (c - 1), r);  // the number of HX..X combinations
                if (k <= count) {  // the kth instruction is one of HX..X combinations, so go right
                    --c;
                    result.push_back('H');
                } else {  // the kth instruction is one of VX..X combinations, so go down
                    k -= count;  // the kth one of XX..X combinations is the (k-count)th one of VX..X combinations
                    --r;
                    result.push_back('V');
                }
            }
            return result;
        }

    private:
        uint64_t nCr(int n, int r) {  // Time: O(n), Space: O(1)
            if (n < r) {
                return 0;
            }
            if (n - r < r) {
                return nCr(n, n - r);
            }
            uint64_t c = 1;
            for (int k = 1; k <= r; ++k) {
                c *= n - k + 1;
                c /= k;
            }
            return c;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.kthSmallestPath(nums);

        // Print result to prevent optimization
        cout << "fun_3zgkuB1mDISRjGSX: Executed kthSmallestPath() from Kth Smallest Instructions" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_3zgkuB1mDISRjGSX: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
