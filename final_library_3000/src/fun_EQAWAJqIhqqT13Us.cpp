#include "fun_EQAWAJqIhqqT13Us.hpp"

int fun_EQAWAJqIhqqT13Us() {
    // LeetCode Problem: Remove Invalid Parentheses

    // Solution class
    class Solution {

    public:
        vector<string> removeInvalidParentheses(string s)  {
            int left_removed = 0, right_removed = 0;
            findMinRemove(s, &left_removed, &right_removed);

            vector<string> res;
            vector<int> removed;
            removeInvalidParenthesesHelper(s, 0, left_removed, right_removed, &removed, &res);
            return res;
        }

    private:
        void findMinRemove(const string& s, int *left_removed, int *right_removed) {
            // Calculate the minimum left and right parantheses to remove.
            for (const auto& c : s) {
                if (c == '(') {
                    ++(*left_removed);
                } else if (c == ')') {
                    if (!(*left_removed)) {
                        ++(*right_removed);
                    } else {
                        --(*left_removed);
                    }
                }
            }
        }

        void removeInvalidParenthesesHelper(const string& s, int start,
                                      int left_removed, int right_removed,
                                      vector<int> *removed, vector<string> *res) {

            if (left_removed == 0 && right_removed == 0) { 
                string tmp;
                for (int i = 0, j = 0; i < s.length(); ++i) {
                    if (j < removed->size() && i == (*removed)[j]) {
                        ++j;
                    } else {
                        tmp.push_back(s[i]);
                    }
                }
                if (isValid(tmp)) {
                    res->emplace_back(tmp);
                }
                return;
            }

            for (int i = start; i < s.length(); ++i) {
                if (right_removed == 0 && left_removed > 0 && s[i] == '(') {
                    if (i == start || s[i] != s[i - 1]) {  // Skip duplicated.
                        removed->emplace_back(i);
                        removeInvalidParenthesesHelper(s, i + 1, left_removed - 1, right_removed,
                                                       removed, res);
                        removed->pop_back();
                    }
                } else if (right_removed > 0 && s[i] == ')') {
                    if (i == start || s[i] != s[i - 1]) {  // Skip duplicated.
                        removed->emplace_back(i);
                        removeInvalidParenthesesHelper(s, i + 1, left_removed, right_removed - 1,
                                                       removed, res);
                        removed->pop_back();
                    }
                }

            }
        }

        // Check whether s is valid or not.
        bool isValid(string s) {
            int sum = 0;
            for (const auto &c : s) {
                if (c == '(') {
                    ++sum;
                } else if (c == ')') {
                    --sum;
                }
                if (sum < 0) {
                    return false;
                }
            }
            return sum == 0;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.removeInvalidParentheses(nums);

        // Print result to prevent optimization
        cout << "fun_EQAWAJqIhqqT13Us: Executed removeInvalidParentheses() from Remove Invalid Parentheses" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_EQAWAJqIhqqT13Us: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
