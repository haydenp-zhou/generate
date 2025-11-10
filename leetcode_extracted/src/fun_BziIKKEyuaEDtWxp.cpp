#include "fun_BziIKKEyuaEDtWxp.hpp"

int fun_BziIKKEyuaEDtWxp() {
    // LeetCode Problem: Earliest Second To Mark Indices Ii

    // Solution class
    class Solution {

    public:
        int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
            vector<int> lookup(size(nums), -1);
            for (int i = size(changeIndices) - 1; i >= 0; --i) {
                if (nums[changeIndices[i] - 1]) {
                    lookup[changeIndices[i] - 1] = i;
                }
            }
            const int64_t total = accumulate(cbegin(nums), cend(nums), 0ll) + size(nums);
            const auto& check = [&](int t) {
                priority_queue<int, vector<int>, greater<int>> min_heap;
                int64_t total2 = 0, cnt = 0;
                for (int i = t - 1; i >= 0; --i) {
                    if (i != lookup[changeIndices[i] - 1]) {
                        ++cnt;
                        continue;
                    }
                    min_heap.emplace(nums[changeIndices[i] - 1]);
                    total2 += nums[changeIndices[i] - 1];
                    if (cnt) {
                        --cnt;
                    } else {
                        ++cnt;
                        total2 -= min_heap.top(); min_heap.pop();
                    }
                }
                return total - (total2 + (size(min_heap))) <= cnt;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.earliestSecondToMarkIndices(nums);

        // Print result to prevent optimization
        cout << "fun_BziIKKEyuaEDtWxp: Executed earliestSecondToMarkIndices() from Earliest Second To Mark Indices Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_BziIKKEyuaEDtWxp: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
