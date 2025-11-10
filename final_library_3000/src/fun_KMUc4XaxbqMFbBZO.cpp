#include "fun_KMUc4XaxbqMFbBZO.hpp"

int fun_KMUc4XaxbqMFbBZO() {
    // LeetCode Problem: Critical  Connections In A  Network

    // Solution class
    class Solution {

    public:
        int steps = 0;

        vector<int> parent;
        vector<vector<int>> adjacent_matrix;

        vector<int> steps_taken;
        vector<int> min_steps_taken;

        vector<bool> visited;

        void initParent(int& n) {
            for (int i = 0; i <= n; ++i)
            {
                parent.push_back(i);
            }
            adjacent_matrix = vector<vector<int>>(n);

            steps_taken = vector<int>(n);
            min_steps_taken = vector<int>(n);

            visited = vector<bool>(n);
        }

        void addEdge(int& x, int& y) {
            adjacent_matrix[x].push_back(y);
            adjacent_matrix[y].push_back(x);
        }

        void dfs(int& vertex, vector<vector<int>>& ans) {
            visited[vertex] = true;

            steps_taken[vertex] = min_steps_taken[vertex] = steps++;

            for (auto adj_vertex : adjacent_matrix[vertex]) {
                if (!visited[adj_vertex]) {
                    parent[adj_vertex] = vertex;

                    dfs(adj_vertex, ans);

                    min_steps_taken[vertex] = min(min_steps_taken[vertex], min_steps_taken[adj_vertex]);

                    // check if the edge is crticial for network or not
                    if (min_steps_taken[adj_vertex] > steps_taken[vertex]) {
                        ans.push_back({vertex, adj_vertex});
                    }

                } else {
                    if (parent[vertex] != adj_vertex) {
                        min_steps_taken[vertex] = min(min_steps_taken[vertex], steps_taken[adj_vertex]);
                    }
                }
            }
        }

        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            vector<vector<int>> ans;
            initParent(n);

            for (auto connection : connections) {
                addEdge(connection[0], connection[1]);
            }

            for (int i = 0; i < n; ++i)
            {
                if (visited[i]) continue;
                dfs(i, ans);
            }

            return ans;
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
        volatile auto result = sol.initParent(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_KMUc4XaxbqMFbBZO: Executed initParent() from Critical  Connections In A  Network" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_KMUc4XaxbqMFbBZO: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
