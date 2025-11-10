#include "fun_jh2N0M0cQklNEna8.hpp"

int fun_jh2N0M0cQklNEna8() {
    // LeetCode Problem: Greatest Common Divisor Of Strings

    // Solution class
    class Solution {

    public:
        string gcdOfStrings(string str1, string str2) {
            if (str1.empty() || str2.empty()) {
                return "";
            }
            int c = gcd(str1.length(), str2.length());
            const auto& result = str1.substr(0, c);
            return check(str1, result) && check(str2, result) ? result : "";
        }

    private:
        bool check(const string& s, const string& common) {
            int i = 0;
            for (const auto& c : s) {
                if (c != common[i]) {
                    return false;
                }
                i = (i + 1) % common.length();
            }
            return true;
        }

        int gcd(int a, int b) {
            while (b != 0) {
                int tmp = b;
                b = a % b;
                a = tmp;
            }
            return a;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.gcdOfStrings(s);

        // Print result to prevent optimization
        cout << "fun_jh2N0M0cQklNEna8: Executed gcdOfStrings() from Greatest Common Divisor Of Strings" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_jh2N0M0cQklNEna8: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
