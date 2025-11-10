#include "fun_XDFZtM4XNbstpBql.hpp"

int fun_XDFZtM4XNbstpBql() {
    // LeetCode Problem: Minimum Degree Of A Connected Trio In A Graph

    // Solution class
    class Solution {

    public:
        int minTrioDegree(int n, vector<vector<int>>& edges) {
            vector<unordered_set<int>> adj(n + 1);
            vector<int> degree(n + 1);
            for (const auto &e: edges) {
                adj[min(e[0], e[1])].emplace(max(e[0], e[1]));
                ++degree[e[0]];
                ++degree[e[1]];
            }
            int result = numeric_limits<int>::max();
            for (int u = 1; u <= n; ++u) {
                for (const auto& v : adj[u]) {
                    for (const auto& w : adj[u]) {
                        if (v < w && adj[v].count(w)) {
                            result = min(result, degree[u] + degree[v] + degree[w] - 6);
                        }
                    }
                }
            }
            return (result != numeric_limits<int>::max()) ? result : -1;
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
        volatile auto result = sol.minTrioDegree(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_XDFZtM4XNbstpBql: Executed minTrioDegree() from Minimum Degree Of A Connected Trio In A Graph" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_XDFZtM4XNbstpBql: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
