#include "fun_Qi8ExjddyRw6SRaP.hpp"

int fun_Qi8ExjddyRw6SRaP() {
    // LeetCode Problem: 3Sum With Multiplicity

    // Solution class
    class Solution {

    public:
        int threeSumMulti(vector<int>& A, int target) {
            unordered_map<int, uint64_t> count;
            for (const auto& a : A) {
                ++count[a];
            }
            uint64_t result = 0;
            for (const auto& kvp1 : count) {
                for (const auto& kvp2 : count) {
                    int i = kvp1.first, j = kvp2.first, k = target - i - j;
                    if (!count.count(k)) {
                        continue;
                    }
                    if (i == j && j == k) {
                        result += count[i] * (count[i] - 1) * (count[i] - 2) / 6;
                    } else if (i == j && j != k) {
                        result += count[i] * (count[i] - 1) / 2 * count[k];
                    } else if (i < j && j < k) {
                        result += count[i] * count[j] * count[k];
                    }
                }
            }
            return result % static_cast<int>(1e9 + 7);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.threeSumMulti(nums);

        // Print result to prevent optimization
        cout << "fun_Qi8ExjddyRw6SRaP: Executed threeSumMulti() from 3Sum With Multiplicity" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Qi8ExjddyRw6SRaP: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
