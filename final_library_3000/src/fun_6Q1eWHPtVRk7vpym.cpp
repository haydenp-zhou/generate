#include "fun_6Q1eWHPtVRk7vpym.hpp"

int fun_6Q1eWHPtVRk7vpym() {
    // LeetCode Problem: Search2 D Matrix

    // Solution class
    class Solution {

    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            return searchMatrix01(matrix, target);
            return searchMatrix02(matrix, target);
        }

        //Just simply convert the 2D matrix to 1D array.
        bool searchMatrix01(vector<vector<int>>& matrix, int target) {
            int row = matrix.size();
            int col = row>0 ? matrix[0].size() : 0;

            int len = row * col;
            int low = 0, high = len -1;
            while (low <= high) {

                int mid = low + (high - low) / 2;
                int r = mid / col;
                int c = mid % col;

                int n = matrix[r][c];
                if (n == target) return true;
                if (n < target) low = mid+1;
                else high = mid -1;
            }
            return false;
        }



        bool searchMatrix02(vector<vector<int> > &matrix, int target) {

            int idx = vertical_binary_search(matrix, target);
            if (idx<0){
                return false;
            }

            idx = binary_search(matrix[idx], target);

            return (idx < 0 ? false : true);

        }
        int vertical_binary_search(vector< vector<int> > v, int key){
            int low = 0;
            int high = v.size()-1;
            while(low <= high){
                int mid = low + (high-low)/2;
                if (v[mid][0] == key){
                    return mid;
                }
                if (key < v[mid][0]){
                    high = mid - 1;
                    continue;
                }
                if (key > v[mid][0]){
                    low = mid + 1;
                    continue;
                }
            }
            return low-1;        
        }

        int binary_search(vector<int> v, int key) {
            int low = 0;
            int high = v.size()-1;
            while(low <= high){
                int mid = low + (high-low)/2;
                if (v[mid] == key){
                    return mid;
                }
                if (key < v[mid]){
                    high = mid - 1;
                    continue;
                }
                if (key > v[mid]){
                    low = mid + 1;
                    continue;
                }
            }
            return -1;
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
        cout << "fun_6Q1eWHPtVRk7vpym: Executed searchMatrix() from Search2 D Matrix" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_6Q1eWHPtVRk7vpym: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
