#include "fun_6S7eDzh2YyjTEAw2.hpp"

int fun_6S7eDzh2YyjTEAw2() {
    // LeetCode Problem: Repeated Substring Pattern

    // Solution class
    class Solution {

    public:
        bool repeatedSubstringPattern(string str) {
            vector<int> prefix = getPrefix(str);
            return prefix.back() != -1 &&
                   (prefix.back() + 1) % (str.length() - prefix.back() - 1) == 0;
        }

    private:
        vector<int> getPrefix(const string& pattern) {
            vector<int> prefix(pattern.length(), -1);
            int j = -1;
            for (int i = 1; i < pattern.length(); ++i) {
                while (j > -1 && pattern[j + 1] != pattern[i]) {
                    j = prefix[j];
                }
                if (pattern[j + 1] == pattern[i]) {
                    ++j;
                }
                prefix[i] = j;
            }
            return prefix;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.repeatedSubstringPattern(nums);

        // Print result to prevent optimization
        cout << "fun_6S7eDzh2YyjTEAw2: Executed repeatedSubstringPattern() from Repeated Substring Pattern" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_6S7eDzh2YyjTEAw2: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
