#include "fun_aiBTA3UsGzIDl0oL.hpp"

int fun_aiBTA3UsGzIDl0oL() {
    // LeetCode Problem: Minimum Moves To Pick K Ones

    // Solution class
    class Solution {

    public:
        long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
            vector<int> idxs;
            for (int i = 0; i < size(nums); ++i) {
                if (nums[i]) {
                    idxs.emplace_back(i);
                }
            }
            vector<int64_t> prefix(size(idxs) + 1);
            for (int i = 0; i < size(idxs); ++i) {
                prefix[i + 1] = prefix[i] + idxs[i];
            }
            const int cnt = max(k - maxChanges, 0);
            const int bound = min({cnt + 3, k, static_cast<int>(size(idxs))});
            int64_t result = numeric_limits<int64_t>::max();
            for (int l = cnt; l <= bound; ++l) {
                const auto cnt1 = (k - l) * 2;
                for (int i = 0; i + l < size(prefix); ++i) {
                    const auto cnt2 = (prefix[(i + l - 1) + 1] - prefix[(i + l - 1) - (l / 2 - 1)]) - (prefix[(i + (l / 2 - 1)) + 1] - prefix[i]);
                    result = min(result, cnt2 + cnt1);
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
        volatile auto result = sol.minimumMoves(nums);

        // Print result to prevent optimization
        cout << "fun_aiBTA3UsGzIDl0oL: Executed minimumMoves() from Minimum Moves To Pick K Ones" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_aiBTA3UsGzIDl0oL: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
