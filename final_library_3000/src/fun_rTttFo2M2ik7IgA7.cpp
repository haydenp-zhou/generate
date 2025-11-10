#include "fun_rTttFo2M2ik7IgA7.hpp"

int fun_rTttFo2M2ik7IgA7() {
    // LeetCode Problem: Minimum Time To Visit All Houses

    // Solution class
    class Solution {

    public:
        long long minTotalTime(vector<int>& forward, vector<int>& backward, vector<int>& queries) {
            vector<int64_t> prefix1((2 * size(forward) - 1) + 1);
            for (int i = 0; i < 2 * size(forward) - 1; ++i) {
                prefix1[i + 1] = prefix1[i] + forward[i % size(forward)];
            }
            vector<int64_t> prefix2((2 * size(backward) - 1) + 1);
            for (int i = 0; i < 2 * size(backward) - 1; ++i) {
                prefix2[i + 1] = prefix2[i] + backward[i % size(backward)];
            }
            int64_t result = 0;
            int prev = 0;
            for (const auto& q : queries) {
                if (prev > q) {
                    result += min(prefix1[q + size(forward)] - prefix1[prev], prefix2[prev + 1] - prefix2[q + 1]);
                } else {
                    result += min(prefix1[q] - prefix1[prev], prefix2[prev + size(forward) + 1] - prefix2[q + 1]);
                }
                prev = q;
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
        volatile auto result = sol.minTotalTime(nums);

        // Print result to prevent optimization
        cout << "fun_rTttFo2M2ik7IgA7: Executed minTotalTime() from Minimum Time To Visit All Houses" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_rTttFo2M2ik7IgA7: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
