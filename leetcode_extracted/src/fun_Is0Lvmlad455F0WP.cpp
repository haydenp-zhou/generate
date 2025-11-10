#include "fun_Is0Lvmlad455F0WP.hpp"

int fun_Is0Lvmlad455F0WP() {
    // LeetCode Problem: Number Of Integers With Popcount Depth Equal To K I

    // Solution class
    class Solution {

    public:
        long long popcountDepth(long long n, int k) {
            if (k == 0) {
                return 1;
            }
            const int l = bit_length(n);
            if (k == 1) {
                return l - 1;
            }
            const auto& count = [&](int c) {
                int64_t result = 0;
                int cnt = 0;
                for (int i = l - 1; i >= 0; --i) {
                    if (!(n & (1ll << i))) {
                        continue;
                    }
                    if (0 <= c - cnt && c - cnt <= i) {
                        result += NCR[i][c - cnt];
                    }
                    ++cnt;
                }
                if (cnt == c) {
                    ++result;
                }
                return result;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.popcountDepth(n);

        // Print result to prevent optimization
        cout << "fun_Is0Lvmlad455F0WP: Executed popcountDepth() from Number Of Integers With Popcount Depth Equal To K I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Is0Lvmlad455F0WP: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
