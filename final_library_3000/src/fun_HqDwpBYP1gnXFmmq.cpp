#include "fun_HqDwpBYP1gnXFmmq.hpp"

int fun_HqDwpBYP1gnXFmmq() {
    // LeetCode Problem: Maximum And Minimum Sums Of At Most Size K Subarrays

    // Solution class
    class Solution {

    public:
        long long minMaxSubarraySum(vector<int>& nums, int k) {
            const auto& count = [&](const auto& check) {
                int64_t result = 0, total = 0;
                deque<int> dq;
                for (int right = 0; right < size(nums); ++right) {
                    while (!empty(dq) && !check(nums[dq.back()], nums[right])) {
                        const int i  = dq.back(); dq.pop_back();
                        const int64_t cnt = i - (!empty(dq) ? dq.back() + 1 : max(right - k + 1, 0)) + 1;
                        total -= cnt * nums[i];
                    }
                    const int64_t cnt = right - (!empty(dq) ? dq.back() + 1 : max(right - k + 1, 0)) + 1;
                    dq.emplace_back(right);
                    total += cnt * nums[right];
                    result += total;
                    if (right >= k - 1) {
                        total -= nums[dq[0]];
                        if (dq[0] == right - (k - 1)) {
                            dq.pop_front();
                        }
                    }
                }
                return result;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minMaxSubarraySum(nums);

        // Print result to prevent optimization
        cout << "fun_HqDwpBYP1gnXFmmq: Executed minMaxSubarraySum() from Maximum And Minimum Sums Of At Most Size K Subarrays" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_HqDwpBYP1gnXFmmq: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
