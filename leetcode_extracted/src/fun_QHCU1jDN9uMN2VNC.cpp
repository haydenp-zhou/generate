#include "fun_QHCU1jDN9uMN2VNC.hpp"

int fun_QHCU1jDN9uMN2VNC() {
    // LeetCode Problem: Minimum Falling Path Sum Ii

    // Solution class
    class Solution {

    public:
        int minFallingPathSum(vector<vector<int>>& arr) {
            for (int i = 1; i < arr.size(); ++i) {
                const auto& smallest_two = nsmallest(2, arr[i - 1]);
                for (int j = 0; j < arr[0].size(); ++j) {
                    arr[i][j] += (arr[i - 1][j] == smallest_two[0]) ? smallest_two[1] : smallest_two[0];
                }
            }
            return *min_element(arr.back().cbegin(), arr.back().cend());
        }

    private:
        vector<int> nsmallest(int k, const vector<int>& arr) {
            priority_queue<int> max_heap;
            for (const auto& x : arr) {
                max_heap.emplace(x);
                if (max_heap.size() > k) {
                    max_heap.pop();
                }
            }
            vector<int> result;
            while (!max_heap.empty()) {
                result.emplace_back(max_heap.top()); max_heap.pop();
            }
            return {result.crbegin(), result.crend()
    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minFallingPathSum(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_QHCU1jDN9uMN2VNC: Executed minFallingPathSum() from Minimum Falling Path Sum Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_QHCU1jDN9uMN2VNC: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
