#include "fun_DBkVQOdDyJkgAAnd.hpp"

int fun_DBkVQOdDyJkgAAnd() {
    // LeetCode Problem: Array Of Doubled Pairs

    // Solution class
    class Solution {

    public:
        bool canReorderDoubled(vector<int>& A) {
            unordered_map<int, int> count;
            for (const auto& x : A) {
                ++count[x];
            }
            vector<int> keys;
            for (const auto& kvp : count) {
                keys.emplace_back(kvp.first);
            }
            sort(keys.begin(), keys.end(),
                 [](int i, int j) {
                     return abs(i) < abs(j);
                 });
            for (const auto& x : keys) {
                if (count[x] > count[2 * x]) {
                    return false;
                }
                count[2 * x] -= count[x];
            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.canReorderDoubled(nums);

        // Print result to prevent optimization
        cout << "fun_DBkVQOdDyJkgAAnd: Executed canReorderDoubled() from Array Of Doubled Pairs" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_DBkVQOdDyJkgAAnd: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
