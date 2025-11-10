#include "fun_zFHvjjVe4U7EPEjb.hpp"

int fun_zFHvjjVe4U7EPEjb() {
    // LeetCode Problem: Word Pattern Ii

    // Solution class
    class Solution {

    public:
        bool wordPatternMatch(string pattern, string str) {
            unordered_map<string, char> w2p;
            unordered_map<char, string> p2w;
            return match(pattern, str, 0, 0, &w2p, &p2w);
        }

        bool match(const string &pattern, const string &str,
                   const int i, const int j,
                   unordered_map<string, char>* w2p,
                   unordered_map<char, string>* p2w) {

            bool is_match = false;
            if (i == pattern.length() && j == str.length()) {
                is_match = true;
            } else if (i < pattern.length() && j < str.length()) {
                const char p = pattern[i];
                if (p2w->count(p)) {
                    const auto& w = (*p2w)[p];
                    if (w == str.substr(j, w.length())) {  // Match pattern.
                        is_match = match(pattern, str, i + 1, j + w.length(), w2p, p2w);
                    }  // Else return false.
                } else {
                    for (int k = j; k < str.length() && !is_match; ++k) {
                        const string w = str.substr(j, k - j + 1);
                        if (!w2p->count(w)) {
                            // Build mapping. Space: O(n + c)
                            (*w2p)[w] = p, (*p2w)[p] = w;
                            is_match = match(pattern, str, i + 1, k + 1, w2p, p2w);
                            w2p->erase(w), p2w->erase(p);
                        }  // Else try longer word.
                    }
                }
            }
            return is_match;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.wordPatternMatch(s);

        // Print result to prevent optimization
        cout << "fun_zFHvjjVe4U7EPEjb: Executed wordPatternMatch() from Word Pattern Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_zFHvjjVe4U7EPEjb: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
