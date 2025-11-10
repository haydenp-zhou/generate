#include "fun_BPDQb0DJ2WhOn2Hr.hpp"

int fun_BPDQb0DJ2WhOn2Hr() {
    // LeetCode Problem: Spiral Matrix

    // Solution class
    class Solution {

    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int>res;
            int left = 0, top = 0, down = matrix.size()-1, right = matrix[0].size()-1;

            while(left <= right && top <= down){            
                //From left to right on top side
                for(int i = left; i <= right; i++)
                    res.push_back(matrix[top][i]);
                top++;
                //From top to down on right side
                for(int i = top; i <= down; i++)
                    res.push_back(matrix[i][right]);
                right--;
                if(top <= down){
                //From right to left on down side
                    for(int i = right; i >= left; i--)
                        res.push_back(matrix[down][i]);
                    down--;
                }
                if(left <= right){
                //From down to top on left side
                    for(int i = down; i >= top; i--)
                        res.push_back(matrix[i][left]);
                    left++;
                }
            }
            return res;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.spiralOrder(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_BPDQb0DJ2WhOn2Hr: Executed spiralOrder() from Spiral Matrix" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_BPDQb0DJ2WhOn2Hr: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
