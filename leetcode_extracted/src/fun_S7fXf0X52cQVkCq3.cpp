#include "fun_S7fXf0X52cQVkCq3.hpp"

int fun_S7fXf0X52cQVkCq3() {
    // LeetCode Problem: Course Schedule Iv

    // Solution class
    class Solution {

    public:
        vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
            const auto& reachable = floydWarshall(n, prerequisites);
            vector<bool> result;
            for (const auto& q : queries) {
                result.emplace_back(reachable.count(q[0] * n + q[1]));
            }
            return result;
        }

    private:
        unordered_set<int> floydWarshall(int n, const vector<vector<int>>& graph) {
            unordered_set<int> reachable;
            for (const auto& connected : graph) {
                reachable.emplace(connected[0] * n + connected[1]);
            }
            for (int k = 0; k < n; ++k) {
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        if (!reachable.count(i * n + j) &&
                            (reachable.count(i * n + k) && reachable.count(k * n + j))) {
                            reachable.emplace(i * n + j);
                        }
                    }
                }
            }
            return reachable;
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
        volatile auto result = sol.checkIfPrerequisite(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_S7fXf0X52cQVkCq3: Executed checkIfPrerequisite() from Course Schedule Iv" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_S7fXf0X52cQVkCq3: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
