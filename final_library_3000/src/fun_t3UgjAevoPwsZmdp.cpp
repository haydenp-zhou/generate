#include "fun_t3UgjAevoPwsZmdp.hpp"

int fun_t3UgjAevoPwsZmdp() {
    // LeetCode Problem: Game Of Life

    // Solution class
    class Solution {

    public:
        // the problem here is we need store two states in one cell,
        // one is the original state, another is the new state
        // So, we could store the state into the bit.
        //  - Old State: the first  bit from the right
        //  - New State: the second bit from the right
        void liveCheck(vector<vector<int>>& board, int r, int c) {
            int cnt = 0;
            for (int i=r-1; i<=r+1; i++) {
                if (i < 0 || i>=board.size()) continue;
                for (int j=c-1; j<=c+1; j++) {
                    if (j<0 || j>=board[0].size() || (i==r && j==c)) continue;
                    if ( board[i][j] & 1 ) cnt++;
                }
            }

            //live -> die
            //if (board[r][c]==1 && (cnt < 2 || cnt > 3)) board[r][c] = 1;

            //live -> live
            if ( board[r][c] == 1 && (cnt == 2 || cnt == 3) ) board[r][c] = 3;

            //die -> live
            if ( board[r][c] == 0 && cnt == 3 ) board[r][c] = 2;

        }

        void gameOfLife(vector<vector<int>>& board) {
            for (int i=0; i<board.size(); i++) {
                for (int j=0; j<board[0].size(); j++) {
                    liveCheck(board, i, j);
                }
            }

            for (int i=0; i<board.size(); i++) {
                for (int j=0; j<board[0].size(); j++) {
                    board[i][j] >>= 1;
                }

            }

        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.liveCheck(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_t3UgjAevoPwsZmdp: Executed liveCheck() from Game Of Life" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_t3UgjAevoPwsZmdp: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
