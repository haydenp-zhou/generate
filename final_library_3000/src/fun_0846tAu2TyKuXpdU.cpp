#include "fun_0846tAu2TyKuXpdU.hpp"

int fun_0846tAu2TyKuXpdU() {
    // LeetCode Problem: Find Words That Can Be Formed By Characters

    // Solution class
    class Solution {

    public:
        int countCharacters(vector<string>& words, string chars) {
            const auto& count = counter(chars);
            int result = 0;
            for (const auto& word : words) {
                if (check(word, chars, count)) {
                    result += word.length();
                }
            }
            return result;
        }

    private:
        unordered_map<char, int> counter(const string& s) {
            unordered_map<char, int> result;
            for (const auto& c : s) {
                ++result[c];
            }
            return result;
        }

        bool check(const string& word, const string& chars,
                   const unordered_map<char, int>& count) {
            if (word.length() > chars.length()) {
                return false;
            }
            unordered_map<char, int> curr_count;
            for (const auto& c : word) {
                ++curr_count[c];
                if (!count.count(c) || count.at(c) < curr_count[c]) {
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
        volatile auto result = sol.countCharacters(strs);

        // Print result to prevent optimization
        cout << "fun_0846tAu2TyKuXpdU: Executed countCharacters() from Find Words That Can Be Formed By Characters" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_0846tAu2TyKuXpdU: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
