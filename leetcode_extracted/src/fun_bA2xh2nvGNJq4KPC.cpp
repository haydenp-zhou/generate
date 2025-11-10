#include "fun_bA2xh2nvGNJq4KPC.hpp"

int fun_bA2xh2nvGNJq4KPC() {
    // LeetCode Problem: Longest Nice Substring

    // Solution class
    class Solution {

        inline int getCharIndex(char c) {
            return  (c >='A' && c <='Z') ? c - 'A' : c - 'a';
        }
        inline int getCaseIndex(char c) {
             return (c >='A' && c <='Z') ? 1 : 0;
        }
    public:
        string longestNiceSubstring(string s) {
            vector<bitset<26>> check(2);
            int start = 0, len = 0;
            for (int i = 0; i < s.size() -1; i++){
                for (int j = i+1; j < s.size(); j++) {

                    check[0] = check[1] = 0;
                    for (int x=i; x<=j; x++){
                        int i = getCaseIndex(s[x]);
                        int j = getCharIndex(s[x]);
                        check[i][j] = true;
                    }

                    if ( (check[0] ^ check[1]) == 0 ) {
                        if ( j - i + 1 > len ){
                            start = i;
                            len = j-i+1;
                        }
                    }
                }
            }

            return s.substr(start, len);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.longestNiceSubstring(s);

        // Print result to prevent optimization
        cout << "fun_bA2xh2nvGNJq4KPC: Executed longestNiceSubstring() from Longest Nice Substring" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_bA2xh2nvGNJq4KPC: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
