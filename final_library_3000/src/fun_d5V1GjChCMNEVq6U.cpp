#include "fun_d5V1GjChCMNEVq6U.hpp"

int fun_d5V1GjChCMNEVq6U() {
    // LeetCode Problem: Line Reflection

    // Solution class
    class Solution {

    public:
        bool isReflected(vector<pair<int, int>>& points) {
            if (points.empty()) {
                return true;
            }
            unordered_map<int, unordered_set<int>> groups_by_y;
            int left = numeric_limits<int>::max();
            int right = numeric_limits<int>::min();
            for (const auto& p : points) {
                groups_by_y[p.second].emplace(p.first);
                left = min(left, p.first);
                right = max(right, p.first);
            }
            const auto mid = left + right;
            for (const auto& kvp : groups_by_y) {
                for (const auto& x : kvp.second) {
                    if (kvp.second.count(mid - x) == 0) {
                        return false;
                    }
                }
            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.isReflected(testValue);

        // Print result to prevent optimization
        cout << "fun_d5V1GjChCMNEVq6U: Executed isReflected() from Line Reflection" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_d5V1GjChCMNEVq6U: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
