#include "fun_6b2mcUzIdJKUGd40.hpp"

int fun_6b2mcUzIdJKUGd40() {
    // LeetCode Problem: Prime Arrangements

    // Solution class
    class Solution {

    public:    
        int numPrimeArrangements(int n) {
            int cnt = count_primes(n);
            return static_cast<uint64_t>(factorial(cnt)) * factorial(n - cnt) % MOD;
        }

    private:
        int count_primes(int n) {
            if (n <= 1) {
                return 0;
            }
            vector<bool> is_primes((n + 1) / 2, true);
            int cnt = is_primes.size();
            for (int i = 3; i * i <= n; i += 2) {
                if (!is_primes[i / 2]) {
                    continue;
                }
                for (int j = i * i; j <= n; j += 2 * i) {
                    if (!is_primes[j / 2]) {
                        continue;
                    }
                    --cnt;
                    is_primes[j / 2] = false;
                }
            }
            return cnt;
        }

        int factorial(int n) {
            int result = 1ull;
            for (int i = 2; i <= n; ++i) {
                result = (static_cast<uint64_t>(result) * i) % MOD;
            }
            return result;
        }

        static const int MOD = 1e9 + 7;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.numPrimeArrangements();

        // Print result to prevent optimization
        cout << "fun_6b2mcUzIdJKUGd40: Executed numPrimeArrangements() from Prime Arrangements" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_6b2mcUzIdJKUGd40: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
