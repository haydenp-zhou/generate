#include "fun_v2m0C2zEw9q0dHKm.hpp"

int fun_v2m0C2zEw9q0dHKm() {
    // LeetCode Problem: Restore The Array From Adjacent Pairs

    // Solution class
    class Solution {

    public:
        vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
            // only two numbers have one neighbour
            // start from one of them to travel all number.

            unordered_map<int, vector<int>> dict;
            for(auto& pair : adjacentPairs) {
                dict[pair[0]].push_back(pair[1]);
                dict[pair[1]].push_back(pair[0]);
            }

            int end[2]; int i=0;
            for (auto& [key, pair] : dict) {
                if(pair.size()==1) end[i++] = key;
                if (i>1) break;
            }
            //cout << "start=" << end[0] <<", end=" << end[1] << endl;
            vector<int> result(1, end[0]);
            int start = end[0];
            int prev = -1;
            while ( start != end[1] ) {
                auto& v = dict[start];
                for(int i= 0; i< v.size(); i++) {
                    if (v[i] == prev) continue;
                    result.push_back(v[i]);
                    prev = start;
                    start = v[i];
                    break;
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
        volatile auto result = sol.restoreArray(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_v2m0C2zEw9q0dHKm: Executed restoreArray() from Restore The Array From Adjacent Pairs" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_v2m0C2zEw9q0dHKm: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
