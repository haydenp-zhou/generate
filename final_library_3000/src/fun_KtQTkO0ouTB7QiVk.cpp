#include "fun_KtQTkO0ouTB7QiVk.hpp"

int fun_KtQTkO0ouTB7QiVk() {
    // LeetCode Problem: Split Array Largest Sum

    // Solution class
    class Solution {

    public:
        int splitArray(vector<int>& nums, int m) {
            int64_t left = *max_element(cbegin(nums), cend(nums));
            int64_t right = accumulate(cbegin(nums), cend(nums), 0LL);
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (check(nums, m, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

    private:
        bool check(vector<int>& nums, int m, int64_t total) {
            int cnt = 1;
            int64_t curr_sum = 0;
            for (const auto& num : nums) {
                curr_sum += num;
                if (curr_sum > total) {
                    curr_sum = num;
                    ++cnt;
                }
            }
            return cnt <= m;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.splitArray(nums);

        // Print result to prevent optimization
        cout << "fun_KtQTkO0ouTB7QiVk: Executed splitArray() from Split Array Largest Sum" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_KtQTkO0ouTB7QiVk: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
