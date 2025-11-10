#include "fun_6VIkb8OmG2XkNTBs.hpp"

int fun_6VIkb8OmG2XkNTBs() {
    // LeetCode Problem: Maximum Number Of K Divisible Components

    // Solution class
    class Solution {

    public:
        int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
            vector<vector<int>> adj(n);
            for (const auto& e : edges) {
                adj[e[0]].emplace_back(e[1]);
                adj[e[1]].emplace_back(e[0]);
            }
            const auto& bfs = [&]() {
                vector<int> cnt(n);
                for (int u = 0; u < n; ++u) {
                    cnt[u] = size(adj[u]);
                }
                int result = 0;
                vector<int> dp(size(values));
                transform(cbegin(values), cend(values), begin(dp), [&](const auto& x) {
                    return x % k;
                });
                vector<int> q;
                for (int u = 0; u < n; ++u) {
                    if (cnt[u] == 1) {
                        q.emplace_back(u);
                    }
                }
                while (!empty(q)) {
                    vector<int> new_q;
                    for (const auto& u : q) {
                        if (!dp[u]) {
                            ++result;
                        }
                        for (const auto& v : adj[u]) {
                            dp[v] = (dp[v] + dp[u]) % k;
                            if (--cnt[v] == 1) {
                                new_q.emplace_back(v);
                            }
                        }
                    }
                    q = move(new_q);
                }
                return max(result, 1);

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.maxKDivisibleComponents(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_6VIkb8OmG2XkNTBs: Executed maxKDivisibleComponents() from Maximum Number Of K Divisible Components" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_6VIkb8OmG2XkNTBs: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
