#include "fun_xcHpmFgBCCIBJWmO.hpp"

int fun_xcHpmFgBCCIBJWmO() {
    // LeetCode Problem: Longest Increasing Path In A Matrix

    // Solution class
    class Solution {

    public:
        int longestIncreasingPath(vector<vector<int>>& matrix) {
            int result = 0;
            int row = matrix.size();
            int col = row ? matrix[0].size() : 0;
            vector<vector<int>> path = vector<vector<int>>(row, vector<int>(col, 0));
            for (int r = 0; r < row; r++) {
                for (int c = 0; c < col; c++) {
                    result = max(result, helper(matrix, path, row, col, r, c));
                }
            }
            return result;
        }

        int helper(vector<vector<int>>& matrix, vector<vector<int>>& path, const int row, const int col, int r, int c) {

            if (path[r][c]>0) return path[r][c];

            int maxPath = 0;

            int tmp = matrix[r][c]; 
            matrix[r][c]=INT_MIN;  
            if (r < row-1 && tmp < matrix[r+1][c]) {
                maxPath = max(maxPath, helper(matrix, path, row, col, r+1, c));
            }
            if (c < col-1 && tmp < matrix[r][c+1]) {
                maxPath = max(maxPath, helper(matrix, path, row, col, r, c+1));
            }
            if (r > 0 && tmp < matrix[r-1][c]) {
                maxPath = max(maxPath, helper(matrix, path, row, col, r-1, c));
            }
            if (c > 0 && tmp < matrix[r][c-1]) {
                maxPath = max(maxPath, helper(matrix, path, row, col, r, c-1));
            }
            matrix[r][c] = tmp;
            path[r][c] = maxPath + 1;
            return path[r][c];
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.longestIncreasingPath(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_xcHpmFgBCCIBJWmO: Executed longestIncreasingPath() from Longest Increasing Path In A Matrix" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_xcHpmFgBCCIBJWmO: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
