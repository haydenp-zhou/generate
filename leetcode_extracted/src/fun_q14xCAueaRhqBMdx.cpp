#include "fun_q14xCAueaRhqBMdx.hpp"

int fun_q14xCAueaRhqBMdx() {
    // LeetCode Problem: Course Schedule

    // Solution class
    class Solution {

    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            unordered_map<int, vector<int>> adj;
            unordered_map<int, int> in_degree;
            for (const auto& p : prerequisites) {
                ++in_degree[p[0]];
                adj[p[1]].emplace_back(p[0]);
            }
            queue<int> q;
            for (int i = 0; i < numCourses; ++i) {
                if (!in_degree.count(i)) {
                    q.emplace(i);
                }
            }
            vector<int> result;
            while (!q.empty()) {
                const auto node = q.front(); q.pop();
                result.emplace_back(node);
                for (const auto& i : adj[node]) {
                    if (!--in_degree[i]) {
                        q.emplace(i);
                    }
                }
            }
            return size(result) == numCourses;
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
        volatile auto result = sol.canFinish(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_q14xCAueaRhqBMdx: Executed canFinish() from Course Schedule" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_q14xCAueaRhqBMdx: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
