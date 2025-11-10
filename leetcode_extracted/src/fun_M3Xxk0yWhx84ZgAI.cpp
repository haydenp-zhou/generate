#include "fun_M3Xxk0yWhx84ZgAI.hpp"

int fun_M3Xxk0yWhx84ZgAI() {
    // LeetCode Problem: Generalized Abbreviation

    // Solution class
    class Solution {

    public:
        vector<string> generateAbbreviations(string word) {
            vector<string> res;
            string cur;
            generateAbbreviationsHelper(word, 0, &cur, &res);
            return res;
        }

        void generateAbbreviationsHelper(const string& word, int i, string *cur, vector<string> *res) {
            if (i == word.length()) {
                res->emplace_back(*cur);
                return;
            }
            cur->push_back(word[i]);
            generateAbbreviationsHelper(word, i + 1, cur, res);
            cur->pop_back();
            if (cur->empty() || not isdigit(cur->back())) {
                for (int l = 1; i + l <= word.length(); ++l) {
                    cur->append(to_string(l));
                    generateAbbreviationsHelper(word, i + l, cur, res);
                    cur->resize(cur->length() - to_string(l).length());
                }
            }
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.generateAbbreviations(strs);

        // Print result to prevent optimization
        cout << "fun_M3Xxk0yWhx84ZgAI: Executed generateAbbreviations() from Generalized Abbreviation" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_M3Xxk0yWhx84ZgAI: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
