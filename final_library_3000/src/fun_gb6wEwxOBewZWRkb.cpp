#include "fun_gb6wEwxOBewZWRkb.hpp"

int fun_gb6wEwxOBewZWRkb() {
    // LeetCode Problem: Reformat The String

    // Solution class
    class Solution {

    public:
        string reformat(string s) {
            unordered_map<char, int> count;
            int alpha_cnt = 0;
            for (const auto& c : s) {
                ++count[c];
                if (isalpha(c)) {
                    ++alpha_cnt;
                }
            }
            if (abs(int(s.length()) - 2 * alpha_cnt) > 1) {
                return "";
            }

            char a = 'a', a_end = 'z';
            char b = '0', b_end = '9';
            if (alpha_cnt < s.length() - alpha_cnt) {
                swap(a, b);
                swap(a_end, b_end);
            }
            string result;
            while (result.length() < s.length()) {
                result.push_back(a = next_char(a, a_end, &count));
                result.push_back(b = next_char(b, b_end, &count));
            }
            if (result.back() == '\0') {
                result.pop_back();
            }
            return result;
        }

    private:
        char next_char(char start, char end, unordered_map<char, int> *count) {
            for (char c = start; c <= end; ++c) {
                if ((*count)[c]) {
                    --(*count)[c];
                    return c;
                }
            }
            return '\0';
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.reformat(s);

        // Print result to prevent optimization
        cout << "fun_gb6wEwxOBewZWRkb: Executed reformat() from Reformat The String" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_gb6wEwxOBewZWRkb: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
