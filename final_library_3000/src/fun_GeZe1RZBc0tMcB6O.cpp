#include "fun_GeZe1RZBc0tMcB6O.hpp"

int fun_GeZe1RZBc0tMcB6O() {
    // LeetCode Problem: Minimum Skips To Arrive At Meeting On Time

    // Solution class
    class Solution {

    public:
        int minSkips(vector<int>& dist, int speed, int hoursBefore) {
            vector<int> dp((size(dist) - 1) + 1);  // dp[i]: (min time by i skips) * speed
            for (int i = 0; i < size(dist); ++i) {
                for (int j = size(dp) - 1; j >= 0; --j) {
                    dp[j] = (i < size(dist) - 1) ? ceil(dp[j] + dist[i], speed) * speed : dp[j] + dist[i];
                    if (j - 1 >= 0) {
                        dp[j] = min(dp[j], dp[j - 1] + dist[i]);
                    }
                }
            }
            const int64_t target = int64_t(hoursBefore) * speed;
            for (int i = 0; i < size(dist); ++i) {
                if (dp[i] <= target) {
                    return i;
                }
            }
            return -1;
        }

    private:
        int ceil(int a, int b) {
            return (a + b - 1) / b;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.minSkips(nums);

        // Print result to prevent optimization
        cout << "fun_GeZe1RZBc0tMcB6O: Executed minSkips() from Minimum Skips To Arrive At Meeting On Time" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_GeZe1RZBc0tMcB6O: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
