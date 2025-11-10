#include "fun_kyndxCR3fyGvy39z.hpp"

int fun_kyndxCR3fyGvy39z() {
    // LeetCode Problem: Check If A String Can Break Another String

    // Solution class
    class Solution {

    public:
        bool checkIfCanBreak(string s1, string s2) {
            const auto& count1 = counter(s1), &count2 = counter(s2);
            return isBreak(count1, count2) || isBreak(count2, count1);
        }

    private:
        bool isBreak(const vector<int>& count1, const const vector<int>& count2) {
            int curr1 = 0, curr2 = 0;
            for (int c = 0; c < 26; ++c) {
                curr1 += count1[c];
                curr2 += count2[c];
                if (curr1 < curr2) {
                    return false;
                }
            }
            return true;
        }

        vector<int> counter(const string& word) {
            vector<int> count(26);
            for (const auto& c : word) {
                ++count[c - 'a'];
            }
            return count;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.checkIfCanBreak(nums);

        // Print result to prevent optimization
        cout << "fun_kyndxCR3fyGvy39z: Executed checkIfCanBreak() from Check If A String Can Break Another String" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_kyndxCR3fyGvy39z: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
