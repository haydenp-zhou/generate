#include "fun_JvlL6zsIRlQqnbLm.hpp"

int fun_JvlL6zsIRlQqnbLm() {
    // LeetCode Problem: Evaluate Reverse Polish Notation

    // Solution class
    class Solution {

    public:
        int evalRPN(vector<string>& tokens) {
            if (tokens.empty()) {
                return 0;
            }
            stack<string> s;
            for (const auto& tok : tokens) {
                if (!is_operator(tok)) {
                    s.emplace(tok);
                } else {
                    auto&& y = stoi(s.top());
                    s.pop();
                    auto&& x = stoi(s.top());
                    s.pop();
                    if (tok[0] == '+') {
                        x += y;
                    } else if (tok[0] == '-') {
                        x -= y;
                    } else if (tok[0] == '*') {
                        x *= y;
                    } else {
                        x /= y;
                    }
                    s.emplace(to_string(x));
                }
            }
            return stoi(s.top());
        }

    private:
        bool is_operator(const string& op) {
            return op.length() == 1 && string("+-*/").find(op) != string::npos;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.evalRPN(strs);

        // Print result to prevent optimization
        cout << "fun_JvlL6zsIRlQqnbLm: Executed evalRPN() from Evaluate Reverse Polish Notation" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_JvlL6zsIRlQqnbLm: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
