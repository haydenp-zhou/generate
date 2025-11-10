#include "fun_91nCCAyl67STNPyX.hpp"

int fun_91nCCAyl67STNPyX() {
    // LeetCode Problem: Minimum Operations To Make Character Frequencies Equal

    // Solution class
    class Solution {

    public:
        int makeStringGood(string s) {
            vector<int> cnt(26);
            for (const auto& x : s) {
                ++cnt[x - 'a'];
            }
            int mx = 0, mn = size(s);
            for (const auto& x : cnt) {
                mx = max(mx, x);
                mn = min(mn, x);
            }
            int result = size(s);
            for (int f = mn; f <= mx; ++f) {
                // dp1: min number of the last one of the operations is insert
                // dp2: min number of the last one of the operations is delete
                int dp1 = 0, dp2 = 0;
                for (int i = 0; i < 26; ++i) {
                    if (!cnt[i]) {
                        continue;
                    }
                    int new_dp1 = 0, new_dp2 = 0;
                    if (cnt[i] >= f) {
                        new_dp1 = size(s);
                        new_dp2 = min(dp1, dp2) + (cnt[i] - f);
                    } else {
                        const int free = i - 1 >= 0 ? (cnt[i - 1] >= f ? cnt[i - 1] - f : cnt[i - 1]) : 0;
                        new_dp1 = min(min(dp1, dp2) + (f - cnt[i]), dp2 + max((f - cnt[i]) - free, 0));
                        new_dp2 = min(dp1, dp2) + cnt[i];
                    }
                    dp1 = new_dp1;
                    dp2 = new_dp2;
                }
                result = min({result, dp1, dp2});
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.makeStringGood(nums);

        // Print result to prevent optimization
        cout << "fun_91nCCAyl67STNPyX: Executed makeStringGood() from Minimum Operations To Make Character Frequencies Equal" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_91nCCAyl67STNPyX: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
