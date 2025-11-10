#include "fun_sIuMK4zXUpaPOiou.hpp"

int fun_sIuMK4zXUpaPOiou() {
    // LeetCode Problem: Expression Add Operators

    // Solution class
    class Solution {

    public:
        vector<string> addOperators(string num, int target) {
            vector<string> result;
            vector<string> expr;
            int val = 0;
            string val_str;
            for (int i = 0; i < num.length(); ++i) {
                val = val * 10 + num[i] - '0';
                val_str.push_back(num[i]);
                // Avoid overflow and "00...".
                if (to_string(val) != val_str) {
                    break;
                }
                expr.emplace_back(val_str);
                addOperatorsDFS(num, target, i + 1, 0, val, &expr, &result);
                expr.pop_back();
            }
            return result;
        }

        void addOperatorsDFS(const string& num, const int& target, const int& pos,
                             const int& operand1, const int& operand2,
                             vector<string> *expr, vector<string> *result) {
            if (pos == num.length() && operand1 + operand2 == target) {
                result->emplace_back(join(*expr));
            } else {
                int val = 0;
                string val_str;
                for (int i = pos; i < num.length(); ++i) {
                    val = val * 10 + num[i] - '0';
                    val_str.push_back(num[i]);
                    // Avoid overflow and "00...".
                    if (to_string(val) != val_str) {
                        break;
                    }

                    // Case '+':
                    expr->emplace_back("+" + val_str);
                    addOperatorsDFS(num, target, i + 1, operand1 + operand2, val, expr, result);
                    expr->pop_back();

                    // Case '-':
                    expr->emplace_back("-" + val_str);
                    addOperatorsDFS(num, target, i + 1, operand1 + operand2, -val, expr, result);
                    expr->pop_back();

                    // Case '*':
                    expr->emplace_back("*" + val_str);
                    addOperatorsDFS(num, target, i + 1, operand1, operand2 * val, expr, result);
                    expr->pop_back();
                }
            }
        }

        string join(const vector<string>& expr) {
            ostringstream stream;
            copy(expr.cbegin(), expr.cend(), ostream_iterator<string>(stream));
            return stream.str();
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.addOperators(strs);

        // Print result to prevent optimization
        cout << "fun_sIuMK4zXUpaPOiou: Executed addOperators() from Expression Add Operators" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_sIuMK4zXUpaPOiou: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
