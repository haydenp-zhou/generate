#include "fun_L2RpKwyyZzJ29Wsy.hpp"

int fun_L2RpKwyyZzJ29Wsy() {
    // LeetCode Problem: Number Of Operations To Make Network Connected

    // Solution class
    class Solution {

    public:
        int makeConnected(int n, vector<vector<int>>& connections) {
            if (connections.size() < n - 1) {
                return -1;
            }
            UnionFind union_find(n);
            for (const auto& c : connections) {
                union_find.union_set(c[0], c[1]);
            }
            return union_find.size() - 1;
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
        volatile auto result = sol.makeConnected(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_L2RpKwyyZzJ29Wsy: Executed makeConnected() from Number Of Operations To Make Network Connected" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_L2RpKwyyZzJ29Wsy: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
