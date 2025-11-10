#include "fun_U2yCqRjS1vpOmGzW.hpp"

int fun_U2yCqRjS1vpOmGzW() {
    // LeetCode Problem: Minimum Cost To Reach City With Discounts

    // Solution class
    class Solution {

    public:
        int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
            using P = pair<int, int>;
            unordered_map<int, vector<P>> adj;
            for (const auto& highway : highways) {
                int u, v, w;
                tie(u, v, w) = make_tuple(highway[0], highway[1], highway[2]);
                adj[u].emplace_back(v, w);
                adj[v].emplace_back(u, w);
            }

            unordered_map<int, unordered_map<int, int>> best;
            best[0][discounts] = 0;
            using T = tuple<int, int, int>;
            priority_queue<T, vector<T>, greater<T>> min_heap;
            min_heap.emplace(0, 0, discounts);
            while (!empty(min_heap)) {
                auto [total, u, k] = min_heap.top(); min_heap.pop();
                if ((best.count(u) && best[u].count(k) &&  best[u][k] < total)) {
                    continue;
                }
                if (u == n - 1) {
                    return total;
                }
                for (const auto& [v, w] : adj[u]) {
                    if (!best.count(v) ||
                        !best[v].count(k) ||
                        total + w < best[v][k]) {
                        best[v][k] = total + w;
                        min_heap.emplace(total + w, v, k);
                    }
                    if (k > 0 &&
                        (!best.count(v) ||
                        !best[v].count(k - 1) ||
                        total + w / 2 < best[v][k - 1])) {
                        best[v][k - 1] = total + w / 2;
                        min_heap.emplace(total + w / 2, v, k - 1);
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
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minimumCost(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_U2yCqRjS1vpOmGzW: Executed minimumCost() from Minimum Cost To Reach City With Discounts" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_U2yCqRjS1vpOmGzW: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
