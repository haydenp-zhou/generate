#include "fun_8y2SmvP2RHV1A5TY.hpp"

int fun_8y2SmvP2RHV1A5TY() {
    // LeetCode Problem: Sum Of Distances In Tree

    // Solution class
    class Solution {

    public:
        vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
            unordered_map<int, vector<int>> graph;
            for (const auto& edge : edges) {
                graph[edge[0]].emplace_back(edge[1]);
                graph[edge[1]].emplace_back(edge[0]);
            }

            vector<int> count(N, 1);
            vector<int> result(N, 0);

            dfs(graph, 0, -1, &count, &result);
            dfs2(graph, 0, -1, &count, &result);
            return result;
        }

    private:
        void dfs(const unordered_map<int, vector<int>>& graph,
                 int node, int parent,
                 vector<int> *count, vector<int> *result) {
            if (!graph.count(node)) {
                return;
            }
            for (const auto& nei : graph.at(node)) {
                if (nei != parent) {
                    dfs(graph, nei, node, count, result);
                    (*count)[node] += (*count)[nei];
                    (*result)[node] += (*result)[nei] + (*count)[nei];
                }
            }
        }

        void dfs2(const unordered_map<int, vector<int>>& graph,
                 int node, int parent,
                 vector<int> *count, vector<int> *result) {
            if (!graph.count(node)) {
                return;
            }
            for (const auto& nei : graph.at(node)) {
                if (nei != parent) {
                    (*result)[nei] = (*result)[node] - (*count)[nei] +
                                     count->size() - (*count)[nei];
                    dfs2(graph, nei, node, count, result);
                }
            }
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
        volatile auto result = sol.sumOfDistancesInTree(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_8y2SmvP2RHV1A5TY: Executed sumOfDistancesInTree() from Sum Of Distances In Tree" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_8y2SmvP2RHV1A5TY: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
