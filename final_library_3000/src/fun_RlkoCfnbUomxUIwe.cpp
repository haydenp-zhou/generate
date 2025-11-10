#include "fun_RlkoCfnbUomxUIwe.hpp"

int fun_RlkoCfnbUomxUIwe() {
    // LeetCode Problem: Word Pattern

    // Solution class
    class Solution {


    private::

        vector<string> split(string str, char delimiter) {
            vector<string> internal;
            stringstream ss(str); // Turn the string into a stream.
            string tok;

            while(getline(ss, tok, delimiter)) {
                internal.push_back(tok);
            }

            return internal;
        }

    public:

        bool wordPattern(string pattern, string str) {
            unordered_map<char, string> dict_pattern;
            unordered_map<string, char> dict_string;

            int len = pattern.size();
            vector<string> strs = split(str, ' ');

            if (len != strs.size()) return false;

            for(int i=0; i<len; i++) {
                char& ch = pattern[i];
                string& s = strs[i];

                if ( dict_pattern.find(ch) == dict_pattern.end() ) {
                    dict_pattern[ch] = s;
                }

                if ( dict_string.find(s) == dict_string.end() ) {
                    dict_string[s] = ch;
                }

                if ( dict_pattern[ch] != s || dict_string[s] != ch ) {
                    return false;
                }

            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.wordPattern(strs);

        // Print result to prevent optimization
        cout << "fun_RlkoCfnbUomxUIwe: Executed wordPattern() from Word Pattern" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_RlkoCfnbUomxUIwe: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
