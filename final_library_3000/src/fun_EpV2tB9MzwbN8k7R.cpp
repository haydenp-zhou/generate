#include "fun_EpV2tB9MzwbN8k7R.hpp"

int fun_EpV2tB9MzwbN8k7R() {
    // LeetCode Problem: Find The Index Of Permutation

    // Solution class
    class Solution {

    private:
        static const uint32_t MOD = 1e9 + 7;

    public:
        int getPermutationIndex(vector<int>& perm) {
            vector<int> fact(size(perm) + 1);
            fact[0] = 1;
            for (int i = 0; i + 1 < size(fact); ++i) {
                fact[i + 1] = (static_cast<int64_t>(i + 1) * fact[i]) % MOD;
            }
            int result = 0;
            BIT bit(size(perm));
            for (int i = 0; i < size(perm); ++i) {
                result = (result + (static_cast<int64_t>((((perm[i] - 1) - bit.query((perm[i] - 1) - 1)) % MOD + MOD) % MOD) * fact[(size(perm) - 1) - i] % MOD)) % MOD;
                bit.add(perm[i] - 1, +1);
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
                    bit_[i] = (bit_[i] + val) % MOD;
                }
            }

            int query(int i) const {
                ++i;
                int total = 0;
                for (; i > 0; i -= lower_bit(i)) {
                    total = (total + bit_[i]) % MOD;
                }
                return total;
            }

        private:
            inline int lower_bit(int i) const {
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
        volatile auto result = sol.getPermutationIndex(nums);

        // Print result to prevent optimization
        cout << "fun_EpV2tB9MzwbN8k7R: Executed getPermutationIndex() from Find The Index Of Permutation" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_EpV2tB9MzwbN8k7R: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
