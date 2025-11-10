#include "fun_BCYyPsMPt9i033iM.hpp"

int fun_BCYyPsMPt9i033iM() {
    // LeetCode Problem: Couples Holding Hands

    // Solution class
    class Solution {

    public:
        int minSwapsCouples(vector<int>& row) {
            int N = row.size() / 2;
            vector<vector<int>> couples(N);
            for (int seat = 0; seat < row.size(); ++seat) {
                couples[row[seat] / 2].emplace_back(seat / 2);
            }
            vector<vector<int>> adj(N);
            for (const auto& couple : couples) {
                adj[couple[0]].emplace_back(couple[1]);
                adj[couple[1]].emplace_back(couple[0]);
            }

            int result = 0;
            for (int couch = 0; couch < N; ++couch) {
                if (adj[couch].empty()) {
                    continue;
                }
                int couch1 = couch;
                int couch2 = adj[couch1].back(); adj[couch1].pop_back();
                while (couch2 != couch) {
                    ++result;
                    adj[couch2].erase(find(adj[couch2].begin(), adj[couch2].end(), couch1));
                    couch1 = couch2;
                    couch2 = adj[couch1].back(); adj[couch1].pop_back();
                }
            }
            return result;  // also equals to N - (# of cycles)
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.minSwapsCouples(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_BCYyPsMPt9i033iM: Executed minSwapsCouples() from Couples Holding Hands" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_BCYyPsMPt9i033iM: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
