#include "fun_DW6rUx37mVTZ4TRU.hpp"

int fun_DW6rUx37mVTZ4TRU() {
    // LeetCode Problem: Walls And Gates

    // Solution class
    class Solution {

    public:
        void wallsAndGates(vector<vector<int>>& rooms) {
            const int INF = numeric_limits<int>::max();
            queue<pair<int, int>> q;
            for (int i = 0; i < rooms.size(); ++i) {
                for (int j = 0; j < rooms[0].size(); ++j) {
                    if (rooms[i][j] == 0) {
                        q.emplace(i, j);
                    }
                }
            }
            while (!q.empty()) {
                int i, j;
                tie(i, j) = q.front();
                q.pop();
                for (const pair<int, int>& d :
                     vector<pair<int, int>>{{i + 1, j}, {i - 1, j},
                                            {i, j + 1}, {i, j - 1}}) {
                    int I, J;
                    tie(I, J) = d;
                    if (I >= 0 && I < rooms.size() &&
                        J >= 0 && J < rooms[0].size() &&
                        rooms[I][J] == INF) {
                        rooms[I][J] = rooms[i][j] + 1;
                        q.emplace(I, J);
                    }
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
        volatile auto result = sol.wallsAndGates(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_DW6rUx37mVTZ4TRU: Executed wallsAndGates() from Walls And Gates" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_DW6rUx37mVTZ4TRU: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
