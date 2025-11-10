#include "fun_YujIDn1LsvSFsq3V.hpp"

int fun_YujIDn1LsvSFsq3V() {
    // LeetCode Problem: Make String Anti Palindrome

    // Solution class
    class Solution {

    public:
        string makeAntiPalindrome(string s) {
            vector<int> cnt(26);
            for (const auto& x : s) {
                ++cnt[x - 'a'];
            }
            if (ranges::max(cnt) > size(s) / 2) {
                return "-1";
            }
            string result(size(s), 0);
            for (int i = 0, j = 0; i < size(cnt); ++i) {
                for (int _ = 0; _ < cnt[i]; ++_) {
                    result[j++] = 'a' + i;
                }
            }
            int l = 0;
            for (; l <= (size(s) / 2) / 2; ++l) {
                if (result[size(s) / 2 + l] != result[size(s) / 2 - 1]) {
                    break;
                }
            }
            if (l) {
                for (int i = 0; i < cnt[result[size(s) / 2 - 1] - 'a'] - l; ++i) {
                    swap(result[size(s) / 2 + i], result[size(s) / 2 + i + l]);
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
        volatile auto result = sol.makeAntiPalindrome(nums);

        // Print result to prevent optimization
        cout << "fun_YujIDn1LsvSFsq3V: Executed makeAntiPalindrome() from Make String Anti Palindrome" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_YujIDn1LsvSFsq3V: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
