#include "fun_8GQ2roALiCd4CmWg.hpp"

int fun_8GQ2roALiCd4CmWg() {
    // LeetCode Problem: Longest Cycle In A Graph

    // Solution class
    class Solution {

    public:
        int longestCycle(vector<int>& edges) {
            int result = -1;
            vector<int> lookup(size(edges), -1);
            for (int i = 0, idx = 0; i < size(edges); ++i) {
                if (lookup[i] != -1) {
                    continue;
                }
                const int start = idx;
                int j = i;
                for (; j != -1; j = edges[j]) {
                    if (lookup[j] != -1) {
                        break;
                    }
                    lookup[j] = idx++;
                }
                if (j != -1 && lookup[j] >= start) {
                    result = max(result, idx - lookup[j]);
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.longestCycle(nums);

        // Print result to prevent optimization
        cout << "fun_8GQ2roALiCd4CmWg: Executed longestCycle() from Longest Cycle In A Graph" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_8GQ2roALiCd4CmWg: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
