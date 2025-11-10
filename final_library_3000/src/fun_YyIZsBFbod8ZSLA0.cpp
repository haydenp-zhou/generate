#include "fun_YyIZsBFbod8ZSLA0.hpp"

int fun_YyIZsBFbod8ZSLA0() {
    // LeetCode Problem: Shortest Distance To Target Color

    // Solution class
    class Solution {

    public:
        vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {   
            vector<vector<int>> dp(3, vector<int>(colors.size(), -1));
            dp[colors[0] - 1][0] = 0;
            for (int i = 1; i < colors.size(); ++i) {
                for (int color = 0; color < 3; ++color) {
                    dp[color][i] = dp[color][i - 1];
                }
                dp[colors[i] - 1][i] = i;
            }

            dp[colors[colors.size() - 1] - 1][colors.size() - 1] = colors.size() - 1;
            for (int i = colors.size() - 2; i >= 0; --i) {
                for (int color = 0; color < 3; ++color) {
                    if (dp[color][i + 1] != -1) {
                        continue;
                    }
                    if (dp[color][i] == -1 ||
                        abs(dp[color][i + 1] - i) < abs(dp[color][i] - i)) {
                        dp[color][i] = dp[color][i + 1];
                    }
                }
                dp[colors[i] - 1][i] = i;
            }

            vector<int> result;
            for (const auto& query : queries) {
                const auto d = abs(dp[query[1] - 1][query[0]]);
                result.emplace_back(dp[query[1] - 1][query[0]] != -1 ? abs(dp[query[1] - 1][query[0]] - query[0]) : -1);
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.shortestDistanceColor(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_YyIZsBFbod8ZSLA0: Executed shortestDistanceColor() from Shortest Distance To Target Color" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_YyIZsBFbod8ZSLA0: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
