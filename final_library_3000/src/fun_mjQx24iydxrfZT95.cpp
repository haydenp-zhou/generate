#include "fun_mjQx24iydxrfZT95.hpp"

int fun_mjQx24iydxrfZT95() {
    // LeetCode Problem: Check If A Word Occurs As A Prefix Of Any Word In A Sentence

    // Solution class
    class Solution {

    public:
        int isPrefixOfWord(string sentence, string searchWord) {
            if (sentence.compare(0, searchWord.size(), searchWord) == 0) {
                return 1;
            }
            searchWord = " " + searchWord;
            auto p = KMP(sentence, searchWord);
            if (p == -1) {
                return -1;
            }
            return 1 + accumulate(cbegin(sentence), cbegin(sentence) + p + 1, 0,
                                  [](const auto& a, const auto& b) {
                                      return a + (b == ' ');
                                  });
        }

    private:
        int KMP(const string& text, const string& pattern) {
            const vector<int> prefix = getPrefix(pattern);
            int j = -1;
            for (int i = 0; i < text.length(); ++i) {
                while (j > -1 && pattern[j + 1] != text[i]) {
                    j = prefix[j];
                }
                if (pattern[j + 1] == text[i]) {
                    ++j;
                }
                if (j == pattern.length() - 1) {
                    return i - j;
                }
            }
            return -1;
        }

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
        volatile auto result = sol.isPrefixOfWord(nums);

        // Print result to prevent optimization
        cout << "fun_mjQx24iydxrfZT95: Executed isPrefixOfWord() from Check If A Word Occurs As A Prefix Of Any Word In A Sentence" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_mjQx24iydxrfZT95: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
