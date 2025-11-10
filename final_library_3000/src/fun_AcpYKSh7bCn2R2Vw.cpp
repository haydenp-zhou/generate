#include "fun_AcpYKSh7bCn2R2Vw.hpp"

int fun_AcpYKSh7bCn2R2Vw() {
    // LeetCode Problem: Valid Palindrome Ii

    // Solution class
    class Solution {

    public:
        bool validPalindrome(string s) {
            int left = 0, right = s.length() - 1;
            while (left < right) {
                if (s[left] != s[right]) {
                    return validPalindrome(s, left, right - 1) || validPalindrome(s, left + 1, right);
                }
                ++left, --right;
            }
            return true;
        }

    private:
        bool validPalindrome(const string& s, int left, int right) {
            while (left < right) {
                if (s[left] != s[right]) {
                    return false;
                }
                ++left, --right;
            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.validPalindrome(s);

        // Print result to prevent optimization
        cout << "fun_AcpYKSh7bCn2R2Vw: Executed validPalindrome() from Valid Palindrome Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_AcpYKSh7bCn2R2Vw: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
