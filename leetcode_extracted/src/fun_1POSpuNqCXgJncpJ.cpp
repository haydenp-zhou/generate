#include "fun_1POSpuNqCXgJncpJ.hpp"

int fun_1POSpuNqCXgJncpJ() {
    // LeetCode Problem: Minimum Deletions For At Most K Distinct Characters

    // Solution class
    class Solution {

    public:
        int minDeletion(string s, int k) {
            vector<int> cnt(26);
            for (const auto& x : s) {
                ++cnt[x - 'a'];
            }
            vector<int> cnt2(ranges::max(cnt) + 1);
            for (const auto& x : cnt) {
                ++cnt2[x];
            }
            int result = 0;
            for (int i = 0, total = 26 - k; i < size(cnt2); ++i) {
                const int c = min(cnt2[i], total);
                result += i * c;
                total -= c;
                if (total == 0) {
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
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minDeletion(nums);

        // Print result to prevent optimization
        cout << "fun_1POSpuNqCXgJncpJ: Executed minDeletion() from Minimum Deletions For At Most K Distinct Characters" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_1POSpuNqCXgJncpJ: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
