#include "fun_C5gOXhR6L8yTKJps.hpp"

int fun_C5gOXhR6L8yTKJps() {
    // LeetCode Problem: The Earliest Moment When Everyone Become Friends

    // Solution class
    class Solution {

    public:
        int earliestAcq(vector<vector<int>>& logs, int N) {
            sort(logs.begin(), logs.end());
            UnionFind union_find(N);
            for (const auto& log : logs) {
                union_find.union_set(log[1], log[2]);
                if (union_find.count() == 1) {
                    return log[0];
                }
            }
            return -1;
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

            int count() const {
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
        volatile auto result = sol.earliestAcq(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_C5gOXhR6L8yTKJps: Executed earliestAcq() from The Earliest Moment When Everyone Become Friends" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_C5gOXhR6L8yTKJps: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
