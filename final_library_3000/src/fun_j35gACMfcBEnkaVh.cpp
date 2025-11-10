#include "fun_j35gACMfcBEnkaVh.hpp"

int fun_j35gACMfcBEnkaVh() {
    // LeetCode Problem: Campus Bikes Ii

    // Solution class
    class Solution {

    public:
        int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
            vector<vector<double>> dp(2,
                                      vector<double>(1 << bikes.size(),
                                                     numeric_limits<double>::infinity()));
            dp[0][0] = 0;
            for (int i = 0; i < workers.size(); ++i) {
                dp[(i + 1) % 2] = vector<double>(1 << bikes.size(),
                                                 numeric_limits<double>::infinity());
                for (int j = 0; j < bikes.size(); ++j) {
                    for (int taken = 0; taken < (1 << bikes.size()); ++taken) {
                        if (taken & (1 << j)) {
                            continue;
                        }
                        dp[(i + 1) % 2][taken | (1 << j)] =
                            min(dp[(i + 1) % 2][taken | (1 << j)],
                                dp[i % 2][taken] + manhattan(workers[i], bikes[j]));
                    }
                }
            }
            return *min_element(dp[workers.size() % 2].cbegin(), dp[workers.size() % 2].cend());
        }

    private:
        int manhattan(const vector<int>& p1, const vector<int>& p2) {
            return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.assignBikes(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_j35gACMfcBEnkaVh: Executed assignBikes() from Campus Bikes Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_j35gACMfcBEnkaVh: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
