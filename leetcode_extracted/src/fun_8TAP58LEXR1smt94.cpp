#include "fun_8TAP58LEXR1smt94.hpp"

int fun_8TAP58LEXR1smt94() {
    // LeetCode Problem: Determine If Two Strings Are Close

    // Solution class
    class Solution {

    public:
        bool closeStrings(string word1, string word2) {
            if (size(word1) != size(word2)) {
                return false;
            }
            vector<int> cnt1(26), cnt2(26);
            for (const auto& c : word1) {
                ++cnt1[c - 'a'];
            }
            for (const auto& c : word2) {
                ++cnt2[c - 'a'];
            }
            unordered_map<int, int> diff;
            for (int i = 0; i < size(cnt1); ++i) {
                if (!cnt1[i] && !cnt2[i]) {
                    continue;
                }
                if (!cnt1[i] || !cnt2[i]) {
                    return false;
                }
                ++diff[cnt1[i]];
                --diff[cnt2[i]];
            }
            return all_of(cbegin(diff), cend(diff),
                          [](const auto& kvp) {
                              return kvp.second == 0;
                          });
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.closeStrings(nums);

        // Print result to prevent optimization
        cout << "fun_8TAP58LEXR1smt94: Executed closeStrings() from Determine If Two Strings Are Close" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_8TAP58LEXR1smt94: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
