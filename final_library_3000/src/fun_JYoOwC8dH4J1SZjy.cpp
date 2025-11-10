#include "fun_JYoOwC8dH4J1SZjy.hpp"

int fun_JYoOwC8dH4J1SZjy() {
    // LeetCode Problem: Number Of Self Divisible Permutations

    // Solution class
    class Solution {

    public:
        int selfDivisiblePermutationCount(int n) {
            vector<vector<bool>> lookup(n, vector<bool>(n));
            for (int i = 0; i < n; ++i) {
                for (int j = i; j < n; ++j) {
                    lookup[i][j] = lookup[j][i] = gcd(i + 1, j + 1) == 1;
                }
            }
            vector<int> dp(1 << n);
            dp[0] = 1;
            for (int mask = 0; mask < (1 << n); ++mask) {
                const int i = __builtin_popcount(mask);
                for (int j = 0; j < n; ++j) {
                    if ((mask & (1 << j)) == 0 && lookup[i][j]) {
                        dp[mask | (1 << j)] += dp[mask];
                    }
                }
            }
            return dp.back();
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.selfDivisiblePermutationCount(nums);

        // Print result to prevent optimization
        cout << "fun_JYoOwC8dH4J1SZjy: Executed selfDivisiblePermutationCount() from Number Of Self Divisible Permutations" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_JYoOwC8dH4J1SZjy: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
