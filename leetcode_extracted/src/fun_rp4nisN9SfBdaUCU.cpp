#include "fun_rp4nisN9SfBdaUCU.hpp"

int fun_rp4nisN9SfBdaUCU() {
    // LeetCode Problem: Possible Bipartition

    // Solution class
    class Solution {

    public:
        bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
            vector<vector<int>> adj(N);
            for (const auto& dislike : dislikes) {
                int u = dislike[0] - 1, v = dislike[1] - 1;
                adj[u].emplace_back(v);
                adj[v].emplace_back(u);
            }

            vector<int> color(N);
            color[0] = 1;
            queue<int> q({0});
            while (!q.empty()) {
                const auto cur = q.front(); q.pop();
                for (const auto& nei : adj[cur]) {
                    if (color[nei] == color[cur]) {
                        return false;
                    } else if (color[nei] == -color[cur]) {
                        continue;
                    }
                    color[nei] = -color[cur];
                    q.emplace(nei);
                }
            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.possibleBipartition(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_rp4nisN9SfBdaUCU: Executed possibleBipartition() from Possible Bipartition" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_rp4nisN9SfBdaUCU: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
