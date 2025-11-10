#include "fun_ImKPrCdydPNy5eti.hpp"

int fun_ImKPrCdydPNy5eti() {
    // LeetCode Problem: Find Players With Zero Or One Losses

    // Solution class
    class Solution {

    public:
        vector<vector<int>> findWinners(vector<vector<int>>& matches) {
            unordered_map<int, int> lose;
            unordered_set<int> players_set;
            for (const auto& x : matches) {
                ++lose[x[1]];
                players_set.emplace(x[0]);
                players_set.emplace(x[1]);
            }
            vector<int> players(cbegin(players_set), cend(players_set));
            sort(begin(players), end(players));
            vector<vector<int>> result(2);
            for (const auto& x: players) {
                for (int i = 0; i < 2; ++i) {
                    if (lose[x] == i) {
                        result[i].emplace_back(x);
                    }
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.findWinners(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_ImKPrCdydPNy5eti: Executed findWinners() from Find Players With Zero Or One Losses" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_ImKPrCdydPNy5eti: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
