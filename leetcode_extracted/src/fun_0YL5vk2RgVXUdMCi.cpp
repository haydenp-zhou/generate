#include "fun_0YL5vk2RgVXUdMCi.hpp"

int fun_0YL5vk2RgVXUdMCi() {
    // LeetCode Problem: Create Sorted Array Through Instructions

    // Solution class
    class Solution {

    public:
        int createSortedArray(vector<int>& instructions) {
            static const int MOD = 1e9 + 7;
            BIT bit(*max_element(cbegin(instructions), cend(instructions)));
            int result = 0;
            for (int i = 0; i < size(instructions); ++i) {
                const auto inst = instructions[i] - 1;
                auto cost = min(bit.query(inst - 1), i - bit.query(inst));
                if (MOD - result <= cost) {
                    cost -= MOD;
                }
                result += cost;
                bit.add(inst, 1);
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
        volatile auto result = sol.createSortedArray(nums);

        // Print result to prevent optimization
        cout << "fun_0YL5vk2RgVXUdMCi: Executed createSortedArray() from Create Sorted Array Through Instructions" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_0YL5vk2RgVXUdMCi: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
