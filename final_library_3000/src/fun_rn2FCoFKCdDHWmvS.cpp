#include "fun_rn2FCoFKCdDHWmvS.hpp"

int fun_rn2FCoFKCdDHWmvS() {
    // LeetCode Problem: Construct String With Minimum Cost Easy

    // Solution class
    class Solution {

    public:
        int minimumCost(string target, vector<string>& words, vector<int>& costs) {
            int l = 0;
            for (const auto& w : words) {
                l = max(l, static_cast<int>(size(w)));
            }
            vector<int> dp(l + 1, INF);
            dp[0] = 0;
            for (int i = 0; i < size(target); ++i) {
                if (dp[i % size(dp)] == INF) {
                    continue;
                }
                for (int j = 0; j < size(words); ++j) {
                    if (target.substr(i, size(words[j])) == words[j]) {
                        dp[(i + size(words[j])) % size(dp)] = min(dp[(i + size(words[j])) % size(dp)], dp[i % size(dp)] + costs[j]);
                    }
                }
                dp[i % size(dp)] = INF;
            }
            return dp[size(target) % size(dp)] != INF ? dp[size(target) % size(dp)] : -1;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.minimumCost(nums);

        // Print result to prevent optimization
        cout << "fun_rn2FCoFKCdDHWmvS: Executed minimumCost() from Construct String With Minimum Cost Easy" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_rn2FCoFKCdDHWmvS: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
