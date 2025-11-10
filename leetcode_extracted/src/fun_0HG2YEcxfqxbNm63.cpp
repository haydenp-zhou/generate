#include "fun_0HG2YEcxfqxbNm63.hpp"

int fun_0HG2YEcxfqxbNm63() {
    // LeetCode Problem: Queries On Number Of Points Inside A Circle

    // Solution class
    class Solution {

    private:
        //refer to: https://stackoverflow.com/a/7227057/13139221
        bool inCircle( vector<int>& point,  vector<int>& circle ) {
            int x = point[0], y = point[1];
            int xo = circle[0], yo = circle[1], r = circle[2];

            int dx = abs(x-xo);
            if ( dx > r ) return false;
            int dy = abs(y-yo);
            if ( dy > r ) return false;
            if ( dx + dy <= r ) return true;
            return ( dx*dx + dy*dy <= r*r );
        }
    public:
        vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
            vector<int> result;
            for(auto& c : queries) {
                int cnt = 0;
                for(auto& p : points) {
                    if ( inCircle(p, c) ) cnt++;
                }
                result.push_back(cnt);
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.countPoints(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_0HG2YEcxfqxbNm63: Executed countPoints() from Queries On Number Of Points Inside A Circle" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_0HG2YEcxfqxbNm63: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
