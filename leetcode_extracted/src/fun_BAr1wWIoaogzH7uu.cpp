#include "fun_BAr1wWIoaogzH7uu.hpp"

int fun_BAr1wWIoaogzH7uu() {
    // LeetCode Problem: Optimize Water Distribution In A Village

    // Solution class
    class Solution {

    public:
        int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
            vector<tuple<int, int, int>> nodes;
            for (int i = 0; i < wells.size(); ++i) {
                nodes.emplace_back(wells[i], 0, i + 1);
            }
            for (int i = 0; i < pipes.size(); ++i) {
                nodes.emplace_back(pipes[i][2], pipes[i][0], pipes[i][1]);
            }
            sort(nodes.begin(), nodes.end());
            int result = 0;
            UnionFind union_find(n + 1);
            for (const auto& [c, x, y] : nodes) {
                if (!union_find.union_set(x, y)) {
                    continue;
                }
                result += c;
                if (union_find.count() == 1) {
                    break;
                }
            }
            return result;
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
        volatile auto result = sol.minCostToSupplyWater(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_BAr1wWIoaogzH7uu: Executed minCostToSupplyWater() from Optimize Water Distribution In A Village" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_BAr1wWIoaogzH7uu: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
