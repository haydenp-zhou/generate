#include "fun_7mGl7FENGaEzTq6d.hpp"

int fun_7mGl7FENGaEzTq6d() {
    // LeetCode Problem: Friend Circles

    // Solution class
    class Solution {

    public:
        int findCircleNum(vector<vector<int>>& M) {
            UnionFind circles(M.size());
            for (int i = 0; i < M.size(); ++i) {
                for (int j = 0; j < M[i].size(); ++j) {
                    if (M[i][j] && i != j) {
                        circles.union_set(i, j);
                    }
                }
            }
            return circles.size();
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
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.findCircleNum(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_7mGl7FENGaEzTq6d: Executed findCircleNum() from Friend Circles" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_7mGl7FENGaEzTq6d: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
