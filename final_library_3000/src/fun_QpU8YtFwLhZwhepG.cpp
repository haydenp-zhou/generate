#include "fun_QpU8YtFwLhZwhepG.hpp"

int fun_QpU8YtFwLhZwhepG() {
    // LeetCode Problem: Remove Max Number Of Edges To Keep Graph Fully Traversable

    // Solution class
    class Solution {

    public:
        int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
            int result = 0;
            UnionFind union_find_a(n), union_find_b(n);
            for (const auto& edge : edges) {
                int t = edge[0], i = edge[1], j = edge[2];
                if (t != 3) {
                    continue;
                }
                bool a = union_find_a.union_set(i - 1, j - 1);
                bool b = union_find_b.union_set(i - 1, j - 1);
                if (!a && !b) {
                    ++result;
                }
            }
            for (const auto& edge : edges) {
                int t = edge[0], i = edge[1], j = edge[2];
                if (t == 1) {
                    if (!union_find_a.union_set(i - 1, j - 1)) {
                        ++result;
                    }
                } else if (t == 2) {
                    if (!union_find_b.union_set(i - 1, j - 1)) {
                        ++result;
                    }
                }
            }
            return union_find_a.size() == 1 && union_find_b.size() == 1 ? result : -1;
        }

    private:
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
                set_[max(x_root, y_root)] = min(x_root, y_root);
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
        volatile auto result = sol.maxNumEdgesToRemove(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_QpU8YtFwLhZwhepG: Executed maxNumEdgesToRemove() from Remove Max Number Of Edges To Keep Graph Fully Traversable" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_QpU8YtFwLhZwhepG: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
