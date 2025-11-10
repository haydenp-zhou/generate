#include "fun_Svnu7cvN5t8BtR7W.hpp"

int fun_Svnu7cvN5t8BtR7W() {
    // LeetCode Problem: Maximum Subsequence Score

    // Solution class
    class Solution {

    public:
        long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
            uint64_t result = 0, curr = 0;
            vector<pair<int, int>> nums;
            for (int i = 0; i < size(nums1); ++i) {
                nums.emplace_back(nums1[i], nums2[i]);
            }
            sort(begin(nums), end(nums), [](const auto& a, const auto& b) {
                return a.second > b.second;
            });
            priority_queue<int, vector<int>, greater<int>> min_heap;
            for (const auto& [a, b] : nums) {
                curr += a;
                min_heap.emplace(a);
                if (size(min_heap) > k) {
                    curr -= min_heap.top(); min_heap.pop();
                }
                if (size(min_heap) == k) {
                    result = max(result, curr * b);
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
        volatile auto result = sol.maxScore(nums);

        // Print result to prevent optimization
        cout << "fun_Svnu7cvN5t8BtR7W: Executed maxScore() from Maximum Subsequence Score" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Svnu7cvN5t8BtR7W: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
