#include "fun_XoeUKNclk2bQrovz.hpp"

int fun_XoeUKNclk2bQrovz() {
    // LeetCode Problem: Single Threaded Cpu

    // Solution class
    class Solution {

    public:
        vector<int> getOrder(vector<vector<int>>& tasks) {
            vector<int> result, idx(tasks.size());
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
            iota(begin(idx), end(idx), 0);
            sort(begin(idx), end(idx), [&](int i, int j) { return tasks[i][0] < tasks[j][0]; });
            for (int64_t i = 0, time = tasks[idx[i]][0]; i < size(idx) || !empty(min_heap);) {
                for (; i < size(idx) && tasks[idx[i]][0] <= time; ++i) {
                    min_heap.emplace(tasks[idx[i]][1], idx[i]);
                }
                if (empty(min_heap)) {
                    time = tasks[idx[i]][0];
                    continue;
                }
                const auto [t, j] = min_heap.top(); min_heap.pop();
                time += t;
                result.emplace_back(j);
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
        volatile auto result = sol.getOrder(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_XoeUKNclk2bQrovz: Executed getOrder() from Single Threaded Cpu" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_XoeUKNclk2bQrovz: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
