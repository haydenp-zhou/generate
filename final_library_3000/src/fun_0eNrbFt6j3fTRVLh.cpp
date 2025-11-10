#include "fun_0eNrbFt6j3fTRVLh.hpp"

int fun_0eNrbFt6j3fTRVLh() {
    // LeetCode Problem: Nth Magical Number

    // Solution class
    class Solution {

    public:
        int nthMagicalNumber(int N, int A, int B) {
            static const int M = 1000000007;
            const uint64_t a = A, b = B;
            const auto lcm = a * b / gcd(a, b);

            auto left = min(a, b), right = max(a, b) * N;
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (check(A, B, N, lcm, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left % M;
        }

    private:
        bool check(uint64_t a, uint64_t b, uint64_t N, uint64_t lcm, uint64_t target) {
            return target / a + target / b - target / lcm >= N;
        }

        uint64_t gcd(uint64_t a, uint64_t b) {
            while (b != 0) {
                int tmp = b;
                b = a % b;
                a = tmp;
            }
            return a;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.nthMagicalNumber(n);

        // Print result to prevent optimization
        cout << "fun_0eNrbFt6j3fTRVLh: Executed nthMagicalNumber() from Nth Magical Number" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_0eNrbFt6j3fTRVLh: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
