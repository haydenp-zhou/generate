#include "fun_XAcR8sTS2wWWra61.hpp"

int fun_XAcR8sTS2wWWra61() {
    // LeetCode Problem: Detect Cycles In 2D Grid

    // Solution class
    class Solution {

    public:
        bool containsCycle(vector<vector<char>>& grid) {
            UnionFind union_find(grid.size() * grid[0].size());
            for (int i = 0; i < grid.size(); ++i) {
                for (int j = 0; j < grid[0].size(); ++j) {
                    if (i && j &&
                        grid[i][j] == grid[i - 1][j] &&
                        grid[i][j] == grid[i][j - 1] &&
                        union_find.find_set(index(grid[0].size(), i - 1, j)) ==
                        union_find.find_set(index(grid[0].size(), i, j - 1))) {
                        return true;
                    }
                    if (i && grid[i][j] == grid[i - 1][j]) {
                        union_find.union_set(index(grid[0].size(), i - 1, j),
                                             index(grid[0].size(), i, j));
                    }
                    if (j && grid[i][j] == grid[i][j - 1]) {
                        union_find.union_set(index(grid[0].size(), i, j - 1),
                                             index(grid[0].size(), i, j));
                    }
                }
            }
            return false;
        }

    private:
        class UnionFind {
            public:
                UnionFind(const int n) : set_(n), count_(n) {
                    iota(set_.begin(), set_.end(), 0);
                }

                int find_set(const int x) {
                   if (set_[x] != x) {
                       set_[x] = find_set(set_[x]);  // Path compression.
                   }
                   return set_[x];
                }

                void union_set(const int x, const int y) {
                    int x_root = find_set(x), y_root = find_set(y);
                    if (x_root != y_root) {
                        set_[min(x_root, y_root)] = max(x_root, y_root);
                        --count_;
                    }
                }

                int size() const {
                    return count_;
                }

            private:
                vector<int> set_;
                int count_;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.containsCycle(nums);

        // Print result to prevent optimization
        cout << "fun_XAcR8sTS2wWWra61: Executed containsCycle() from Detect Cycles In 2D Grid" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_XAcR8sTS2wWWra61: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
