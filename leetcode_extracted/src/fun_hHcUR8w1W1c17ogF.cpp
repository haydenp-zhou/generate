#include "fun_hHcUR8w1W1c17ogF.hpp"

int fun_hHcUR8w1W1c17ogF() {
    // LeetCode Problem: Number Of Ways To Reach A Position After Exactly K Steps

    // Solution class
    class Solution {

    public:
        int numberOfWays(int startPos, int endPos, int k) {
            const int r = k - abs(endPos - startPos);
            return r >= 0 && r % 2 == 0 ? nCr(k, r / 2) : 0;
        }

    private:
        int nCr(int n, int k) {
            while (size(inv_) <= n) {  // lazy initialization
                fact_.emplace_back(mulmod(fact_.back(), size(inv_)));
                inv_.emplace_back(mulmod(inv_[MOD % size(inv_)], MOD - MOD / size(inv_)));  // https://cp-algorithms.com/algebra/module-inverse.html
                inv_fact_.emplace_back(mulmod(inv_fact_.back(), inv_.back()));
            }
            return mulmod(mulmod(fact_[n], inv_fact_[n - k]), inv_fact_[k]);
        }

        uint32_t addmod(uint32_t a, uint32_t b) {  // avoid overflow
            a %= MOD, b %= MOD;
            if (MOD - a <= b) {
                b -= MOD;  // relied on unsigned integer overflow in order to give the expected results
            }
            return a + b;
        }

        // reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types
        uint32_t mulmod(uint32_t a, uint32_t b)  {  // avoid overflow
            a %= MOD, b %= MOD;
            uint32_t result = 0;
            if (a < b) {
                swap(a, b);
            }
            while (b > 0)  { 
                if (b % 2 == 1) {
                    result = addmod(result, a);
                }
                a = addmod(a, a);
                b /= 2; 
            } 
            return result; 
        }

        static const uint32_t MOD = 1e9 + 7;
        vector<int> fact_ = {1, 1
    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.numberOfWays(nums);

        // Print result to prevent optimization
        cout << "fun_hHcUR8w1W1c17ogF: Executed numberOfWays() from Number Of Ways To Reach A Position After Exactly K Steps" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_hHcUR8w1W1c17ogF: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
