#include "fun_kH6aYnaKzvAEDXSS.hpp"

int fun_kH6aYnaKzvAEDXSS() {
    // LeetCode Problem: Graph Valid Tree

    // Solution class
    class Solution {

    public:
        bool validTree(int n, vector<pair<int, int>>& edges) {
            if (edges.size() != n - 1) {
                return false;
            }

            unordered_map<int, vector<int>> neighbors;
            for (const auto& edge : edges) {
                neighbors[edge.first].emplace_back(edge.second);
                neighbors[edge.second].emplace_back(edge.first);
            }

            queue<int> q;
            q.emplace(0);
            unordered_set<int> visited;
            visited.emplace(0);
            while (!q.empty()) {
                const int i = q.front();
                q.pop();
                for (const auto& node : neighbors[i]) {
                    if (!visited.count(node)) {
                        visited.emplace(node);
                        q.emplace(node);
                    }
                }
            }
            return visited.size() == n;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.validTree(nums);

        // Print result to prevent optimization
        cout << "fun_kH6aYnaKzvAEDXSS: Executed validTree() from Graph Valid Tree" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_kH6aYnaKzvAEDXSS: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
