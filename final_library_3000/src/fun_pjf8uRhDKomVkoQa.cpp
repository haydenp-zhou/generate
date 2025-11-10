#include "fun_pjf8uRhDKomVkoQa.hpp"

int fun_pjf8uRhDKomVkoQa() {
    // LeetCode Problem: Maximum Number Of Events That Can Be Attended

    // Solution class
    class Solution {

    public:
        int maxEvents(vector<vector<int>>& events) {
            sort(events.begin(), events.end(), greater<vector<int>>());
            const auto max_day = (*max_element(events.cbegin(), events.cend(),
                                               [](const auto& a, const auto& b) {
                                                   return a[1] < b[1];
                                               }))[1];
            priority_queue<int, vector<int>, greater<int>> min_heap;
            int result = 0;
            for (int d = 1; d <= max_day; ++d) {
                while (!events.empty() && events.back()[0] == d) {
                    min_heap.emplace(events.back()[1]);
                    events.pop_back();
                }
                while (!min_heap.empty() && min_heap.top() == d - 1) {
                    min_heap.pop();
                }
                if (min_heap.empty()) {
                    continue;
                }
                min_heap.pop();
                ++result;
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
        volatile auto result = sol.maxEvents(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_pjf8uRhDKomVkoQa: Executed maxEvents() from Maximum Number Of Events That Can Be Attended" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_pjf8uRhDKomVkoQa: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
