#include "fun_m1L0XPxhFHGXZPXd.hpp"

int fun_m1L0XPxhFHGXZPXd() {
    // LeetCode Problem: New 21 Game

    // Solution class
    class Solution {

    public:
        double new21Game(int N, int K, int W) {
            if (K == 0 || N >= K + W) {
                return 1.0f;
            }
            vector<double> dp(N + 1);
            dp[0] = 1.0f;
            double W_sum = 1.0f, result = 0.0f;
            for (int i = 1; i <= N; ++i) {
                dp[i] = W_sum / W;
                if (i < K) {
                    W_sum += dp[i];
                } else {
                    result += dp[i];
                }
                if (i - W >= 0) {
                    W_sum -= dp[i - W];
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.new21Game(testValue);

        // Print result to prevent optimization
        cout << "fun_m1L0XPxhFHGXZPXd: Executed new21Game() from New 21 Game" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_m1L0XPxhFHGXZPXd: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
