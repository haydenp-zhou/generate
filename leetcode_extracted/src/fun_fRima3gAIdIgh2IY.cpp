#include "fun_fRima3gAIdIgh2IY.hpp"

int fun_fRima3gAIdIgh2IY() {
    // LeetCode Problem: Count Substrings That Can Be Rearranged To Contain A String I

    // Solution class
    class Solution {

    public:
        long long validSubstringCount(string word1, string word2) {
            vector<int> cnt(26);
            int curr = 0;
            for (const auto& x : word2) {
                if (cnt[x - 'a']++ == 0) {
                    ++curr;
                }
            }
            int64_t result = 0;
            for (int right = 0, left = 0; right < size(word1); ++right) {
                if (--cnt[word1[right] - 'a'] == 0) {
                    --curr;
                }
                for (; !curr; ++left) {
                    result += size(word1) - right;
                    if (cnt[word1[left] - 'a']++ == 0) {
                        ++curr;
                    }
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
        volatile auto result = sol.validSubstringCount(nums);

        // Print result to prevent optimization
        cout << "fun_fRima3gAIdIgh2IY: Executed validSubstringCount() from Count Substrings That Can Be Rearranged To Contain A String I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_fRima3gAIdIgh2IY: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
