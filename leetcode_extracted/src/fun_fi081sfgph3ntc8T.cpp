#include "fun_fi081sfgph3ntc8T.hpp"

int fun_fi081sfgph3ntc8T() {
    // LeetCode Problem: Minimum Interval To Include Each Query

    // Solution class
    class Solution {

    public:
        vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
            sort(begin(intervals), end(intervals));
            vector<pair<int, int>> sorted_queries;
            for (int i = 0; i < size(queries); ++i) {
                sorted_queries.emplace_back(queries[i], i);
            }
            sort(begin(sorted_queries), end(sorted_queries));
            using P = pair<int, int>;
            priority_queue<P, vector<P>, greater<P>> min_heap;
            int i = 0;
            vector<int> result(size(queries), -1);
            for (const auto& [q, idx] : sorted_queries) {
                for (; i != size(intervals) && intervals[i][0] <= q; ++i) {
                    min_heap.emplace(intervals[i][1] - intervals[i][0] + 1, i);
                }
                while (!empty(min_heap) && intervals[min_heap.top().second][1] < q) {
                    min_heap.pop();
                }
                result[idx] = (!empty(min_heap)) ? min_heap.top().first : -1;
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
        volatile auto result = sol.minInterval(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_fi081sfgph3ntc8T: Executed minInterval() from Minimum Interval To Include Each Query" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_fi081sfgph3ntc8T: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
