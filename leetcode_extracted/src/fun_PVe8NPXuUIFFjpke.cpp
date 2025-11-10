#include "fun_PVe8NPXuUIFFjpke.hpp"

int fun_PVe8NPXuUIFFjpke() {
    // LeetCode Problem: Longest Substring With At Least K Repeating Characters

    // Solution class
    class Solution {

    public:
        int longestSubstring(string s, int k) {

            //deal with edge cases
            if (s.size() == 0 || s.size() < k) return 0;
            if (k==1) return s.size();

            //declare a map for every char's counter
            int count[NO_OF_CHARS];
            memset(count , 0, sizeof(count));

            //counting every char
            for (char ch : s) {
                count[ch]++;
            }

            int i=0;
            for ( i=0; i<NO_OF_CHARS; i++) {
                if (count[i] !=0 && count[i] < k) break;
            }
            //all of the chars meet the requirement
            if ( i >= NO_OF_CHARS ) return s.size();

            // find the most infrequent char
            char least = 0;
            for (int c = 0; c < NO_OF_CHARS; c++) {
                if (count[c] == 0) continue;
                if (least == 0) {
                    least = c;
                } else if ( count[c] < count[least]) {
                    least = c;
                }
            }

            //split the string and run them recursively
            vector<string> subs;
            split(s, least, subs);

            int res = 0;
            for (string str: subs) {
                res = max(res, longestSubstring(str, k));
            }
            return res;
            return 0;
        }

    private:

        inline int max(int x, int y) { return x>y? x:y; }

        inline void split(const string &s, char delim, vector<string> &elems) {
            stringstream ss;
            ss.str(s);
            string item;
            while (getline(ss, item, delim)) {
                cout << item << endl;
                elems.push_back(item);
            }
        }


        inline vector<string> split(const string &s, char delim) {
            vector<string> elems;
            split(s, delim, elems);
            return elems;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.longestSubstring(strs);

        // Print result to prevent optimization
        cout << "fun_PVe8NPXuUIFFjpke: Executed longestSubstring() from Longest Substring With At Least K Repeating Characters" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_PVe8NPXuUIFFjpke: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
