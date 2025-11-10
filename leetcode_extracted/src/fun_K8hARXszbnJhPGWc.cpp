#include "fun_K8hARXszbnJhPGWc.hpp"

int fun_K8hARXszbnJhPGWc() {
    // LeetCode Problem: Reachable Nodes In Subdivided Graph

    // Solution class
    class Solution {

    public:
        int reachableNodes(vector<vector<int>>& edges, int M, int N) {
            using P = pair<int, int>;
            vector<vector<P>> adj(N);
            for (const auto& edge: edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                adj[u].emplace_back(v, w);
                adj[v].emplace_back(u, w);
            }
            unordered_map<int, int> best;
            best[0] = 0;
            unordered_map<int, unordered_map<int, int>> count;
            int result = 0;
            priority_queue<P, vector<P>, greater<P>> min_heap;
            min_heap.emplace(0, 0);
            while (!min_heap.empty()) {
                int curr_total, u;
                tie(curr_total, u) = min_heap.top(); min_heap.pop();
                if (best.count(u) && best[u] < curr_total) {
                    continue;
                }
                ++result;
                for (const auto& kvp: adj[u]) {
                    int v, w;
                    tie(v, w) = kvp;
                    count[u][v] = min(w, M - curr_total);
                    int next_total = curr_total + w + 1;
                    if (next_total <= M && 
                        (!best.count(v) || next_total < best[v])) {
                        best[v] = next_total;
                        min_heap.emplace(next_total, v);
                    }
                }
            }
            for (const auto& edge: edges) {
                int u = edge[0], v = edge[1], w = edge[2];
                result += min(w, count[u][v] + count[v][u]);
            }
            return result;
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
        volatile auto result = sol.reachableNodes(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_K8hARXszbnJhPGWc: Executed reachableNodes() from Reachable Nodes In Subdivided Graph" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_K8hARXszbnJhPGWc: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
