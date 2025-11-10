#include "fun_VRY3C8pSnVSfGcPj.hpp"

int fun_VRY3C8pSnVSfGcPj() {
    // LeetCode Problem: Course  Schedule

    // Solution class
    class Solution {

    public:

        // helper function
        bool dfs(vector<vector<int>>& adjlist, vector<int>& visited, int i) {

            // base condition
            if(visited[i]==1) return false;
            visited[i]=1; // mark as being visited

            for(int a:adjlist[i]) {
                if(!dfs(adjlist, visited, a)) // dfs(adjlist, visited, a) == false
                    return false; 
            }

            visited[i] = 2; // mark as visited
            return true; 
        }


        bool canFinish(int numc, vector<vector<int>>& prereq) {

            // numc: numCourses
            // prereq: prerequisites

            // create adjacency list
            vector<vector<int>> adjlist(numc, vector<int>());
            for(vector<int>& p:prereq)
                adjlist[p[0]].push_back(p[1]);

            vector<int> visited(numc, 0); 
            // unvisited: 0
            // being visited: 1
            // completely visited: 2
            for(int i=0; i<numc; i++) {
                if(visited[i]==0 && !dfs(adjlist, visited, i))
                    return false;
            }

            return true;
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
        volatile auto result = sol.dfs(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_VRY3C8pSnVSfGcPj: Executed dfs() from Course  Schedule" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_VRY3C8pSnVSfGcPj: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
