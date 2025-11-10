#include "fun_Sf3vojGKMY0c5G0Q.hpp"

int fun_Sf3vojGKMY0c5G0Q() {
    // LeetCode Problem: Minimum Cost To Reach Destination In Time

    // Solution class
    class Solution {

    public:
        int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
            using P = pair<int, int>;
            unordered_map<int, vector<P>> adj;
            for (const auto& edge : edges) {
                int u, v, w;
                tie(u, v, w) = make_tuple(edge[0], edge[1],edge[2]);
                adj[u].emplace_back(v, w);
                adj[v].emplace_back(u, w);
            }

            unordered_map<int, int> best;
            best[0] = 0;
            using T = tuple<int, int, int>;
            priority_queue<T, vector<T>, greater<T>> min_heap;
            min_heap.emplace(passingFees[0], 0, 0);
            while (!empty(min_heap)) {
                const auto [result, u, w] = min_heap.top(); min_heap.pop();
                if (w > maxTime) {  // state with best[u] < w can't be filtered, which may have less cost
                    continue;
                }
                if (u == size(passingFees) - 1) {
                    return result;
                }
                for (const auto& [v, nw] : adj[u]) {
                    if (!best.count(v) || w + nw < best[v]) {  // from less cost to more cost, only need to check state with less time
                        best[v] = w + nw;
                        min_heap.emplace(result + passingFees[v], v, w + nw);
                    }
                }
            }
            return -1;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.minCost(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_Sf3vojGKMY0c5G0Q: Executed minCost() from Minimum Cost To Reach Destination In Time" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Sf3vojGKMY0c5G0Q: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
