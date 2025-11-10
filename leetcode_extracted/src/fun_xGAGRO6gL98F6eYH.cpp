#include "fun_xGAGRO6gL98F6eYH.hpp"

int fun_xGAGRO6gL98F6eYH() {
    // LeetCode Problem: Additive Number

    // Solution class
    class Solution {

    public:
        bool isAdditiveNumber(string num) {
            for (int i = 1; i < num.length(); ++i) {
                for (int j = i + 1; j < num.length(); ++j) {
                    string s1 = num.substr(0, i), s2 = num.substr(i, j - i);
                    if ((s1.length() > 1 && s1[0] == '0') ||
                        (s2.length() > 1 && s2[0] == '0')) {
                        continue;
                    }

                    string next = add(s1, s2);
                    string cur = s1 + s2 + next;
                    while (cur.length() < num.length()) {
                        s1 = s2;
                        s2 = next;
                        next = add(s1, s2);
                        cur += next;
                    }
                    if (cur == num) {
                        return true;
                    }
                }
            }
            return false;
        }

    private:
            string add(const string& m, const string& n) {
                string res;
                int res_length = max(m.length(), n.length()) ;

                int carry = 0;
                for (int i = 0; i < res_length; ++i) {
                    int m_digit_i = i < m.length() ? m[m.length() - 1 - i] - '0' : 0;
                    int n_digit_i = i < n.length() ? n[n.length() - 1 - i] - '0' : 0;
                    int sum = carry + m_digit_i + n_digit_i;
                    carry = sum / 10;
                    sum %= 10;
                    res.push_back('0' + sum);
                }
                if (carry) {
                    res.push_back('0' + carry);
                }
                reverse(res.begin(), res.end());

                return res;
            }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.isAdditiveNumber(s);

        // Print result to prevent optimization
        cout << "fun_xGAGRO6gL98F6eYH: Executed isAdditiveNumber() from Additive Number" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_xGAGRO6gL98F6eYH: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
