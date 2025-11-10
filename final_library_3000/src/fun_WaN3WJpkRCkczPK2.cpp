#include "fun_WaN3WJpkRCkczPK2.hpp"

int fun_WaN3WJpkRCkczPK2() {
    // LeetCode Problem: Count Non Decreasing Subarrays After K Operations

    // Solution class
    class Solution {

    public:
        long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
            int64_t result = 0, cnt = 0;
            deque<int> dq;
            for (int left = size(nums) - 1, right = size(nums) - 1; left >= 0; --left) {
                while (!empty(dq) && nums[dq.back()] < nums[left]) {
                    const int64_t l = dq.back(); dq.pop_back();
                    const int64_t r = !empty(dq) ? dq.back() - 1 : right;
                    cnt += (r - l + 1) * (nums[left] - nums[l]);
                }
                dq.emplace_back(left);
                for (; cnt > k; --right) {
                    cnt -= nums[dq[0]] - nums[right];
                    if (dq[0] == right) {
                        dq.pop_front();
                    }
                }
                result += right - left + 1;
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
        volatile auto result = sol.countNonDecreasingSubarrays(nums);

        // Print result to prevent optimization
        cout << "fun_WaN3WJpkRCkczPK2: Executed countNonDecreasingSubarrays() from Count Non Decreasing Subarrays After K Operations" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_WaN3WJpkRCkczPK2: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
