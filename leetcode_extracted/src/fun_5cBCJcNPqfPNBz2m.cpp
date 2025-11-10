#include "fun_5cBCJcNPqfPNBz2m.hpp"

int fun_5cBCJcNPqfPNBz2m() {
    // LeetCode Problem: Maximum Segment Sum After Removals

    // Solution class
    class Solution {

    public:
        vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
            vector<long long> result(size(nums));
            vector<bool> lookup(size(nums));
            UnionFind uf(nums);
            for (int i = size(removeQueries) - 1; i >= 1; --i) {
                const int q = removeQueries[i];
                lookup[q] = true;
                if (q - 1 >= 0 && lookup[q - 1]) {
                    uf.union_set(q - 1, q);
                }
                if (q + 1 < size(lookup) && lookup[q + 1]) {
                    uf.union_set(q, q + 1);
                }
                result[i - 1] = max(result[i], uf.total(q));
            }
            return result;
        }

    private:
        class UnionFind {
        public:
            UnionFind(const vector<int>& nums)
             : set_(size(nums))
             , rank_(size(nums))
             , size_(cbegin(nums), cend(nums))  {
                iota(set_.begin(), set_.end(), 0);
            }

            int find_set(int x) {
               if (set_[x] != x) {
                   set_[x] = find_set(set_[x]);  // Path compression.
               }
               return set_[x];
            }

            bool union_set(int x, int y) {
                x = find_set(x), y = find_set(y);
                if (x == y) {
                    return false;
                }
                if (rank_[x] > rank_[y]) {
                    swap(x, y);
                }
                set_[x] = y;  // Union by rank.
                if (rank_[x] == rank_[y]) {
                    ++rank_[y];
                }
                size_[y] += size_[x];
                return true;
            }

            long long total(int x) {
                return size_[find_set(x)];
            }

        private:
            vector<int> set_;
            vector<int> rank_;
            vector<long long> size_;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.maximumSegmentSum(nums);

        // Print result to prevent optimization
        cout << "fun_5cBCJcNPqfPNBz2m: Executed maximumSegmentSum() from Maximum Segment Sum After Removals" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_5cBCJcNPqfPNBz2m: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
