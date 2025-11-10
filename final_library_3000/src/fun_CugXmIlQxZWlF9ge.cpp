#include "fun_CugXmIlQxZWlF9ge.hpp"

int fun_CugXmIlQxZWlF9ge() {
    // LeetCode Problem: Find Critical And Pseudo Critical Edges In Minimum Spanning Tree

    // Solution class
    class Solution {

    public:
        vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
            for (int i = 0; i < edges.size(); ++i) {
                edges[i].push_back(i);
            }
            sort(begin(edges), end(edges),
                 [](const auto& a, const auto& b) {
                     return a[2] < b[2];
                 });
            int mst = MST(n, edges);
            vector<vector<int>> result(2);
            for (int i = 0; i < edges.size(); ++i) {
                if (mst < MST(n, edges, i)) {
                    result[0].emplace_back(edges[i][3]);
                } else if (mst == MST(n, edges, -1, i)) {
                    result[1].emplace_back(edges[i][3]);
                }
            }
            return result;
        }

    private:
        int MST(const int n, const vector<vector<int>>& edges,
                int unused = -1, int used = -1) {
            UnionFind union_find(n);
            int weight = 0;
            if (used != -1) {
                const auto& edge = edges[used];
                if (union_find.union_set(edge[0], edge[1])) {
                    weight += edge[2];
                }
            }
            for (int i = 0; i < edges.size(); ++i) {
                if (i == unused) {
                    continue;
                }
                const auto& edge = edges[i];
                if (union_find.union_set(edge[0], edge[1])) {
                    weight += edge[2];
                }
            }
            return union_find.size() == 1 ? weight : numeric_limits<int>::max();
        }

        class UnionFind {
        public:
            UnionFind(const int n) : set_(n), size_(n) {
                iota(set_.begin(), set_.end(), 0);
            }

            int find_set(const int x) {
               if (set_[x] != x) {
                   set_[x] = find_set(set_[x]);  // Path compression.
               }
               return set_[x];
            }

            bool union_set(const int x, const int y) {
                int x_root = find_set(x), y_root = find_set(y);
                if (x_root == y_root) {
                    return false;
                }
                set_[min(x_root, y_root)] = max(x_root, y_root);
                --size_;
                return true;
            }

            int size() const {
                return size_;
            }

        private:
            vector<int> set_;
            int size_;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.findCriticalAndPseudoCriticalEdges(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_CugXmIlQxZWlF9ge: Executed findCriticalAndPseudoCriticalEdges() from Find Critical And Pseudo Critical Edges In Minimum Spanning Tree" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_CugXmIlQxZWlF9ge: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
