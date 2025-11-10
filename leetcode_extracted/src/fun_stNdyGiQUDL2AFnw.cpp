#include "fun_stNdyGiQUDL2AFnw.hpp"

int fun_stNdyGiQUDL2AFnw() {
    // LeetCode Problem: Maximum Total Damage With Spell Casting

    // Solution class
    class Solution {

    public:
        long long maximumTotalDamage(vector<int>& power) {
            static const int DIST = 2;

            sort(begin(power), end(power));
            deque<pair<int, int64_t>> dp;
            int64_t mx = 0;
            for (const auto& x: power) {
                if (!empty(dp) && dp.back().first == x) {
                    dp.back().second += x;
                    continue;
                }
                while (!empty(dp) && dp.front().first + DIST < x) {
                    mx = max(mx, dp.front().second);
                    dp.pop_front();
                }
                dp.emplace_back(x, mx + x);
            }
            return max_element(cbegin(dp), cend(dp), [](const auto& a, const auto& b) {
                return a.second < b.second;
            })->second;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.maximumTotalDamage(nums);

        // Print result to prevent optimization
        cout << "fun_stNdyGiQUDL2AFnw: Executed maximumTotalDamage() from Maximum Total Damage With Spell Casting" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_stNdyGiQUDL2AFnw: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
