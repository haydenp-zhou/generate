#include "fun_6CNJnRIGPGeclKwg.hpp"

int fun_6CNJnRIGPGeclKwg() {
    // LeetCode Problem: Frog Jump

    // Solution class
    class Solution {

    public:
        bool canCross(vector<int>& stones) {
            if (stones[1] != 1) {
                return false;
            }

            unordered_map<int, unordered_set<int>> last_jump_units;
            for (const auto& s: stones) {
                last_jump_units.emplace(s, {unordered_set<int>()});
            }
            last_jump_units[1].emplace(1);

            for (int i = 0; i + 1 < stones.size(); ++i) {
                for (const auto& j : last_jump_units[stones[i]]) {
                    for (const auto& k : {j - 1, j, j + 1}) {
                        if (k > 0 && last_jump_units.count(stones[i] + k)) {
                            last_jump_units[stones[i] + k].emplace(k);
                        }
                    }
                }
            }

            return !last_jump_units[stones.back()].empty();
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.canCross(nums);

        // Print result to prevent optimization
        cout << "fun_6CNJnRIGPGeclKwg: Executed canCross() from Frog Jump" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_6CNJnRIGPGeclKwg: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
