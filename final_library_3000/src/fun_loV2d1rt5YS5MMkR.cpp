#include "fun_loV2d1rt5YS5MMkR.hpp"

int fun_loV2d1rt5YS5MMkR() {
    // LeetCode Problem: Parsing A Boolean Expression

    // Solution class
    class Solution {

    public:
        bool parseBoolExpr(string expression) {
            int i = 0;
            return parse(expression, &i);
        }

    private:
        bool parse(const string& expression, int *i) {
            static const string ops = "&|!";
            if (ops.find(expression[*i]) == string::npos) {
                bool result = expression[*i] == 't';
                ++(*i);
                return result;
            }
            const auto& op = expression[*i];
            *i += 2;
            vector<bool> stk;
            while (expression[*i] != ')') {
                if (expression[*i] == ',') {
                    ++(*i);
                    continue;
                }
                stk.emplace_back(parse(expression, i));
            }
            ++(*i);
            if (op == '&') {
                return all_of(stk.cbegin(), stk.cend(),
                              [](bool val) { return val; });
            }
            if (op == '|') {
                return any_of(stk.cbegin(), stk.cend(),
                              [](bool val) { return val; });
            }
            return !stk[0];
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.parseBoolExpr(s);

        // Print result to prevent optimization
        cout << "fun_loV2d1rt5YS5MMkR: Executed parseBoolExpr() from Parsing A Boolean Expression" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_loV2d1rt5YS5MMkR: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
