#include "fun_2Dts6qtsmKyEA9Ma.hpp"

int fun_2Dts6qtsmKyEA9Ma() {
    // LeetCode Problem: The Kth Factor Of N

    // Solution class
    class Solution {

    public:
        int kthFactor(int n, int k) {
            const auto& [mid, count] = kthFactor_(n);
            int total = 2 * count - (mid * mid == n);
            if (k > total) {
                return -1;
            }
            int result = kthFactor_(n, (k <= count) ? k : total - (k - 1)).first;
            return (k <= count) ? result : n / result;
        }

    private:
        pair<int, int> kthFactor_(int n, int k = 0) {
            int mid = -1;
            for (int i = 1; i * i <= n; ++i) {
                if (n % i) {
                    continue;
                }
                mid = i;
                if (!--k) {
                    break;
                }
            }
            return {mid, -k
    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.kthFactor(n);

        // Print result to prevent optimization
        cout << "fun_2Dts6qtsmKyEA9Ma: Executed kthFactor() from The Kth Factor Of N" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_2Dts6qtsmKyEA9Ma: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
