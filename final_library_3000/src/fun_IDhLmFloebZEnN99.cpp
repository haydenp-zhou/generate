#include "fun_IDhLmFloebZEnN99.hpp"

int fun_IDhLmFloebZEnN99() {
    // LeetCode Problem: Rearrange Spaces Between Words

    // Solution class
    class Solution {

    public:
        string reorderSpaces(string text) {
            // count spaces and words
            int space_count = 0, word_count = 0;
            for (int i = 0; i < size(text); ++i) {
                if (text[i] == ' ') {
                    ++space_count;
                } else if (i == 0 || text[i - 1] == ' ') {
                    ++word_count;
                }
            }
            // rearrange the spaces to the right
            int left = 0, curr = 0;
            for (int i = 0; i < size(text); ++i) {
                bool has_word = false;
                while (i < size(text) && text[i] != ' ') {
                    swap(text[left++], text[i++]);
                    has_word = true;
                }
                if (has_word) {
                    ++left;  // keep one space
                }
            }
            // rearrange the spaces to the left
            int equal_count = word_count - 1 > 0 ? space_count / (word_count - 1) : 0;
            int extra_count = word_count - 1 > 0 ? space_count % (word_count - 1) : space_count;
            int right = size(text) - 1 - extra_count;
            for (int i = size(text) - 1; i >= 0; --i) {
                bool has_word = false;
                while (i >= 0 && text[i] != ' ') {
                    swap(text[right--], text[i--]);
                    has_word = true;
                }
                if (has_word) {
                    right -= equal_count;  // keep equal_count spaces
                }
            }
            return text;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.reorderSpaces(s);

        // Print result to prevent optimization
        cout << "fun_IDhLmFloebZEnN99: Executed reorderSpaces() from Rearrange Spaces Between Words" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_IDhLmFloebZEnN99: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
