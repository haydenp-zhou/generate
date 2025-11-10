#include "fun_2iSp5HRRdnr4F2Jx.hpp"

int fun_2iSp5HRRdnr4F2Jx() {
    // LeetCode Problem: Preimage Size Of Factorial Zeroes Function

    // Solution class
    class Solution {

    public:
        int preimageSizeFZF(int K) {
            const int p = 5;
            int left = 0, right = p * K;
            while (left <= right) {
                const int mid = left + (right - left) / 2;
                if (countOfFactorialPrimes(mid, p) >= K) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return countOfFactorialPrimes(left, p) == K ? p : 0;
        }

    private:
        int countOfFactorialPrimes(int n, int p) {
            int cnt = 0;
            for (; n > 0; n /= p) {
                cnt += n / p;
            }
            return cnt;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.preimageSizeFZF(n);

        // Print result to prevent optimization
        cout << "fun_2iSp5HRRdnr4F2Jx: Executed preimageSizeFZF() from Preimage Size Of Factorial Zeroes Function" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_2iSp5HRRdnr4F2Jx: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
