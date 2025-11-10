#include "fun_1BtihbTfL6iYwl3H.hpp"

int fun_1BtihbTfL6iYwl3H() {
    // LeetCode Problem: Maximum Number Of Visible Points

    // Solution class
    class Solution {

    public:
        int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
            static const double PI = atan2(0, -1);

            vector<double> arr;
            int extra = 0;
            for (const auto& p : points) {
                if (p == location) {
                    ++extra;
                    continue;
                }
                arr.emplace_back(atan2(p[1] - location[1], p[0] - location[0]));
            }
            sort(begin(arr), end(arr));
            const int n = size(arr);
            for (int i = 0; i < n; ++i) {  // make it circular
                arr.emplace_back(arr[i] + 2.0 * PI);
            }
            const double d = 2.0 * PI * (angle / 360.0);
            int result = 0;
            for (int left = 0, right = 0; right < size(arr); ++right) {
                while (arr[right] - arr[left] > d) {
                    ++left;
                }
                result = max(result, right - left + 1);
            }
            return result + extra;
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
        volatile auto result = sol.visiblePoints(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_1BtihbTfL6iYwl3H: Executed visiblePoints() from Maximum Number Of Visible Points" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_1BtihbTfL6iYwl3H: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
