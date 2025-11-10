#include "fun_xlObv6OVG2MKV6AE.hpp"

int fun_xlObv6OVG2MKV6AE() {
    // LeetCode Problem: Largest Merge Of Two Strings

    // Solution class
    class Solution {

    private:
        bool string_cmp(string& s1, int p1, string& s2, int p2) {
            for (; p1 < s1.size() && p2 < s2.size() ; p1++, p2++) {
                if (s1[p1] == s2[p2]) continue;
                return s1[p1] > s2[p2];
            }
            return (s1.size() - p1 >  s2.size() - p2);
        }
    public:
        string largestMerge(string word1, string word2) {
            int p1 = 0, p2 = 0;
            int len1 = word1.size(), len2 = word2.size();
            string merge(len1+len2, '\0');
            int p = 0;

            while (p1 < len1 && p2 < len2) {
                if ( string_cmp(word1, p1, word2, p2) ){ // take char from `word1`
                    merge[p++] = word1[p1++];
                }else{ //take char from `word2`
                    merge[p++] = word2[p2++];
                }
            }

            while (p1 < len1) merge[p++] = word1[p1++];
            while (p2 < len2) merge[p++] = word2[p2++];

            return merge;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.largestMerge(s);

        // Print result to prevent optimization
        cout << "fun_xlObv6OVG2MKV6AE: Executed largestMerge() from Largest Merge Of Two Strings" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_xlObv6OVG2MKV6AE: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
