#include "fun_2Ir9Wv9lCGg9F8l2.hpp"

int fun_2Ir9Wv9lCGg9F8l2() {
    // LeetCode Problem: Remove Duplicate Letters

    // Solution class
    class Solution {

    public:
        string removeDuplicateLetters(string s) {
            const int k = 26;
            vector<int> remaining(k);
            for (const auto& c : s) {
                ++remaining[c - 'a'];
            }

            vector<bool> in_stack(k);
            string stk;
            for (const auto& c : s) {
                if (!in_stack[c - 'a']) {
                    while (!stk.empty() && stk.back() > c && remaining[stk.back() - 'a']) {
                        in_stack[stk.back() - 'a'] = false;
                        stk.pop_back();
                    }
                    stk.push_back(c);
                    in_stack[c - 'a'] = true;
                }
                --remaining[c - 'a'];
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
        volatile auto result = sol.removeDuplicateLetters(nums);

        // Print result to prevent optimization
        cout << "fun_2Ir9Wv9lCGg9F8l2: Executed removeDuplicateLetters() from Remove Duplicate Letters" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_2Ir9Wv9lCGg9F8l2: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
