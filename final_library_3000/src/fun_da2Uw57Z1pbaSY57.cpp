#include "fun_da2Uw57Z1pbaSY57.hpp"

int fun_da2Uw57Z1pbaSY57() {
    // LeetCode Problem: Course Schedule

    // Solution class
    class Solution {

    public:

        bool hasCycle(int n, vector<int>& explored, vector<int>& path, map<int, vector<int>>& graph) {

            for(int i=0; i<graph[n].size(); i++){

                //detect the cycle
                if ( path[graph[n][i]] ) return true;

                //set the marker
                path[graph[n][i]] = true;

                if (hasCycle(graph[n][i], explored, path, graph)) {
                    return true;
                }
                //backtrace reset
                path[graph[n][i]] = false;
            }
            //no cycle found, mark this node can finished!
            explored[n] = true;
            return false;

        }

        bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {

            //using map to stroe the graph, it's easy to search the edge for each node
            //the bool in pair means it is explored or not
            map<int, vector<int>> graph;
            for(int i=0; i<prerequisites.size(); i++){
                graph[prerequisites[i].first].push_back( prerequisites[i].second );
            }

            //explored[] is used to record the node already checked!
            vector<int> explored(numCourses, false);

            //path[] is used to check the cycle during DFS
            vector<int> path(numCourses, false);

            for(int i=0; i<numCourses; i++){

                if (explored[i]) continue;
                if (hasCycle(i, explored, path, graph)) return false;


            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.hasCycle(nums);

        // Print result to prevent optimization
        cout << "fun_da2Uw57Z1pbaSY57: Executed hasCycle() from Course Schedule" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_da2Uw57Z1pbaSY57: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
