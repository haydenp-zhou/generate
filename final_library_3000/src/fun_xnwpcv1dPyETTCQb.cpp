#include "fun_xnwpcv1dPyETTCQb.hpp"

int fun_xnwpcv1dPyETTCQb() {
    // LeetCode Problem: Minimum Sideway Jumps

    // Solution class
    class Solution {

    private:
        int min (int x, int y) {
            return x < y ? x : y;
        }
        int min(int x, int y, int z) {
            return min(x, min(y,z));
        }
        void print(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();

            for(int i=0; i<m; i++) {
                for (int j=0; j<n-1; j++){
                    if (matrix[j][i] == n) {
                        cout << setw(2) << "X"<<",";
                    } else {
                        cout << setw(2) <<matrix[j][i] << ",";
                    }
                }
                cout << matrix[n-1][i] << endl;
            }
        }
    public:
        int minSideJumps(vector<int>& obstacles) {
            int n = obstacles.size();
            vector<vector<int>> dp(n, vector(3,0));
            dp[0][0] = dp[0][2] = 1;

            for(int i = 1; i < n; i++){

                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
                dp[i][2] = dp[i-1][2];
                if (obstacles[i] > 0 ) dp[i][obstacles[i]-1] = n;

                if (obstacles[i]-1 != 0 ) dp[i][0] = min(dp[i-1][0], dp[i][1]+1, dp[i][2]+1);     
                if (obstacles[i]-1 != 1 ) dp[i][1] = min(dp[i][0]+1, dp[i-1][1], dp[i][2]+1);
                if (obstacles[i]-1 != 2 ) dp[i][2] = min(dp[i][0]+1, dp[i][1]+1, dp[i-1][2]);

            }
            //print(dp);
            //cout << endl;
            return min(dp[n-1][0], dp[n-1][1], dp[n-1][2]);
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
        volatile auto result = sol.minSideJumps(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_xnwpcv1dPyETTCQb: Executed minSideJumps() from Minimum Sideway Jumps" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_xnwpcv1dPyETTCQb: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
