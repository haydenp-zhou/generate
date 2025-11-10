#include "fun_OAbLHKciICQkudPC.hpp"

int fun_OAbLHKciICQkudPC() {
    // LeetCode Problem: Smallest Value After Replacing With Sum Of Prime Factors

    // Solution class
    class Solution {

    public:
        int smallestValue(int n) {
            while (true) {
                int curr = n, new_n =0;
                for (const auto& p : PRIMES) {
                    if (p * p > curr) {
                        continue;
                    }
                    while (curr % p == 0) {
                        curr /= p;
                        new_n += p;
                    }
                }
                if (curr > 1) {  // curr is a prime
                    new_n += curr;
                }
                if (new_n == n) {
                    break;
                }
                n = new_n;
            }
            return n;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.smallestValue(n);

        // Print result to prevent optimization
        cout << "fun_OAbLHKciICQkudPC: Executed smallestValue() from Smallest Value After Replacing With Sum Of Prime Factors" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_OAbLHKciICQkudPC: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
