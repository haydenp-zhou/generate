#include "fun_ZZmgC8d0L4rvrgzL.hpp"

int fun_ZZmgC8d0L4rvrgzL() {
    // LeetCode Problem: Sum Of Digits Of String After Convert

    // Solution class
    class Solution {

    public:
        int sumChar(char c) {
            int x = c - 'a' + 1;
            return x < 10 ? x : x / 10 + x % 10;
        }
        int sumInt(int x) {
            int s = 0;
            while( x > 0 ) {
                s += x % 10;
                x /= 10;
            }
            return s;
        }
        int getLucky(string s, int k) {
            int result = 0;
            for (auto c : s) {
                result += sumChar(c);
            }
            for (; k > 1 ; k--) {
                result = sumInt(result);
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.sumChar(s);

        // Print result to prevent optimization
        cout << "fun_ZZmgC8d0L4rvrgzL: Executed sumChar() from Sum Of Digits Of String After Convert" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_ZZmgC8d0L4rvrgzL: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
