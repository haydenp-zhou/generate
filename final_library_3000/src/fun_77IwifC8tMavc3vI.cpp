#include "fun_77IwifC8tMavc3vI.hpp"

int fun_77IwifC8tMavc3vI() {
    // LeetCode Problem: Longest Subsequence Repeated K Times

    // Solution class
    class Solution {

    public:
        string longestSubsequenceRepeatedK(string s, int k) {
            vector<int> cnts(26);
            for (const auto& c : s) {
                ++cnts[c - 'a'];
            }
            string new_s;
            for (const auto& c : s) {
                if (cnts[c - 'a'] < k) {
                    continue;
                }
                new_s.push_back(c);
            }
            string result, curr;
            backtracking(new_s, k, &curr, &cnts, &result);
            return result;
        }

    private:    
        void backtracking(const string& s, int k, string *curr, vector<int> *cnts, string *result) {
            if (!check(s, k, *curr)) {
                return;
            }
            if (size(*curr) > size(*result)) {
                *result = *curr;
            }
            for (char c = 'z'; c >= 'a'; --c) {;
                if ((*cnts)[c -'a'] < k) {
                    continue;
                }
                (*cnts)[c -'a'] -= k;
                curr->push_back(c);
                backtracking(s, k, curr, cnts, result);
                curr->pop_back();
                (*cnts)[c -'a'] += k;
            }
        }

        bool check(const string& s, int k, const string& curr) {
            if (empty(curr)) {
                return true;
            }
            int i = 0;
            for (const auto& c: s) {
                if (curr[i] != c || ++i != size(curr)) {
                    continue;
                }
                i = 0, --k;
                if (k == 0) {
                    return true;
                }
            }
            return false;
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
        volatile auto result = sol.longestSubsequenceRepeatedK(nums);

        // Print result to prevent optimization
        cout << "fun_77IwifC8tMavc3vI: Executed longestSubsequenceRepeatedK() from Longest Subsequence Repeated K Times" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_77IwifC8tMavc3vI: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
