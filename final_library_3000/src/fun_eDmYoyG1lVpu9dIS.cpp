#include "fun_eDmYoyG1lVpu9dIS.hpp"

int fun_eDmYoyG1lVpu9dIS() {
    // LeetCode Problem: Paint House Ii

    // Solution class
    class Solution {

    public:
        int minCostII(vector<vector<int>>& costs) {
            if (costs.empty()) {
                return 0;
            }

            vector<vector<int>> min_cost(2, costs[0]);

            const int n = costs.size();
            const int k = costs[0].size();
            for (int i = 1; i < n; ++i) {
                int smallest = numeric_limits<int>::max(), second_smallest = numeric_limits<int>::max();
                for (int j = 0; j < k; ++j) {
                    if (min_cost[(i - 1) % 2][j] < smallest) {
                        second_smallest = smallest;
                        smallest = min_cost[(i - 1) % 2][j];
                    } else if (min_cost[(i - 1) % 2][j] < second_smallest) {
                        second_smallest = min_cost[(i - 1) % 2][j];
                    }
                }
                for (int j = 0; j < k; ++j) {
                    const int min_j = (min_cost[(i - 1) % 2][j] != smallest) ? smallest : second_smallest;
                    min_cost[i % 2][j] = costs[i][j] + min_j;
                }
            }

            return *min_element(min_cost[(n - 1) % 2].cbegin(), min_cost[(n - 1) % 2].cend());
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minCostII(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_eDmYoyG1lVpu9dIS: Executed minCostII() from Paint House Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_eDmYoyG1lVpu9dIS: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
