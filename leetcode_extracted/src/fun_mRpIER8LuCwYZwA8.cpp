#include "fun_mRpIER8LuCwYZwA8.hpp"

int fun_mRpIER8LuCwYZwA8() {
    // LeetCode Problem: Island Perimeter

    // Solution class
    class Solution {

    public:
        int edge(vector<vector<int>> &grid, int x, int y) {
            int edge = 0;

            if (x==0 || (x>0 && grid[x-1][y] == 0 ) ) edge++; //up
            if (y==0 || (y>0 && grid[x][y-1] == 0 ) ) edge++; //left
            if (x == grid.size() - 1 || 
                (x < grid.size() - 1 && grid[x+1][y] == 0)) edge++; //down
            if (y == grid[0].size() - 1 || 
                (y < grid[0].size() - 1 && grid[x][y+1] == 0)) edge++; //right

            return edge;
        }

        int islandPerimeter(vector<vector<int>>& grid) {
            int perimeter = 0;
            for(int i=0; i<grid.size(); i++) {
                for(int j=0; j<grid[0].size(); j++) {
                    if (grid[i][j] == 1) {
                        perimeter += edge (grid, i, j);
                    }
                }
            }
            return perimeter;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.edge(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_mRpIER8LuCwYZwA8: Executed edge() from Island Perimeter" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_mRpIER8LuCwYZwA8: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
