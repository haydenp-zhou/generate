#include "fun_ovKdW7xA32Swidos.hpp"

int fun_ovKdW7xA32Swidos() {
    // LeetCode Problem: Number Of Connected Components In An Undirected Graph

    // Solution class
    class Solution {

    public:
        int countComponents(int n, vector<pair<int, int>>& edges) {
            UnionFind union_find(n);
            for (const auto& e : edges) {
                union_find.union_set(e.first, e.second);
            }
            return union_find.length();
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

                int length() const {
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
        volatile auto result = sol.countComponents(nums);

        // Print result to prevent optimization
        cout << "fun_ovKdW7xA32Swidos: Executed countComponents() from Number Of Connected Components In An Undirected Graph" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_ovKdW7xA32Swidos: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
