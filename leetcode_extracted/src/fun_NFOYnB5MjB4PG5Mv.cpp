#include "fun_NFOYnB5MjB4PG5Mv.hpp"

int fun_NFOYnB5MjB4PG5Mv() {
    // LeetCode Problem: Valid Anagram

    // Solution class
    class Solution {

    public:

        //stupid way - but easy to understand  - 76ms
        bool isAnagram01(string s, string t) {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s == t;
        }

        //using a map to count every chars in the string.
        bool isAnagram02(string s, string t) {
            int map[26] ={0} ; //only lowercase alphabets
            //memset(map, 0, sizeof(map));

            // count each char for s
            for (int i=0; i<s.size(); i++) {
                map[s[i]-'a']++;
            }
            // decrease the count for t
            for (int i=0; i<t.size(); i++) {
                map[t[i]-'a']--;
            }

            //if all alphabets is zero, then they are anagram 
            for (int i=0; i<sizeof(map)/sizeof(map[0]); i++) {
                if (map[i]!=0) return false;
            }
            return true;
        }



        bool isAnagram(string s, string t) {
            return isAnagram02(s,t); //12ms
            return isAnagram01(s,t); //76ms
        }


    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.isAnagram01(s);

        // Print result to prevent optimization
        cout << "fun_NFOYnB5MjB4PG5Mv: Executed isAnagram01() from Valid Anagram" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_NFOYnB5MjB4PG5Mv: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
