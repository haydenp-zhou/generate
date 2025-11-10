#include "fun_NZ12jCvoCR70dBd3.hpp"

int fun_NZ12jCvoCR70dBd3() {
    // LeetCode Problem: Number Of Ways To Reconstruct A Tree

    // Solution class
    class Solution {

    public:
        int checkWays(vector<vector<int>>& pairs) {
            unordered_map<int, unordered_set<int>> adj;
            for (const auto& pair : pairs) {
                adj[pair[0]].emplace(pair[1]);
                adj[pair[1]].emplace(pair[0]);
            }
            int n = size(adj);
            bool mul = false;
            unordered_set<int> lookup;
            vector<int> nodes;
            transform(begin(adj), end(adj), back_inserter(nodes),
                      [](const auto& kvp) { return kvp.first; });
            sort(begin(nodes), end(nodes),
                 [&adj](const auto& a, const auto& b) {
                     return size(adj[a]) > size(adj[b]);
                 });
            for (const auto& node : nodes) {
                lookup.emplace(node);
                int parent = 0;
                for (const auto& x : adj[node]) {
                    if (!lookup.count(x)) {
                        continue;
                    }
                    if (parent == 0 || size(adj[x]) < size(adj[parent])) {
                        parent = x;
                    }
                }
                if (parent) {
                    for (const auto& x : adj[node]) {
                        if (x != parent && !adj[parent].count(x)) {
                            return 0;
                        }
                    }
                    mul |= size(adj[node]) == size(adj[parent]);
                } else if (size(adj[node]) != n - 1) {
                    return 0;
                }
            }
            return 1 + mul;
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
        volatile auto result = sol.checkWays(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_NZ12jCvoCR70dBd3: Executed checkWays() from Number Of Ways To Reconstruct A Tree" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_NZ12jCvoCR70dBd3: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
