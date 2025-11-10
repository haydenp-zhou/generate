#include "fun_PMtIBWLTL13CJnE2.hpp"

int fun_PMtIBWLTL13CJnE2() {
    // LeetCode Problem: Sum Of Floored Pairs

    // Solution class
    class Solution {

    public:
        int sumOfFlooredPairs(vector<int>& nums) {
            static const int MOD = 1e9 + 7;
            vector<int> prefix(*max_element(cbegin(nums), cend(nums)) + 1);
            unordered_map<int, int> count;
            for (const auto& num : nums) {
                ++count[num];
            }
            for (const auto& [num, cnt] : count) {
                for (int j = num; j < size(prefix); j += num) {
                    prefix[j] += cnt;
                }
            }
            for (int i = 0; i + 1 < size(prefix); ++i) {
                prefix[i + 1] += prefix[i];
            }
            return accumulate(cbegin(nums), cend(nums), 0,
                              [&prefix](int total, int x) {
                                  return (total + prefix[x]) % MOD;
                              });
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.sumOfFlooredPairs(nums);

        // Print result to prevent optimization
        cout << "fun_PMtIBWLTL13CJnE2: Executed sumOfFlooredPairs() from Sum Of Floored Pairs" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_PMtIBWLTL13CJnE2: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
