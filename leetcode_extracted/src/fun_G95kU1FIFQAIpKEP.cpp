#include "fun_G95kU1FIFQAIpKEP.hpp"

int fun_G95kU1FIFQAIpKEP() {
    // LeetCode Problem: Time To Cross A Bridge

    // Solution class
    class Solution {

    public:
        int findCrossingTime(int n, int k, vector<vector<int>>& time) {
            vector<pair<int, int>> workers;
            for (int i = 0; i < k; ++i) {
                workers.emplace_back(time[i][0] + time[i][2], i);
            }
            priority_queue<pair<int, int>> left_bridge(cbegin(workers), cend(workers)), right_bridge;
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> left_ware, right_ware;
            int curr = 0;
            while (n) {
                while (!empty(left_ware) && left_ware.top().first <= curr) {
                    const auto [_, i] = left_ware.top(); left_ware.pop();
                    left_bridge.emplace(time[i][0] + time[i][2], i);
                }
                while (!empty(right_ware) && right_ware.top().first <= curr) {
                    const auto [_, i] = right_ware.top(); right_ware.pop();
                    right_bridge.emplace(time[i][0] + time[i][2], i);
                }
                if (!empty(right_bridge)) {
                    const auto [_, i] = right_bridge.top(); right_bridge.pop();
                    curr += time[i][2];
                    left_ware.emplace(curr + time[i][3], i);
                    --n;
                } else if (!empty(left_bridge) && n - size(right_ware)) {
                    const auto [_, i] = left_bridge.top(); left_bridge.pop();
                    curr += time[i][0];
                    right_ware.emplace(curr + time[i][1], i);
                } else {
                    curr = min(!empty(left_ware) ? left_ware.top().first : numeric_limits<int>::max(),
                               !empty(right_ware) ? right_ware.top().first : numeric_limits<int>::max());
                }
            }
            return curr;
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
        volatile auto result = sol.findCrossingTime(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_G95kU1FIFQAIpKEP: Executed findCrossingTime() from Time To Cross A Bridge" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_G95kU1FIFQAIpKEP: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
