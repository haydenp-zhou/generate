#include "fun_21571UlpjbgSdRw1.hpp"

int fun_21571UlpjbgSdRw1() {
    // LeetCode Problem: Longest Substring With At Least K Repeating Characters

    // Solution class
    class Solution {

    public:
        int longestSubstring(string s, int k) {
            return longestSubstringHelper(s, k, 0, s.size());
        }

    private:
        int longestSubstringHelper(const string& s, int k, int start, int end) {
            vector<int> count(26);
            for (int i = start; i < end; ++i) {
                ++count[s[i] - 'a'];
            }

            int max_len = 0;
            for (int i = start; i < end;) {
                while (i < end && count[s[i] - 'a'] < k) {
                    ++i;
                }
                if (i == end) {
                    break;
                }

                int j = i;
                while (j < end && count[s[j] - 'a'] >= k) {
                    ++j;
                }
                if (i == start && j == end) {
                    return end - start; 
                }

                max_len = max(max_len, longestSubstringHelper(s, k, i, j));
                i = j;
            }
            return max_len;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.longestSubstring(nums);

        // Print result to prevent optimization
        cout << "fun_21571UlpjbgSdRw1: Executed longestSubstring() from Longest Substring With At Least K Repeating Characters" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_21571UlpjbgSdRw1: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
