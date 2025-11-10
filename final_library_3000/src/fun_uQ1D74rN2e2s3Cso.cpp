#include "fun_uQ1D74rN2e2s3Cso.hpp"

int fun_uQ1D74rN2e2s3Cso() {
    // LeetCode Problem: Stone Game V

    // Solution class
    class Solution {

    public:
        int stoneGameV(vector<int>& stoneValue) {
            const int n = stoneValue.size();
            vector<int> prefix(n + 1);
            partial_sum(cbegin(stoneValue), cend(stoneValue), begin(prefix) + 1);

            vector<int> mid(n);
            iota(begin(mid), end(mid), 0);

            vector<vector<int>> dp(n, vector<int>(n));
            for (int i = 0; i < n; ++i) {
                dp[i][i] = stoneValue[i];
            }

            int max_score = 0;
            for (int l = 2; l <= n; ++l) {
                for (int i = 0; i <= n - l; ++i) {
                    const int j = i + l - 1;
                    while (prefix[mid[i]] - prefix[i] < prefix[j + 1] - prefix[mid[i]]) {
                        ++mid[i];  // Time: O(n^2) in total
                    }
                    const int p = mid[i];
                    max_score = 0;
                    if (prefix[p] - prefix[i] == prefix[j + 1] - prefix[p]) {
                        max_score = max(dp[i][p - 1], dp[j][p]);
                    } else {
                        if (i <= p - 2) {
                            max_score = max(max_score, dp[i][p - 2]);
                        }
                        if (p <= j) {
                            max_score = max(max_score, dp[j][p]);
                        }
                    }
                    dp[i][j] = max(dp[i][j - 1], (prefix[j + 1] - prefix[i]) + max_score);
                    dp[j][i] = max(dp[j][i + 1], (prefix[j + 1] - prefix[i]) + max_score);
                }
            }
            return max_score;
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
        volatile auto result = sol.stoneGameV(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_uQ1D74rN2e2s3Cso: Executed stoneGameV() from Stone Game V" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_uQ1D74rN2e2s3Cso: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
