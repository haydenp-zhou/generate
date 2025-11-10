#include "fun_MExI8stiJSOfZM2b.hpp"

int fun_MExI8stiJSOfZM2b() {
    // LeetCode Problem: Unique Paths. I I I

    // Solution class
    class Solution {

    public:
        int uniquePathsIII(vector<vector<int>>& grid) {

            int path = 0;
            int startX, startY;
    	if (!findStartPoint( grid, startX, startY)) return 0;
            uniquePathsHelper(grid, startX, startY, path);
            return path;
        }

        bool findStartPoint(vector<vector<int>> &grid, int& x, int& y) {
             for(int i=0; i<grid.size(); i++) {
                for(int j=0; j<grid[0].size(); j++) {
                    if (grid[i][j] == 1) {
                        x = i; y =j;
                        return true;
                    }
                }
             }
            return false;
        }
        bool check(vector<vector<int>> &grid ) {
            for(int i=0; i<grid.size(); i++) {
                for(int j=0; j<grid[0].size(); j++) {
                    if (grid[i][j]  == 0 ) return false;
                }
            }
            return true;
        }


        void uniquePathsHelper(vector<vector<int>> &grid, int x, int y, int& path ) {

            if (x < 0 || y < 0 || x>= grid.size() || y>=grid[0].size()) return;

            if ( grid[x][y] < 0)  return;

            if ( grid[x][y] == 2) {  
                if (check(grid)) path++;
                return;
            }

            //back tracing - mark -2 means already passed.
            grid[x][y] = -2;
            uniquePathsHelper(grid, x, y-1, path); // up
            uniquePathsHelper(grid, x, y+1, path); // down
            uniquePathsHelper(grid, x+1, y, path); // right
            uniquePathsHelper(grid, x-1, y, path); // left
            grid[x][y] = 0;

        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.uniquePathsIII(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_MExI8stiJSOfZM2b: Executed uniquePathsIII() from Unique Paths. I I I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_MExI8stiJSOfZM2b: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
