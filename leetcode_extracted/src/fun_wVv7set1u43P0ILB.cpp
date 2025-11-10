#include "fun_wVv7set1u43P0ILB.hpp"

int fun_wVv7set1u43P0ILB() {
    // LeetCode Problem: Third Maximum Number

    // Solution class
    class Solution {

    public:
        int thirdMax(vector<int>& nums) {
            int count = 0;
            vector<int64_t> top(3, numeric_limits<int64_t>::min());

            for (const auto& num : nums) {
                if (num > top[0]) {
                    top[2] = top[1];
                    top[1] = top[0];
                    top[0] = num;
                    ++count;
                } else if (num != top[0] && num > top[1]) {
                    top[2] = top[1];
                    top[1] = num;
                    ++count;
                } else if (num != top[0] && num != top[1] && num >= top[2]) {
                    top[2] = num;
                    ++count;
                }
            }

            if (count < 3) { 
                return top[0];
            }
            return top[2];
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.thirdMax(nums);

        // Print result to prevent optimization
        cout << "fun_wVv7set1u43P0ILB: Executed thirdMax() from Third Maximum Number" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_wVv7set1u43P0ILB: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
