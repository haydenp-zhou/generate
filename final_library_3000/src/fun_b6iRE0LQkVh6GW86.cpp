#include "fun_b6iRE0LQkVh6GW86.hpp"

int fun_b6iRE0LQkVh6GW86() {
    // LeetCode Problem: Super Palindromes

    // Solution class
    class Solution {

    public:
        int superpalindromesInRange(string L, string R) {
            const auto K = static_cast<int>(pow(10, (R.length() + 1) * 0.25));
            const int64_t l = stol(L), r = stol(R);
            int result = 0;

            // count odd length
            for (int k = 0; k < K; ++k) {
                const string s = to_string(k), rev_s(s.rbegin(), s.rend());
                int64_t v = stol(s + rev_s.substr(1));
                v *= v;
                if (v > r) {
                    break;
                }
                if (v >= l && is_palindrome(v)) {
                    ++result;
                }
            }

            // count even length
            for (int k = 0; k < K; ++k) {
                const string s = to_string(k), rev_s(s.rbegin(), s.rend());
                int64_t v = stol(s + rev_s);
                v *= v;
                if (v > r) {
                    break;
                }
                if (v >= l && is_palindrome(v)) {
                    ++result;
                }
            }

            return result;
        }

    private:
        bool is_palindrome(int64_t k) {
            const string s = to_string(k), rev_s(s.rbegin(), s.rend());
            return s == rev_s;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.superpalindromesInRange(s);

        // Print result to prevent optimization
        cout << "fun_b6iRE0LQkVh6GW86: Executed superpalindromesInRange() from Super Palindromes" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_b6iRE0LQkVh6GW86: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
