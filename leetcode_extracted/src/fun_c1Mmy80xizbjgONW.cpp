#include "fun_c1Mmy80xizbjgONW.hpp"

int fun_c1Mmy80xizbjgONW() {
    // LeetCode Problem: Maximum Fruits Harvested After At Most K Steps

    // Solution class
    class Solution {

    public:
        int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
            const int max_pos = max(startPos, fruits.back()[0]);
            vector<int> cnt(max_pos + 1);
            for (const auto& x : fruits) {
                cnt[x[0]] += x[1];
            }
            vector<int> prefix(1);
            for (int i = 0; i < size(cnt); ++i) {
                prefix.emplace_back(prefix.back() + cnt[i]);
            }
            int result = 0;
            for (int left_dist = 0; left_dist <= min(startPos, k); ++left_dist) {
                const int right_dist = max(k - 2 * left_dist, 0);
                const int left = startPos - left_dist;
                const int right = min(startPos + right_dist, max_pos);
                result = max(result, prefix[right + 1] - prefix[left]);
            }
            for (int right_dist = 0; right_dist <= min(max_pos - startPos, k); ++right_dist) {
                const int left_dist = max(k - 2 * right_dist, 0);
                const int left = max(startPos - left_dist, 0);
                const int right = startPos + right_dist;
                result = max(result, prefix[right + 1] - prefix[left]);
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.maxTotalFruits(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_c1Mmy80xizbjgONW: Executed maxTotalFruits() from Maximum Fruits Harvested After At Most K Steps" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_c1Mmy80xizbjgONW: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
