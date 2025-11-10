#include "fun_SWqKSy4aejAFjNxa.hpp"

int fun_SWqKSy4aejAFjNxa() {
    // LeetCode Problem: Number Of Orders In The Backlog

    // Solution class
    class Solution {

    public:
        int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
            static const int MOD = 1e9 + 7;

            priority_queue<vector<int>> buy;  // max_heap
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> sell;  // min_heap
            for (const auto& o : orders) {
                if (o[2] == 0) {
                    buy.emplace(o);
                } else {
                    sell.emplace(o);
                }
                while (!empty(buy) && !empty(sell) && sell.top()[0] <= buy.top()[0]) {
                    int k = min(buy.top()[1], sell.top()[1]);
                    auto tmp = buy.top(); buy.pop();
                    tmp[1] -= k;
                    if (tmp[1]) {
                        buy.emplace(tmp);
                    }
                    tmp = sell.top(); sell.pop();
                    tmp[1] -= k;
                    if (tmp[1]) {
                        sell.emplace(tmp);
                    }
                }

            }
            int result = 0;
            while (!empty(buy)) {
                result = (result + buy.top()[1]) % MOD; buy.pop();
            }
            while (!empty(sell)) {
                result = (result + sell.top()[1]) % MOD; sell.pop();
            }
            return result;
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
        volatile auto result = sol.getNumberOfBacklogOrders(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_SWqKSy4aejAFjNxa: Executed getNumberOfBacklogOrders() from Number Of Orders In The Backlog" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_SWqKSy4aejAFjNxa: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
