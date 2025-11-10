#include "fun_Jt1LqDL1eNO7FGdS.hpp"

int fun_Jt1LqDL1eNO7FGdS() {
    // LeetCode Problem: Parallel Courses

    // Solution class
    class Solution {

    public:
        int minimumSemesters(int N, vector<vector<int>>& relations) {
            unordered_map<int, vector<int>> g;
            vector<int> in_degree(N);
            for (const auto& r : relations) {
                g[r[0] - 1].emplace_back(r[1] - 1);          
                ++in_degree[r[1] - 1];
            }
            queue<pair<int, int>> q;
            for (int i = 0; i < N; ++i) {
                if (!in_degree[i]) {
                    q.emplace(1, i);
                }
            }

            int result = 0;
            int count = N;
            while (!q.empty()) {
                int level, u;
                tie(level, u) = q.front(); q.pop();
                --count;
                result = level;
                for (const auto& v : g[u]) {
                    --in_degree[v];
                    if (!in_degree[v]) {
                        q.emplace(level+1, v);
                    }
                }
            }
            return count == 0 ? result : -1;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.minimumSemesters(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_Jt1LqDL1eNO7FGdS: Executed minimumSemesters() from Parallel Courses" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Jt1LqDL1eNO7FGdS: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
