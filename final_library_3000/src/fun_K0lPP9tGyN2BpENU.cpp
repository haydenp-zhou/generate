#include "fun_K0lPP9tGyN2BpENU.hpp"

int fun_K0lPP9tGyN2BpENU() {
    // LeetCode Problem: Maximum Product Of Subsequences With An Alternating Sum Equal To K

    // Solution class
    class Solution {

    public:
        int maxProduct(vector<int>& nums, int k, int limit) {
            const int total = accumulate(cbegin(nums), cend(nums), 0);
            if (k > total || k < -total) {  // optimized to speed up
                return -1;
            }
            unordered_map<int, unordered_map<int, unordered_set<int>>> dp;
            for (const auto& x : nums) {
                unordered_map<int, unordered_map<int, unordered_set<int>>> new_dp;
                for (const auto& [p, total_products] : dp) {
                    for (const auto& [total, products] : total_products) {
                        new_dp[p][total] = products;
                    }
                }
                new_dp[1][x].emplace(min(x, limit + 1));
                for (const auto& [p, total_products] : dp) {
                    const int new_p = p ^ 1;
                    const int v = p == 0 ? x : -x;
                    for (const auto& [total, products] : total_products) {
                        const int new_total = total + v;
                        for (const auto& v : products) {
                            new_dp[new_p][new_total].emplace(min(v * x, limit + 1));
                        }
                    }
                }
                dp = move(new_dp);
            }
            int result = -1;
            for (const auto& [p, total_products] : dp) {
                for (const auto& [total, products] : total_products) {
                    if (total != k) {
                        continue;
                    }
                    for (const auto& v : products) {
                        if (v <= limit) {
                            result = max(result, v);
                        }
                    }
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
        volatile auto result = sol.maxProduct(nums);

        // Print result to prevent optimization
        cout << "fun_K0lPP9tGyN2BpENU: Executed maxProduct() from Maximum Product Of Subsequences With An Alternating Sum Equal To K" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_K0lPP9tGyN2BpENU: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
