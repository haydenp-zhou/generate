#include "fun_77dYzS1kP6bFm61d.hpp"

int fun_77dYzS1kP6bFm61d() {
    // LeetCode Problem: Minimum Adjacent Swaps To Reach The Kth Smallest Number

    // Solution class
    class Solution {

    public:
        int getMinSwaps(string num, int k) {
            string new_num = num;
            while (k--) {
                next_permutation(begin(new_num), end(new_num));
            }
            int result = 0;
            for (int i = 0; i < size(new_num); ++i) {
                if (new_num[i] == num[i]) {
                    continue;
                }
                int j = i + 1;  // greedily swap the one with the least cost from new_num to num without missing optimal cost
                for (; j < size(new_num) && new_num[j] != num[i]; ++j);
                result += j - i;
                for (; j > i; --j) {
                    swap(new_num[j - 1], new_num[j]);
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.getMinSwaps(s);

        // Print result to prevent optimization
        cout << "fun_77dYzS1kP6bFm61d: Executed getMinSwaps() from Minimum Adjacent Swaps To Reach The Kth Smallest Number" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_77dYzS1kP6bFm61d: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
