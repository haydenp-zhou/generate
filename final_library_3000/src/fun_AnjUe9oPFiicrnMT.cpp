#include "fun_AnjUe9oPFiicrnMT.hpp"

int fun_AnjUe9oPFiicrnMT() {
    // LeetCode Problem: Search2 D Matrix. I I

    // Solution class
    class Solution {

    public:

        bool binary_search(vector<int> &v, int target) {
            int low = 0;
            int high = v.size()-1;
            while(low <= high) {
                int mid = low + (high - low)/2;
                if (target == v[mid]) return true;
                if (target < v[mid]) {
                    high = mid -1;
                }else {
                    low = mid + 1;
                }
            }

            return false;
        }

        //using binary_search() to search each rows - slow O(n*log(n))
        //the run time is around 140ms for all test case
        bool searchMatrix01(vector<vector<int>>& matrix, int target) {
            if (matrix.size() == 0 || matrix[0].size()==0) return false;
            for (int i=0; i<matrix.size(); i++){
                if (target < matrix[i][0] ) return false;
                if (binary_search(matrix[i], target))  return true;

            }
            return false;
        }


        //start the liner search from top right corner of matrix. - O(m+n)
        //the run time is around 64ms
        bool searchMatrix02(vector<vector<int>>& matrix, int target) {
            if (matrix.size() == 0 || matrix[0].size()==0) return false;
            int row=0,  col = matrix[0].size() - 1; 
            while (row < matrix.size() && col >=0 ) {
                if (target == matrix[row][col]) return true;
                if (target < matrix[row][col]) {
                    col--;
                }else{
                    row++;
                }

            }
            return false;
        }

        //a bit optimization for methed 2 - the run time is 68ms
        bool searchMatrix021(vector<vector<int>>& matrix, int target) {
            if (matrix.size() == 0 || matrix[0].size()==0) return false;
            int row=0,  col = matrix[0].size() - 1; 
            while (row < matrix.size() && col >=0 ) {
                if (target == matrix[row][col]) return true;
                while ( col>=0 && target < matrix[row][col]) {
                    col--;
                }
                while(col >=0 && row < matrix.size() && target > matrix[row][col]){
                    row++;
                }

            }
            return false;
        }

        //Optimization: using binary search methed to move `low` and `row` 
        //However, the run time is 112ms
        bool searchMatrix022(vector<vector<int>>& matrix, int target) {
            if (matrix.size() == 0 || matrix[0].size()==0) return false;

            int row=0,  col = matrix[0].size() - 1; 

            while (row < matrix.size() && col >=0 ) {

                if (target == matrix[row][col]) return true;

                if (target < matrix[row][col]) {
                    int start=0, end=col;
                    while(start <= end){
                        int mid = start + (end - start)/2;
                        if (target == matrix[row][mid]) return true;
                        if (target > matrix[row][mid]) {
                            start = mid + 1;
                        }else {
                            end = mid - 1;
                        }
                    }
                    col = end; 
                }else{
                    int start=row, end=matrix.size()-1;
                    while(start<=end){
                        int mid = start + (end - start)/2;
                        if (target == matrix[mid][col]) return true;
                        if (target > matrix[mid][col]) {
                            start = mid + 1;
                        }else{
                            end = mid -1;
                        }
                    }
                    row = start;
                }

            }
            return false;
        }


        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            return searchMatrix022(matrix, target); //112ms
            return searchMatrix021(matrix, target); //68ms
            return searchMatrix02(matrix, target); //64ms
            return searchMatrix01(matrix, target); //148ms
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
        volatile auto result = sol.binary_search(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_AnjUe9oPFiicrnMT: Executed binary_search() from Search2 D Matrix. I I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_AnjUe9oPFiicrnMT: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
