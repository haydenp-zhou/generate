#include "fun_sVCRnWYlz8pfpGVx.hpp"

int fun_sVCRnWYlz8pfpGVx() {
    // LeetCode Problem: First Unique Character In A String

    // Solution class
    class Solution {

    public:
        int firstUniqChar(string s) {
            //As the question mentioned, there only have lower case chars, 
            //so the MAX_CHAR can be defined as 26, but I want this algorithm be more general for all ASCII
            #define MAX_CHAR 256
            #define NOT_FOUND  -1
            #define DUPLICATION -2

            // initlize all chars status to NOT_FOUND
            int pos_map[MAX_CHAR];
            memset(pos_map, NOT_FOUND,sizeof(pos_map));

            // if it is the first time to find, set the status to its postion
            // if it is the second time to find, set the status to duplication
            // if it has already duplicated, do nothing 
            for (int i=0; i<s.size(); i++){
                if ( pos_map[s[i]] >= 0 ) {
                    pos_map[s[i]] = DUPLICATION;
                }else if ( pos_map[s[i]] == NOT_FOUND ) {
                    pos_map[s[i]] = i;
                }
            }

            // find the lowest postion
            int pos = INT_MAX;
            for (auto item : pos_map) {
                cout << item << ",";
                if (item >= 0 && item < pos) {
                    pos = item;
                }
            }
            return pos == INT_MAX ? -1 : pos;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.firstUniqChar(s);

        // Print result to prevent optimization
        cout << "fun_sVCRnWYlz8pfpGVx: Executed firstUniqChar() from First Unique Character In A String" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_sVCRnWYlz8pfpGVx: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
