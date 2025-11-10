#include "fun_AwwDOl6EgcITA4Eh.hpp"

int fun_AwwDOl6EgcITA4Eh() {
    // LeetCode Problem: Count Visited Nodes In A Directed Graph

    // Solution class
    class Solution {

    public:
        vector<int> countVisitedNodes(vector<int>& edges) {
            const auto& find_cycles = [](const auto& adj) {
                vector<int> result(size(adj));
                vector<int> lookup(size(adj));
                vector<int> stk;  // added
                stk.reserve(size(adj));
                for (int i = 0, idx = 0; i < size(adj); ++i) {
                    int u = i, prev = idx;
                    while (!lookup[u]) {
                        lookup[u] = ++idx;
                        stk.emplace_back(u);  // added
                        u = adj[u];
                    }
                    if (lookup[u] > prev) {
                        const int l = idx - lookup[u] + 1;
                        for (int _ = 0; _ < l; ++_) {  // added
                            result[stk.back()] = l;
                            stk.pop_back();
                        }
                    }
                    while (!empty(stk))  {  // added
                        result[stk.back()] = result[adj[stk.back()]] + 1;
                        stk.pop_back();
                    }
                }
                return result;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.countVisitedNodes(nums);

        // Print result to prevent optimization
        cout << "fun_AwwDOl6EgcITA4Eh: Executed countVisitedNodes() from Count Visited Nodes In A Directed Graph" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_AwwDOl6EgcITA4Eh: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
