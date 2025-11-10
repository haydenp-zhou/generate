#include "fun_r0Et6hnNKl7lcvsr.hpp"

int fun_r0Et6hnNKl7lcvsr() {
    // LeetCode Problem: Parallel Courses Iii

    // Solution class
    class Solution {

    public:
        int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
            vector<vector<int>> adj(n);
            vector<int> in_degree(n);
            for (const auto& relation : relations) {
                adj[relation[0] - 1].emplace_back(relation[1] - 1);
                ++in_degree[relation[1] - 1];
            }
            vector<int> q;
            vector<int> dist(n);
            for (int u = 0; u < n; ++u) {
                if (in_degree[u]) {
                    continue;
                }
                q.emplace_back(u);
                dist[u] = time[u];
            }
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        dist[v] = max(dist[v], dist[u] + time[v]);
                        --in_degree[v];
                        if (!in_degree[v]) {
                            new_q.emplace_back(v);
                        }
                    }
                }
                q = move(new_q);
            }
            return *max_element(cbegin(dist), cend(dist));
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
        volatile auto result = sol.minimumTime(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_r0Et6hnNKl7lcvsr: Executed minimumTime() from Parallel Courses Iii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_r0Et6hnNKl7lcvsr: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
