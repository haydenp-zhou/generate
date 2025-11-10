#include "fun_gmYvNFsYrpkAnQpS.hpp"

int fun_gmYvNFsYrpkAnQpS() {
    // LeetCode Problem: Sell Diminishing Valued Colored Balls

    // Solution class
    class Solution {

    public:
        int maxProfit(vector<int>& inventory, int orders) {
            static const int MOD = 1e9 + 7;

            int left = 1, right = *max_element(cbegin(inventory), cend(inventory));
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (!check(inventory, orders, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            uint64_t result = 0;
            for (const auto& cnt : inventory) {
                if (cnt >= left) {
                    result = (result + (uint64_t(left + cnt) * (cnt - left + 1) / 2) % MOD) % MOD;
                }
            }
            // assert(orders - count(inventory, left) >= 0);
            return (result + uint64_t(left - 1) * (orders - count(inventory, left)) % MOD) % MOD;
        }

    private:
        int count(const vector<int>& inventory, int x) {
            static const int MAX_ORDERS = 1e9;

            int result = 0;
            for (const auto& cnt : inventory) {
                if (cnt >= x) {
                    if (result >= (MAX_ORDERS + 1) - (cnt - x + 1)) {
                        result = MAX_ORDERS + 1;
                        break;
                    }
                    result += cnt - x + 1;
                }
            }
            return result;
        }

        bool check(const vector<int>& inventory, int orders, int x) {
            return count(inventory, x) > orders;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.maxProfit(nums);

        // Print result to prevent optimization
        cout << "fun_gmYvNFsYrpkAnQpS: Executed maxProfit() from Sell Diminishing Valued Colored Balls" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_gmYvNFsYrpkAnQpS: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
