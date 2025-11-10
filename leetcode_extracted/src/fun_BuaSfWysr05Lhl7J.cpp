#include "fun_BuaSfWysr05Lhl7J.hpp"

int fun_BuaSfWysr05Lhl7J() {
    // LeetCode Problem: Brace Expansion

    // Solution class
    class Solution {

    public:
        vector<string> expand(string S) {  // nested is fine
            int i = 0;
            return generateWords(S, &i);
        }

    private:
        vector<string> generateWords(const string& expr, int *i) {
            vector<vector<string>> options;
            while (*i != expr.length() &&
                   string(",}").find(expr[*i]) == string::npos) {
                vector<string> tmp;
                if (string("{,}").find(expr[*i]) == string::npos) {
                    tmp.emplace_back(string(1, expr[*i]));
                    ++(*i);  // a-z
                } else if (expr[*i] == '{') {
                    tmp = generateOption(expr, i);
                }
                options.emplace_back(move(tmp));
            }
            return formWords(options);
        }

        vector<string> generateOption(const string& expr, int *i) {
            set<string> option_set;
            while (*i != expr.length() && expr[*i] != '}') {
                ++(*i);  // { or ,
                for (const auto& option : generateWords(expr, i)) {
                    option_set.emplace(option);
                }
            }
            ++(*i);  // }
            return vector<string>(option_set.cbegin(), option_set.cend());
        }

        vector<string> formWords(const vector<vector<string>>& options) {
            set<string> words_set;
            int total = 1;
            for (const auto& opt : options) {
                total *= opt.size();
            }
            for (int i = 0; i < total; ++i) {
                vector<string> tmp;
                int curr = i;
                for (int j = options.size() - 1; j >= 0; --j) {
                    tmp.emplace_back(options[j][curr % options[j].size()]);
                    curr /= options[j].size();
                }
                reverse(tmp.begin(), tmp.end());
                words_set.emplace(accumulate(tmp.cbegin(), tmp.cend(), string()));
            }
            return vector<string>(words_set.cbegin(), words_set.cend());
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.expand(strs);

        // Print result to prevent optimization
        cout << "fun_BuaSfWysr05Lhl7J: Executed expand() from Brace Expansion" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_BuaSfWysr05Lhl7J: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
