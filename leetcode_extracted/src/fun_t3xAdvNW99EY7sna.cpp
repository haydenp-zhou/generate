#include "fun_t3xAdvNW99EY7sna.hpp"

int fun_t3xAdvNW99EY7sna() {
    // LeetCode Problem: Longest Palindromic Path In Graph

    // Solution class
    class Solution {

    public:
        int maxLen(int n, vector<vector<int>>& edges, string label) {
            if (size(edges) == n * (n - 1) / 2) {  // to improve performance
                vector<int> cnt(26);
                for (const auto& x : label) {
                    ++cnt[x - 'a'];
                }
                int result = 0;
                for (const auto& c : cnt) {
                    result += (c / 2) * 2;
                    if (c % 2 && result % 2 == 0) {
                        ++result;
                    }
                }
                return result;
            }
            vector<vector<int>> adj(n);
            for (const auto& e : edges) {
                adj[e[0]].emplace_back(e[1]);
                adj[e[1]].emplace_back(e[0]);
            }
            vector<vector<vector<bool>>> dp(1 << n, vector<vector<bool>>(n, vector<bool>(n)));
            for (int u = 0; u < n; ++u) {
                dp[1 << u][u][u] = true;
            }
            for (const auto& e : edges) {
                if (label[e[0]] == label[e[1]]) {
                    dp[(1 << e[0]) | (1 << e[1])][min(e[0], e[1])][max(e[0], e[1])] = true;
                }
            }
            int result = 0;
            for (int mask = 1; mask < (1 << n); ++mask) {
                for (int u = 0; u < n; ++u) {
                    for (int v = u; v < n; ++v) {
                        if (!dp[mask][u][v]) {
                            continue;
                        }
                        result = max(result, __builtin_popcount(mask));
                        for (const auto& nu : adj[u]) {
                            if (mask & (1 << nu)) {
                                continue;
                            }
                            for (const auto& nv : adj[v]) {
                                if (mask & (1 << nv)) {
                                    continue;
                                }
                                if (nu == nv) {
                                    continue;
                                }
                                if (label[nu] == label[nv]) {
                                    dp[mask | (1 << nu) | (1 << nv)][min(nu, nv)][max(nu, nv)] = true;
                                }
                            }
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
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.maxLen(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_t3xAdvNW99EY7sna: Executed maxLen() from Longest Palindromic Path In Graph" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_t3xAdvNW99EY7sna: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
