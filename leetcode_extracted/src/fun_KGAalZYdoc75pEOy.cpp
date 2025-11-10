#include "fun_KGAalZYdoc75pEOy.hpp"

int fun_KGAalZYdoc75pEOy() {
    // LeetCode Problem: Count Of Smaller Numbers After Self

    // Solution class
    class Solution {

    public:
        vector<int> countSmaller(vector<int>& nums) {
            // Get the place (position in the ascending order) of each number.
            vector<int> idx(size(nums));
            iota(begin(idx), end(idx), 0);
            vector<int> lookup(size(nums));
            sort(begin(idx), end(idx),
                 [&nums](const auto& a, const auto& b) {
                     return nums[a] == nums[b] ? a < b : nums[a] < nums[b];
                 });
            for (int i = 0; i < size(idx); ++i) {
                lookup[idx[i]] = i;
            }
            // Count the smaller elements after the number.
            BIT bit(size(nums));
            vector<int> result(size(nums));
            for (int i = size(nums) - 1; i >= 0; --i) {
                result[i] = bit.query(lookup[i] - 1);
                bit.add(lookup[i], 1);
            }
            return result;
        }

    private:
        class BIT {
        public:
            BIT(int n) : bit_(n + 1) {  // 0-indexed
            }

            void add(int i, int val) {
                ++i;
                for (; i < size(bit_); i += lower_bit(i)) {
                    bit_[i] += val;
                }
            }

            int query(int i) const {
                ++i;
                int total = 0;
                for (; i > 0; i -= lower_bit(i)) {
                    total += bit_[i];
                }
                return total;
            }

        private:
            int lower_bit(int i) const {
                return i & -i;
            }

            vector<int> bit_;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.countSmaller(nums);

        // Print result to prevent optimization
        cout << "fun_KGAalZYdoc75pEOy: Executed countSmaller() from Count Of Smaller Numbers After Self" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_KGAalZYdoc75pEOy: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
