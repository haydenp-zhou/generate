#include "fun_3kdfynuBTN7VdJNG.hpp"

int fun_3kdfynuBTN7VdJNG() {
    // LeetCode Problem: Number Of Good Paths

    // Solution class
    class Solution {

    public:
        int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
            sort(begin(edges), end(edges), [&](const auto& x, const auto& y) {
                return max(vals[x[0]], vals[x[1]]) < max(vals[y[0]], vals[y[1]]);
            });
            int result = size(vals);
            UnionFind uf(vals);
            for (const auto& e : edges) {
                result += uf.union_set(e[0], e[1], max(vals[e[0]], vals[e[1]]));
            }
            return result;
        }

    private:
        class UnionFind {
        public:
            UnionFind(const vector<int>& nums)
             : set_(size(nums))
             , rank_(size(nums))
             , cnt_(size(nums)) {  // added
                iota(set_.begin(), set_.end(), 0);
                 for (int i = 0; i < size(nums); ++i) {
                     ++cnt_[i][nums[i]];  // added
                 }
            }

            int find_set(int x) {
               if (set_[x] != x) {
                   set_[x] = find_set(set_[x]);  // Path compression.
               }
               return set_[x];
            }

            int union_set(int x, int y, int v) {  // modified
                x = find_set(x), y = find_set(y);
                if (x == y) {
                    return 0;  // modified
                }
                if (rank_[x] > rank_[y]) {
                    swap(x, y);
                }
                set_[x] = y;  // Union by rank.
                if (rank_[x] == rank_[y]) {
                    ++rank_[y];
                }
                const int cx = cnt_[x][v], cy = cnt_[y][v];  // added
                cnt_[y] = {{v, cx + cy}
    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.numberOfGoodPaths(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_3kdfynuBTN7VdJNG: Executed numberOfGoodPaths() from Number Of Good Paths" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_3kdfynuBTN7VdJNG: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
