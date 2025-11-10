#include "fun_7kibHHSzP1Ku0da6.hpp"

int fun_7kibHHSzP1Ku0da6() {
    // LeetCode Problem: Second Minimum Time To Reach Destination

    // Solution class
    class Solution {

    public:
        int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
            vector<vector<int>> adj(n);
            for (const auto& edge : edges) {
                adj[edge[0] - 1].emplace_back(edge[1] - 1);
                adj[edge[1] - 1].emplace_back(edge[0] - 1);
            }
            return calc_time(time, change, bi_bfs(adj, 0, n - 1));
        }

    private:
        // Template:
        // https://github.com/kamyu104/LeetCode-Solutions/blob/master/C++/nearest-exit-from-entrance-in-maze.cpp
        int bi_bfs(const vector<vector<int>>& adj, int start, int end) {
            unordered_set<int> left = {start}, right = {end}, lookup;
            int result = 0, steps = 0;
            while (!empty(left) && (!result || result + 2 > steps)) {  // modified
                for (const auto& u : left) {
                    lookup.emplace(u);
                }
                unordered_set<int> new_left;
                for (const auto& u : left) {
                    if (right.count(u)) {
                        if (!result) {  // modified
                            result = steps;
                        } else if (result < steps) {  // modified
                            return result + 1;
                        }
                    }
                    for (const auto& v : adj[u]) {
                        if (lookup.count(v)) {
                            continue;
                        }
                        new_left.emplace(v);
                    }
                }
                left = move(new_left);
                ++steps;
                if (size(left) > size(right)) {
                    swap(left, right);
                }
            }
            return result + 2;  // modified
        }

        int calc_time(int time, int change, int dist) {
            int result = 0;
            while (dist--) {
                if (result / change % 2) {
                    result = (result / change + 1) * change;
                }
                result += time;
            }
            return result;
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
        volatile auto result = sol.secondMinimum(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_7kibHHSzP1Ku0da6: Executed secondMinimum() from Second Minimum Time To Reach Destination" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_7kibHHSzP1Ku0da6: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
