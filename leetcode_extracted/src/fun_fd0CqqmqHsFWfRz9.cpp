#include "fun_fd0CqqmqHsFWfRz9.hpp"

int fun_fd0CqqmqHsFWfRz9() {
    // LeetCode Problem: Maximum Points After Collecting Coins From All Nodes

    // Solution class
    class Solution {

    public:
        int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
            static const int NEG_INF = numeric_limits<int>::min();

            vector<vector<int>> adj(size(coins));
            for (const auto& e : edges) {
                adj[e[0]].emplace_back(e[1]);
                adj[e[1]].emplace_back(e[0]);
            }
            const int mx = *max_element(cbegin(coins), cend(coins));
            const int max_base = 1 << (mx != 0 ? __lg(mx) + 1 : 0);
            vector<int> lookup(size(coins));
            const function<int (int, int, int)> dfs = [&](int u, int p, int base) {
                if (base >= max_base) {
                    return 0;
                }
                if (lookup[u] & base) {  // we prefer the first way to the second way, so the visited state cannot improve the current chosen ways
                    return NEG_INF;
                }
                lookup[u] |= base;
                int total1 = (coins[u] / base) - k;
                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    const auto& r = dfs(v, u, base);
                    if (r == NEG_INF) {
                        total1 = r;
                        break;
                    }
                    total1 += r;
                }
                if ((coins[u] / base) - k >= coins[u] / (base << 1)) {  // if (coins[u]//base)-k >= coins[u]//(base*2), the first way is always better
                    return total1;
                }
                int total2 = coins[u] / (base << 1);
                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    const auto& r = dfs(v, u, base << 1);
                    if (r == NEG_INF) {
                        total2 = r;
                        break;
                    }
                    total2 += r;
                }
                return max(total1, total2);

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.maximumPoints(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_fd0CqqmqHsFWfRz9: Executed maximumPoints() from Maximum Points After Collecting Coins From All Nodes" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_fd0CqqmqHsFWfRz9: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
