#include "fun_MwagxVp11T5zZIhx.hpp"

int fun_MwagxVp11T5zZIhx() {
    // LeetCode Problem: Connecting Cities With Minimum Cost

    // Solution class
    class Solution {

    public:
        int minimumCost(int N, vector<vector<int>>& connections) {
            sort(connections.begin(), connections.end(),
                 [](const auto& a, const auto& b) {
                    return a[2] < b[2]; 
                 });
            UnionFind union_find(N);
            int result = 0;
            for (const auto& c : connections) {
                if (union_find.union_set(c[0] - 1, c[1] - 1)) {
                    result += c[2];
                }
            }
            return union_find.size() == 1 ? result : -1;
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

            bool union_set(const int x, const int y) {
                int x_root = find_set(x), y_root = find_set(y);
                if (x_root == y_root) {
                    return false;
                }
                set_[min(x_root, y_root)] = max(x_root, y_root);
                --count_;
                return true;
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
        volatile auto result = sol.minimumCost(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_MwagxVp11T5zZIhx: Executed minimumCost() from Connecting Cities With Minimum Cost" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_MwagxVp11T5zZIhx: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
