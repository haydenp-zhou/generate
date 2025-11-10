#include "fun_U2AZ2Es9TeyRkidf.hpp"

int fun_U2AZ2Es9TeyRkidf() {
    // LeetCode Problem: Set Matrix Zeroes

    // Solution class
    class Solution {

    public:
        Solution(){
            srand(time(NULL));
        }
        void setZeroes(vector<vector<int> > &matrix) {
            if(random()%2){
                setZeroes1(matrix);
            }
            setZeroes2(matrix);
        }

        void setZeroes1(vector<vector<int> > &matrix) {

            int bRow = false, bCol=false;

            for (int r=0; r<matrix.size(); r++){
                for(int c=0; c<matrix[r].size(); c++){
                    if (matrix[r][c]==0){
                        if (r==0) bRow = true;
                        if (c==0) bCol = true;
                        matrix[0][c] = matrix[r][0] = 0;
                    }
                }
            }

            for (int r=1; r<matrix.size(); r++){
                for(int c=1; c<matrix[r].size(); c++){
                    if (matrix[0][c]==0 || matrix[r][0]==0) {
                        matrix[r][c]=0;
                    }
                }
            }
            if (bRow){
                for(int c=0; c<matrix[0].size(); c++) matrix[0][c] = 0;
            }
            if (bCol){
                for(int r=0; r<matrix.size(); r++) matrix[r][0] = 0;
            }

        }

        void setZeroes2(vector<vector<int> > &matrix) {

            bool *row = new bool[matrix.size()]();
            bool *col = new bool[matrix[0].size()]();
            for (int r=0; r<matrix.size(); r++){
                for(int c=0; c<matrix[r].size(); c++){
                    if (matrix[r][c]==0){
                        row[r]=true;
                        col[c]=true;
                    }
                }
            }

            for (int r=0; r<matrix.size(); r++){
                for(int c=0; c<matrix[r].size(); c++){
                    if (row[r] || col[c]) {
                        matrix[r][c]=0;
                    }
                }
            }
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.Solution(nums);

        // Print result to prevent optimization
        cout << "fun_U2AZ2Es9TeyRkidf: Executed Solution() from Set Matrix Zeroes" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_U2AZ2Es9TeyRkidf: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
