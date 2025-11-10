#include "fun_VZWO4cgmNvQVZCHk.hpp"

int fun_VZWO4cgmNvQVZCHk() {
    // LeetCode Problem: Choose K Elements With Maximum Sum

    // Solution class
    class Solution {

    public:
        vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
            vector<long long> result(size(nums1));
            priority_queue<int, vector<int>, greater<int>> min_heap;
            vector<int> idxs(size(nums1));
            iota(begin(idxs), end(idxs), 0);
            sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
                return nums1[a] < nums1[b];
            });
            int64_t total = 0;
            for (int i = 0, j = 0; i < size(idxs); ++i) {
                for (; nums1[idxs[j]] < nums1[idxs[i]]; ++j) {
                    total += nums2[idxs[j]];
                    min_heap.emplace(nums2[idxs[j]]);
                    if (size(min_heap) == k + 1) {
                        total -= min_heap.top(); min_heap.pop();
                    }
                }
                result[idxs[i]] = total;
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
        volatile auto result = sol.findMaxSum(nums);

        // Print result to prevent optimization
        cout << "fun_VZWO4cgmNvQVZCHk: Executed findMaxSum() from Choose K Elements With Maximum Sum" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_VZWO4cgmNvQVZCHk: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
