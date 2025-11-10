#include "fun_HetxBqQ8W2SJrpi5.hpp"

int fun_HetxBqQ8W2SJrpi5() {
    // LeetCode Problem: The Skyline Problem

    // Solution class
    class Solution {

    public:

        vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
            vector< pair<int, int> > edges;

            //put all of edge into a vector
            //set left edge as negtive, right edge as positive
            //so, when we sort the edges, 
            //  1) for same left point, the height would be descending order
            //  2) for same right point, the height would be ascending order
            int left, right, height;
            for(int i=0; i<buildings.size(); i++) {
                left   = buildings[i][0];
                right  = buildings[i][1];
                height = buildings[i][2];
                edges.push_back(make_pair(left, -height));
                edges.push_back(make_pair(right, height));
            }
            sort(edges.begin(), edges.end());

            // 1) if we meet a left edge, then we add its height into a `set`.
            //    the `set` whould sort the height automatically.
            // 2) if we meet a right edge, then we remove its height from the `set`
            //
            // So, we could get the current highest height from the `set`, if the 
            // current height is different with preivous height, then we need add
            // it into the result.
            vector< pair<int, int> > result;
            multiset<int> m;
            m.insert(0);
            int pre = 0, cur = 0;
            for (int i=0; i<edges.size(); i++){
                pair<int,int> &e = edges[i];
                if (e.second < 0) {
                    m.insert(-e.second);
                }else{
                    m.erase(m.find(e.second));
                }
                cur = *m.rbegin();
                if (cur != pre) {
                    result.push_back(make_pair(e.first, cur));
                    pre = cur;
                }
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
        volatile auto result = sol.getSkyline(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_HetxBqQ8W2SJrpi5: Executed getSkyline() from The Skyline Problem" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_HetxBqQ8W2SJrpi5: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
