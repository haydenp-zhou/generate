#include "fun_uIpAU822AV9dd1H5.hpp"

int fun_uIpAU822AV9dd1H5() {
    // LeetCode Problem: Find All Anagrams In A String

    // Solution class
    class Solution {

    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> result;
            if (p.empty() || s.empty()) {
                return result;
            }

            vector<int> cnts(26);
            for (const auto& c : p) {
                ++cnts[c - 'a'];
            }

            for (int left = 0, right = 0; right < s.length(); ++right) {
                --cnts[s[right] - 'a'];
                while (left <= right && cnts[s[right] - 'a'] < 0) {
                    ++cnts[s[left++] - 'a'];
                }
                if (right - left + 1 == p.length()) {
                    result.emplace_back(left);
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
        volatile auto result = sol.findAnagrams(nums);

        // Print result to prevent optimization
        cout << "fun_uIpAU822AV9dd1H5: Executed findAnagrams() from Find All Anagrams In A String" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_uIpAU822AV9dd1H5: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
