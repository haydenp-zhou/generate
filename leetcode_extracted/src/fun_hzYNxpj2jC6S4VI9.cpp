#include "fun_hzYNxpj2jC6S4VI9.hpp"

int fun_hzYNxpj2jC6S4VI9() {
    // LeetCode Problem: Largest Color Value In A Directed Graph

    // Solution class
    class Solution {

    public:
        int largestPathValue(string colors, vector<vector<int>>& edges) {
            vector<vector<int>> adj(size(colors));
            vector<int> in_degree(size(colors));
            for (const auto& edge : edges) {
                adj[edge[0]].emplace_back(edge[1]);
                ++in_degree[edge[1]];
            }
            vector<int> q;
            for (int i = 0; i < size(colors); ++i) {
                if (!in_degree[i]) {
                    q.emplace_back(i);
                }
            }
            vector<vector<int>> dp(size(colors), vector<int>(26));
            int result = -1, cnt = 0;
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    ++cnt;
                    result = max(result, ++dp[u][colors[u] - 'a']);
                    for (const auto& v : adj[u]) {
                        for (int c = 0; c < 26; ++c) {
                            dp[v][c] = max(dp[v][c], dp[u][c]);
                        }
                        if (!--in_degree[v]) {
                            new_q.emplace_back(v);
                        }
                    }
                }
                q = move(new_q);
            }
            return cnt == size(colors) ? result : -1;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.largestPathValue(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_hzYNxpj2jC6S4VI9: Executed largestPathValue() from Largest Color Value In A Directed Graph" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_hzYNxpj2jC6S4VI9: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
