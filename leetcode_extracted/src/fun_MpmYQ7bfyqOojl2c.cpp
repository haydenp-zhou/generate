#include "fun_MpmYQ7bfyqOojl2c.hpp"

int fun_MpmYQ7bfyqOojl2c() {
    // LeetCode Problem: K Th Smallest In Lexicographical Order

    // Solution class
    class Solution {

    public:
        int findKthNumber(int n, int k) {
            int result = 0;

            vector<int> cnts(10);
            for (int i = 1; i <= 9; ++i) {
                cnts[i] = cnts[i - 1] * 10 + 1;
            }

            vector<int> nums;
            for (int i = n; i > 0; i /= 10) {
                nums.emplace_back(i % 10);
            }
            int total = n;
            int target = 0;
            for (int i = nums.size() - 1; i >= 0 && k; --i) {
                target = target * 10 + nums[i];
                const auto start = i == nums.size() - 1 ? 1 : 0;
                for (int j = start; j <= 9; ++j) {
                    const auto candidate = result * 10 + j;
                    int num;
                    if (candidate < target) {
                        num = cnts[i + 1];
                    } else if (candidate > target) {
                        num = cnts[i];
                    } else {
                        num = total - cnts[i + 1] * (j - start) - cnts[i] * (9 - j);
                    }
                    if (k > num) {
                        k -= num;
                    } else {
                        result = candidate;
                        --k;
                        total = num - 1;
                        break;
                    }
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.findKthNumber(nums);

        // Print result to prevent optimization
        cout << "fun_MpmYQ7bfyqOojl2c: Executed findKthNumber() from K Th Smallest In Lexicographical Order" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_MpmYQ7bfyqOojl2c: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
