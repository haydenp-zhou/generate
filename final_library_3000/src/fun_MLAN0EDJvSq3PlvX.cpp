#include "fun_MLAN0EDJvSq3PlvX.hpp"

int fun_MLAN0EDJvSq3PlvX() {
    // LeetCode Problem: Maximum Star Sum Of A Graph

    // Solution class
    class Solution {

    public:
        int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
            vector<vector<int>> adj(size(vals));
            for (const auto& e : edges) {
                if (vals[e[1]] > 0) {
                    adj[e[0]].emplace_back(e[1]);
                }
                if (vals[e[0]] > 0) {
                    adj[e[1]].emplace_back(e[0]);
                }
            }
            int result = numeric_limits<int>::min();
            for (int u = 0; u < size(vals); ++u) {
                if (1 <= k && k <= size(adj[u])) {
                    nth_element(begin(adj[u]), begin(adj[u]) + k - 1, end(adj[u]),
                                [&](const auto& a, const auto& b) {
                                    return vals[a] > vals[b];
                                });
                }
                result = max(result, vals[u] + accumulate(cbegin(adj[u]), cbegin(adj[u]) + min(k, static_cast<int>(size(adj[u]))), 0,
                                                          [&](const auto& total, const auto& x) {
                                                              return total + vals[x];
                                                          }));
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
        volatile auto result = sol.maxStarSum(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_MLAN0EDJvSq3PlvX: Executed maxStarSum() from Maximum Star Sum Of A Graph" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_MLAN0EDJvSq3PlvX: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
