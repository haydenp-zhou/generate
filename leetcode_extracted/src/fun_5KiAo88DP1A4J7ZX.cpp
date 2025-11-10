#include "fun_5KiAo88DP1A4J7ZX.hpp"

int fun_5KiAo88DP1A4J7ZX() {
    // LeetCode Problem: One Edit Distance

    // Solution class
    class Solution {

    public:
        bool isOneEditDistance(string s, string t) {
            const int m = s.length(), n = t.length();
            if (m > n) {
                return isOneEditDistance(t, s);
            }
            if (n - m > 1) {
                return false;
            }

            int i = 0, shift = n - m;
            while (i < m && s[i] == t[i]) {
                ++i;
            }
            if (shift == 0) {
                ++i;
            }
            while (i < m && s[i] == t[i + shift]) {
                ++i;
            }

            return i == m;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.isOneEditDistance(s);

        // Print result to prevent optimization
        cout << "fun_5KiAo88DP1A4J7ZX: Executed isOneEditDistance() from One Edit Distance" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_5KiAo88DP1A4J7ZX: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
