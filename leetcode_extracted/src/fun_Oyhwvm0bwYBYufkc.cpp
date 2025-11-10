#include "fun_Oyhwvm0bwYBYufkc.hpp"

int fun_Oyhwvm0bwYBYufkc() {
    // LeetCode Problem: Minimum Insertions To Balance A Parentheses String

    // Solution class
    class Solution {

    public:
        int minInsertions(string s) {
            vector<char> stack;

            int cnt = 0;
            int len = s.size();
            for (int i=0; i<len; i++) {

                if ( s[i] == '(' ) {
                    stack.push_back( s[i] );
                    continue;
                }
                // if s[i] is ')'
                if (stack.size() > 0)  {
                    stack.pop_back();
                } else {
                    cnt++; // missed the '('
                }

                // if  s[i+1] is ')', need to skip
                if ( i < len -1 && s[i+1] == ')' ) {
                    i++;
                }else{
                    cnt++; //missed the ')'
                }

            }

            // if the stack still has '(', which means need double of ')'
            return cnt + stack.size()*2;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.minInsertions(s);

        // Print result to prevent optimization
        cout << "fun_Oyhwvm0bwYBYufkc: Executed minInsertions() from Minimum Insertions To Balance A Parentheses String" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Oyhwvm0bwYBYufkc: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
