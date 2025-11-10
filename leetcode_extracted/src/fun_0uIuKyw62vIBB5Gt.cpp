#include "fun_0uIuKyw62vIBB5Gt.hpp"

int fun_0uIuKyw62vIBB5Gt() {
    // LeetCode Problem: Process String With Special Operations I

    // Solution class
    class Solution {

    public:
        string processStr(string s) {
            deque<char> dq;
            bool right = true;
            for (const auto& x : s) {
                if (x == '*') {
                    if (empty(dq)) {
                        continue;
                    }
                    if (right) {
                        dq.pop_back();
                    } else {
                        dq.pop_front();
                    }
                } else if (x == '#') {
                    const int l = size(dq);
                    for (int i = 0; i < l; ++i) {
                        dq.emplace_back(dq[i]);
                    }
                } else if (x == '%') {
                    right = !right;
                } else {
                    if (right) {
                        dq.emplace_back(x);
                    } else {
                        dq.emplace_front(x);
                    }
                }
            }
            if (!right) {
                reverse(begin(dq), end(dq));
            }
            return string(cbegin(dq), cend(dq));
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.processStr(s);

        // Print result to prevent optimization
        cout << "fun_0uIuKyw62vIBB5Gt: Executed processStr() from Process String With Special Operations I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_0uIuKyw62vIBB5Gt: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
