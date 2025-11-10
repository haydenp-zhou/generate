#include "fun_IPCVxG027XcDAxqe.hpp"

int fun_IPCVxG027XcDAxqe() {
    // LeetCode Problem: Find And Replace Pattern

    // Solution class
    class Solution {

    public:
        vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
            vector<string> result;
            for (const auto& word: words) {
                if (match(word, pattern)) {
                    result.emplace_back(word);
                }
            }
            return result;
        }

    private:
        bool match(const string& word, const string& pattern) {
            unordered_map<char, char> lookup;
            unordered_set<char> char_set;
            for (int i = 0; i < word.length(); ++i) {
                const auto& c = word[i], &p = pattern[i];
                if (!lookup.count(c)) {
                    if (char_set.count(p)) {
                        return false;
                    }
                    char_set.emplace(p);
                    lookup[c] = p;
                }
                if (lookup[c] != p) {
                    return false;
                }
            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.findAndReplacePattern(strs);

        // Print result to prevent optimization
        cout << "fun_IPCVxG027XcDAxqe: Executed findAndReplacePattern() from Find And Replace Pattern" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_IPCVxG027XcDAxqe: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
