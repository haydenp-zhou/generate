#include "fun_mDncso8RP5NkcZHd.hpp"

int fun_mDncso8RP5NkcZHd() {
    // LeetCode Problem: Number Of Restricted Paths From First To Last Node

    // Solution class
    class Solution {

    public:
        int countRestrictedPaths(int n, vector<vector<int>>& edges) {
            static const int MOD = 1e9 + 7;
            vector<vector<pair<int, int>>> adj(n);
            for (const auto& e : edges) {
                int u = e[0] - 1, v = e[1] - 1, w = e[2];
                adj[u].emplace_back(v, w);
                adj[v].emplace_back(u, w);
            }
            vector<int> dist(n, numeric_limits<int>::max()), dp(n);
            dist[n - 1] = 0;
            dp[n - 1] = 1;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
            min_heap.emplace(0, n - 1);
            while (!empty(min_heap)) {
                const auto [w, u] = min_heap.top(); min_heap.pop();
                if (w > dist[u]) {
                    continue;
                }
                for (const auto& [v, d] : adj[u]) {
                    if (w + d < dist[v]) {
                        dist[v] = w + d;
                        min_heap.emplace(dist[v], v);
                    } else if (w > dist[v]) {
                        dp[u] = (dp[u] + dp[v]) % MOD;
                    }
                }
                if (u == 0) {  // early return
                    break;
                }
            }
            return dp[0];
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
        volatile auto result = sol.countRestrictedPaths(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_mDncso8RP5NkcZHd: Executed countRestrictedPaths() from Number Of Restricted Paths From First To Last Node" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_mDncso8RP5NkcZHd: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
