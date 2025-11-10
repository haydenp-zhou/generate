#include "fun_TbY48JxmfmjRCnO1.hpp"

int fun_TbY48JxmfmjRCnO1() {
    // LeetCode Problem: Strong Password Checker

    // Solution class
    class Solution {

    public:
        int strongPasswordChecker(string s) {
            int missing_type_cnt = 3;
            missing_type_cnt -= static_cast<int>(any_of(s.begin(), s.end(), [](char c){ return isdigit(c); }));
            missing_type_cnt -= static_cast<int>(any_of(s.begin(), s.end(), [](char c){ return isupper(c); }));
            missing_type_cnt -= static_cast<int>(any_of(s.begin(), s.end(), [](char c){ return islower(c); }));

            int total_change_cnt = 0;
            int one_change_cnt = 0, two_change_cnt = 0, three_change_cnt = 0;
            for (int i = 2; i < s.length();) {
                if (s[i] == s[i - 1] && s[i - 1] == s[i - 2]) {
                    int length = 2;
                    while (i < s.length() && s[i] == s[i - 1]) {
                        ++length;
                        ++i;
                    }
                    total_change_cnt += length / 3;
                    if (length % 3 == 0) {
                        ++one_change_cnt;
                    } else if (length % 3 == 1) {
                        ++two_change_cnt;
                    } else {
                        ++three_change_cnt;
                    }
                } else {
                    ++i;
                }
            }

            if (s.length() < 6) {
                return max(missing_type_cnt, 6 - static_cast<int>(s.length()));
            } else if (s.length() <= 20) {
                return max(missing_type_cnt, total_change_cnt);
            }

            int delete_cnt = s.length() - 20;

            total_change_cnt -= min(delete_cnt, one_change_cnt) / 1;
            total_change_cnt -= min(max(delete_cnt - one_change_cnt, 0), two_change_cnt * 2) / 2;
            total_change_cnt -= min(max(delete_cnt - one_change_cnt - 2 * two_change_cnt, 0), three_change_cnt * 3) / 3;

            return delete_cnt + max(missing_type_cnt, total_change_cnt);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.strongPasswordChecker(s);

        // Print result to prevent optimization
        cout << "fun_TbY48JxmfmjRCnO1: Executed strongPasswordChecker() from Strong Password Checker" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_TbY48JxmfmjRCnO1: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
