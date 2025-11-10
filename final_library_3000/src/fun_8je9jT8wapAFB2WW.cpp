#include "fun_8je9jT8wapAFB2WW.hpp"

int fun_8je9jT8wapAFB2WW() {
    // LeetCode Problem: Smallest Subsequence Of Distinct Characters

    // Solution class
    class Solution {

    public:
        string smallestSubsequence(string text) {
            const int k = 26;
            vector<int> count(k);
            for (const auto& c : text) {
                ++count[c - 'a'];
            }

            vector<bool> lookup(k);
            string stk;
            for (const auto& c : text) {
                if (!lookup[c - 'a']) {
                    while (!stk.empty() && stk.back() > c &&
                           count[stk.back() - 'a']) {
                        lookup[stk.back() - 'a'] = false;
                        stk.pop_back();
                    }
                    stk.push_back(c);
                    lookup[c - 'a'] = true;
                }
                --count[c - 'a'];
            }
            return stk; 
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
        volatile auto result = sol.smallestSubsequence(nums);

        // Print result to prevent optimization
        cout << "fun_8je9jT8wapAFB2WW: Executed smallestSubsequence() from Smallest Subsequence Of Distinct Characters" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_8je9jT8wapAFB2WW: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
