#include "fun_ruoAq2sconLgyLO8.hpp"

int fun_ruoAq2sconLgyLO8() {
    // LeetCode Problem: Search A 2D Matrix

    // Solution class
    class Solution {

    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            if (matrix.empty()) {
                return false;
            }

            // Treat matrix as 1D array.
            const int m = matrix.size();
            const int n = matrix[0].size();
            int left = 0;
            int right = m * n - 1;

            // Find min of left s.t.  matrix[left / n][left % n] >= target
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[mid / n][mid % n] >= target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            // Check if matrix[left / n][left % n] equals to target.
            if (left != m * n && matrix[left / n][left % n] == target) {
                return true;
            }

            return false;
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
        volatile auto result = sol.searchMatrix(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_ruoAq2sconLgyLO8: Executed searchMatrix() from Search A 2D Matrix" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_ruoAq2sconLgyLO8: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
