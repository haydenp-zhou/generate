#include "fun_fxy7yelz0UGlxqHE.hpp"

int fun_fxy7yelz0UGlxqHE() {
    // LeetCode Problem: Meeting Scheduler

    // Solution class
    class Solution {

    public:
        vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
            vector<pair<int, int>> min_heap;
            for (const auto& slot : slots1) {
                if (slot[1] - slot[0] >= duration) {
                    min_heap.emplace_back(slot[0], slot[1]);
                }
            }
            for (const auto& slot : slots2) {
                if (slot[1] - slot[0] >= duration) {
                    min_heap.emplace_back(slot[0], slot[1]);
                }
            }
            make_heap(min_heap.begin(), min_heap.end(), greater<>());  // Time: O(n)
            while (min_heap.size() > 1) {
                pop_heap(min_heap.begin(), min_heap.end(), greater<>());  // Time: O(logn)
                const auto left = min_heap.back();
                min_heap.pop_back();
                pop_heap(min_heap.begin(), min_heap.end(), greater<>());
                const auto right = min_heap.back();
                min_heap.pop_back();
                min_heap.emplace_back(right);
                push_heap(min_heap.begin(), min_heap.end(), greater<>());
                if (left.second - right.first >= duration) {
                    return {right.first, right.first + duration
    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.minAvailableDuration(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_fxy7yelz0UGlxqHE: Executed minAvailableDuration() from Meeting Scheduler" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_fxy7yelz0UGlxqHE: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
