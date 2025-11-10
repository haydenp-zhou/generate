#include "fun_CaklTMVJhQ8uQtAN.hpp"

int fun_CaklTMVJhQ8uQtAN() {
    // LeetCode Problem: Split Two Strings To Make Palindrome

    // Solution class
    class Solution {

    public:
        bool checkPalindromeFormation(string a, string b) {
            return check(a, b) || check(b, a);
        }

    private:
        bool isPalindrome(const string &s, int i, int j) {
            for (; i < j; ++i, --j) {
                if (s[i] != s[j]) {
                    return false;
                }
            }
            return true;
        }

        bool check(const string &a, const string &b) {
            for (int i = 0, j = size(b) - 1; i < j; ++i, --j) {
                if (a[i] != b[j]) {
                    return isPalindrome(a, i, j) || isPalindrome(b, i, j);
                }
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
        volatile auto result = sol.checkPalindromeFormation(s);

        // Print result to prevent optimization
        cout << "fun_CaklTMVJhQ8uQtAN: Executed checkPalindromeFormation() from Split Two Strings To Make Palindrome" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_CaklTMVJhQ8uQtAN: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
