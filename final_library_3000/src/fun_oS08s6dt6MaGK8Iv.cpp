#include "fun_oS08s6dt6MaGK8Iv.hpp"

int fun_oS08s6dt6MaGK8Iv() {
    // LeetCode Problem: Parallel Courses Ii

    // Solution class
    class Solution {

    public:
        int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
            vector<int> reqs(n);
            for (const auto& d : dependencies) {
                reqs[d[1] - 1] |= 1 << (d[0] - 1);
            }
            vector<int> dp(1 << n, n);
            dp[0] = 0;
            for (int mask = 0; mask < dp.size(); ++mask) {
                vector<int> candidates;
                for (int v = 0; v < n; ++v) {
                    if ((mask & (1 << v)) == 0 && (mask & reqs[v]) == reqs[v]) {
                        candidates.emplace_back(v);
                    }
                }
                const auto r = min(int(candidates.size()), k);
                combinations(candidates.size(), min(int(candidates.size()), k), 
                             [&dp, &mask, &candidates](const vector<int>& idxs) {
                                 auto new_mask = mask;
                                 new_mask |= accumulate(cbegin(idxs), cend(idxs), 0,
                                                        [&candidates](const auto& a, const auto& b) {
                                                            return a | (1 << candidates[b]);
                                                        });
                                 dp[new_mask] = min(dp[new_mask], dp[mask] + 1);
                             });
            }
            return dp.back();
        }

    private:
        void combinations(int n, int k, const function<void (const vector<int>&)>& callback) {
            static const auto& next_pos =
                [](const auto& n, const auto& k, const auto& idxs) {
                    int i = k - 1;
                    for (; i >= 0; --i) {
                        if (idxs[i] != i + n - k) {
                            break;
                        }
                    }
                    return i;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minNumberOfSemesters(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_oS08s6dt6MaGK8Iv: Executed minNumberOfSemesters() from Parallel Courses Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_oS08s6dt6MaGK8Iv: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
