#include "fun_33N9FjyHLO4uWUMN.hpp"

int fun_33N9FjyHLO4uWUMN() {
    // LeetCode Problem: Shift Distance Between Two Strings

    // Solution class
    class Solution {

    public:
        long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
            vector<int64_t> prefix1(size(nextCost) + 1);
            for (int i = 0; i < size(nextCost); ++i) {
                prefix1[i + 1] = prefix1[i] + nextCost[i];
            }
            vector<int64_t> prefix2(size(previousCost) + 1);
            for (int i = 0; i < size(previousCost); ++i) {
                prefix2[i + 1] = prefix2[i] + previousCost[i];
            }
            int64_t result = 0;
            for (int i = 0; i < size(s); ++i) {
                if (s[i] == t[i]) {
                    continue;
                }
                const int left = s[i] - 'a';
                const int right = t[i] - 'a';
                if (left <= right) {
                    result += min(prefix1[right] - prefix1[left], prefix2.back() - (prefix2[right + 1] - prefix2[left + 1]));
                } else {
                    result += min(prefix2[left + 1] - prefix2[right + 1], prefix1.back() - (prefix1[left] - prefix1[right]));
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.shiftDistance(nums);

        // Print result to prevent optimization
        cout << "fun_33N9FjyHLO4uWUMN: Executed shiftDistance() from Shift Distance Between Two Strings" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_33N9FjyHLO4uWUMN: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
