#include "fun_tq1f1ZdhgCudZcQi.hpp"

int fun_tq1f1ZdhgCudZcQi() {
    // LeetCode Problem: Longest Path With Different Adjacent Characters

    // Solution class
    class Solution {

    public:
        int longestPath(vector<int>& parent, string s) {    
            vector<vector<int>> adj(size(s));
            vector<int> in_degree(size(s));
            for (int i = 1; i < size(parent); ++i) {
                adj[i].emplace_back(parent[i]);
                ++in_degree[parent[i]];
            }

            const auto& topological_sort = [&s, &adj](vector<int> *in_degree) {
                int result = 1;
                unordered_map<int, vector<int>> top2;
                vector<pair<int, int>> q;
                for (int i = 0; i < size(*in_degree); ++i) {
                    if (!(*in_degree)[i]) {
                        q.emplace_back(i, 1);
                    }
                }
                while (!empty(q)) {
                    vector<pair<int, int>> new_q;
                    for (const auto& [u, l] : q) {
                        for (const auto& v : adj[u]) {
                            if (!top2.count(v)) {
                                top2[v] = vector<int>(2);
                            }
                            if (s[v] != s[u]) {
                                if (l > top2[v][0]) {
                                    top2[v][1] = top2[v][0];
                                    top2[v][0] = l;
                                } else if (l > top2[v][1]) {
                                    top2[v][1] = l;
                                }
                            }
                            if (!--(*in_degree)[v]) {
                                new_q.emplace_back(v, top2[v][0] + 1);
                                result = max(result, top2[v][0] + top2[v][1] + 1);
                                top2.erase(v);
                            }
                        }
                    }
                    q = move(new_q);
                }
                return result;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.longestPath(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_tq1f1ZdhgCudZcQi: Executed longestPath() from Longest Path With Different Adjacent Characters" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_tq1f1ZdhgCudZcQi: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
