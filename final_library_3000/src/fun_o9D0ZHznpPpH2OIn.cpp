#include "fun_o9D0ZHznpPpH2OIn.hpp"

int fun_o9D0ZHznpPpH2OIn() {
    // LeetCode Problem: Minimum Edge Weight Equilibrium Queries In A Tree

    // Solution class
    class Solution {

    private:
        static const int MAX_W = 26;

    public:
        vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
            vector<vector<pair<int, int>>> adj(n);
            for (const auto& e : edges) {
                adj[e[0]].emplace_back(e[1], e[2] - 1), adj[e[1]].emplace_back(e[0], e[2] - 1);
            }
            unordered_map<int, unordered_set<int>> pairs;
            for (const auto& q : queries) {
                pairs[q[0]].emplace(q[1]), pairs[q[1]].emplace(q[0]);
            }
            TreeInfos tree_infos(adj, pairs);
            vector<int> result(size(queries));
            for (int i = 0; i < size(queries); ++i) {
                const auto& a = queries[i][0], &b = queries[i][1];
                const auto& lca = tree_infos.lca(a, b);
                int mx = 0;
                for (int w = 0; w < MAX_W; ++w) {
                    mx = max(mx, tree_infos.count(a, w) + tree_infos.count(b, w) - 2 * tree_infos.count(lca, w));
                }
                result[i] = (tree_infos.depth(a) + tree_infos.depth(b) - 2 * tree_infos.depth(lca)) - mx;
            }
            return result;
        }

    private:
        class UnionFind {
        public:
            UnionFind(int n)
             : set_(n)
             , rank_(n)
             , ancestor_(n) {
                iota(set_.begin(), set_.end(), 0);
                iota(ancestor_.begin(), ancestor_.end(), 0);  // added
            }

            int find_set(int x) {
               if (set_[x] != x) {
                   set_[x] = find_set(set_[x]);  // Path compression.
               }
               return set_[x];
            }

            bool union_set(int x, int y) {
                x = find_set(x), y = find_set(y);
                if (x == y) {
                    return false;
                }
                if (rank_[x] > rank_[y]) {
                    swap(x, y);
                }
                set_[x] = y;  // Union by rank.
                if (rank_[x] == rank_[y]) {
                    ++rank_[y];
                }
                return true;
            }

        int find_ancestor_of_set(int x) {  // added
            return ancestor_[find_set(x)];
        }

        void update_ancestor_of_set(int x) {  // added
            ancestor_[find_set(x)] = x;
        }

        private:
            vector<int> set_;
            vector<int> rank_;
            vector<int> ancestor_;  // added

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minOperationsQueries(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_o9D0ZHznpPpH2OIn: Executed minOperationsQueries() from Minimum Edge Weight Equilibrium Queries In A Tree" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_o9D0ZHznpPpH2OIn: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
