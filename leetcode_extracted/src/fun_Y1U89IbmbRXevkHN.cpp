#include "fun_Y1U89IbmbRXevkHN.hpp"

int fun_Y1U89IbmbRXevkHN() {
    // LeetCode Problem: Maximum Coins Heroes Can Collect

    // Solution class
    class Solution {

    public:
        vector<long long> maximumCoins(vector<int>& heroes, vector<int>& monsters, vector<int>& coins) {
            vector<int> idxs1(size(heroes));
            iota(begin(idxs1), end(idxs1), 0);
            sort(begin(idxs1), end(idxs1), [&](const auto& a, const auto& b) {
                return heroes[a] < heroes[b];
            });
            vector<int> idxs2(size(monsters));
            iota(begin(idxs2), end(idxs2), 0);
            sort(begin(idxs2), end(idxs2), [&](const auto& a, const auto& b) {
                return monsters[a] < monsters[b];
            });
            vector<long long> result(size(idxs1));
            int i = 0;
            long long curr = 0;
            for (const auto& idx : idxs1) {
                for (; i < size(idxs2); ++i) {
                    if (monsters[idxs2[i]] > heroes[idx]) {
                        break;
                    }
                    curr += coins[idxs2[i]];
                }
                result[idx] = curr;
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.maximumCoins(nums);

        // Print result to prevent optimization
        cout << "fun_Y1U89IbmbRXevkHN: Executed maximumCoins() from Maximum Coins Heroes Can Collect" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Y1U89IbmbRXevkHN: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
