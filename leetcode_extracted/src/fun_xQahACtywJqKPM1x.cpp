#include "fun_xQahACtywJqKPM1x.hpp"

int fun_xQahACtywJqKPM1x() {
    // LeetCode Problem: Maximum Performance Of A Team

    // Solution class
    class Solution {

    public:
        int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
            static const int MOD = 1e9 + 7;
            uint64_t result = 0, s_sum = 0;
            vector<pair<int, int>> engineers;
            for (int i = 0; i < speed.size(); ++i) {
                engineers.emplace_back(efficiency[i], speed[i]);
            }
            sort(engineers.begin(), engineers.end(), greater<pair<int, int>>());
            priority_queue<int, vector<int>, greater<int>> min_heap;
            for (const auto& [e, s] : engineers) {
                s_sum += s;
                min_heap.emplace(s);
                if (min_heap.size() > k) {
                    s_sum -= min_heap.top(); min_heap.pop();
                }
                result = max(result, s_sum * e);
            }
            return result % MOD;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.maxPerformance(nums);

        // Print result to prevent optimization
        cout << "fun_xQahACtywJqKPM1x: Executed maxPerformance() from Maximum Performance Of A Team" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_xQahACtywJqKPM1x: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
