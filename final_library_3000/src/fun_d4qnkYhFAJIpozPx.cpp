#include "fun_d4qnkYhFAJIpozPx.hpp"

int fun_d4qnkYhFAJIpozPx() {
    // LeetCode Problem: Meeting Rooms Iii

    // Solution class
    class Solution {

    public:
        int mostBooked(int n, vector<vector<int>>& meetings) {
            sort(begin(meetings), end(meetings));
            vector<pair<int64_t, int>> rooms(n, {meetings[0][0], -1});
            int i = 0;
            for (auto& room : rooms) {
                room.second = i++;
            }
            priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> min_heap(cbegin(rooms), cend(rooms));
            vector<int> result(n);
            for (const auto& m : meetings) {
                const int s = m[0], e = m[1];
                while (!empty(min_heap) && min_heap.top().first < s) {
                    const auto [_, i] = min_heap.top(); min_heap.pop();
                    min_heap.emplace(s, i);
                }
                const auto [e2, i] = min_heap.top(); min_heap.pop();
                min_heap.emplace(e2 + (e - s), i);
                ++result[i];
            }
            return distance(cbegin(result), max_element(cbegin(result), cend(result)));
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
        volatile auto result = sol.mostBooked(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_d4qnkYhFAJIpozPx: Executed mostBooked() from Meeting Rooms Iii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_d4qnkYhFAJIpozPx: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
