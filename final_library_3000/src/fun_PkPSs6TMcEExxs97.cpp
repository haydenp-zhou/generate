#include "fun_PkPSs6TMcEExxs97.hpp"

int fun_PkPSs6TMcEExxs97() {
    // LeetCode Problem: Max Area Of Island

    // Solution class
    class Solution {

    public:
        int maxAreaOfIsland(vector<vector<int>>& grid) {
            int maxArea = 0;
            for (int i=0; i<grid.size(); i++) {
                for(int j=0; j<grid[0].size(); j++) {
                    if ( grid[i][j] == 1 ) {
                        int area = 0;
                        maxAreaOfIsland_DFS(grid, i, j, area);
                        maxArea = max( maxArea, area );
                    }
                }
            }
            return maxArea;
        }

        void maxAreaOfIsland_DFS( vector<vector<int>>& grid, int i, int j, int& area ) {
            if (i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] != 1 ) return;

            area++;
            grid[i][j] = -1;

            maxAreaOfIsland_DFS(grid, i-1, j, area);
            maxAreaOfIsland_DFS(grid, i+1, j, area);
            maxAreaOfIsland_DFS(grid, i, j-1, area);
            maxAreaOfIsland_DFS(grid, i, j+1, area);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.maxAreaOfIsland(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_PkPSs6TMcEExxs97: Executed maxAreaOfIsland() from Max Area Of Island" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_PkPSs6TMcEExxs97: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
