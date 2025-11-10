#include "fun_9Yzwwx0KVS3KRmJq.hpp"

int fun_9Yzwwx0KVS3KRmJq() {
    // LeetCode Problem: Collect Coins In A Tree

    // Solution class
    class Solution {

    public:
        int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
            static const int DISTANCE = 2;

            vector<unordered_set<int>> adj(size(coins));
            for (const auto& e : edges) {
                adj[e[0]].emplace(e[1]);
                adj[e[1]].emplace(e[0]);
            }
            int n = size(coins);
            for (int i = 0; i < size(coins); ++i) {
                int u = i;
                while (size(adj[u]) == 1 && !coins[u]) {
                    const int v = *cbegin(adj[u]);
                    adj[u].erase(v);
                    adj[v].erase(u);
                    --n;
                    u = v;
                }
            }
            vector<int> q;
            for (int u = 0; u < size(coins); ++u) {
                if (size(adj[u]) == 1) {
                    q.emplace_back(u);
                }
            }
            for (int _ = 0; _ < DISTANCE; ++_) {
                vector<int> new_q;
                for (const auto& u : q) {
                    if (empty(adj[u])) {
                        assert(n == 1);
                        break;
                    }
                    const int v = *cbegin(adj[u]);
                    adj[u].erase(v);
                    adj[v].erase(u);
                    --n;
                    if (size(adj[v]) == 1) {
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            return (n - 1) * 2;
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
        volatile auto result = sol.collectTheCoins(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_9Yzwwx0KVS3KRmJq: Executed collectTheCoins() from Collect Coins In A Tree" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_9Yzwwx0KVS3KRmJq: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
