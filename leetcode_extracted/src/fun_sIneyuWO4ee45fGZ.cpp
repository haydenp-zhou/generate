#include "fun_sIneyuWO4ee45fGZ.hpp"

int fun_sIneyuWO4ee45fGZ() {
    // LeetCode Problem: Check Whether Two Strings Are Almost Equivalent

    // Solution class
    class Solution {

    public:
        bool checkAlmostEquivalent(string word1, string word2) {
            static const int K = 3;

            unordered_map<char, int> cnt1;
            for (const auto& c : word1) {
                ++cnt1[c];
            }
            unordered_map<char, int> cnt2;
            for (const auto& c : word2) {
                ++cnt2[c];
            }
            for (const auto& [k, v] : cnt1) {
                if (abs(cnt2[k] - v) > K) {
                    return false;
                }
            }
            for (const auto& [k, v] : cnt2) {
                if (abs(cnt1[k] - v) > K) {
                    return false;
                }
            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.checkAlmostEquivalent(s);

        // Print result to prevent optimization
        cout << "fun_sIneyuWO4ee45fGZ: Executed checkAlmostEquivalent() from Check Whether Two Strings Are Almost Equivalent" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_sIneyuWO4ee45fGZ: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
