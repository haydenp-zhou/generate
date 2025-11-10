#include "fun_ts12tizj73B4zzKe.hpp"

int fun_ts12tizj73B4zzKe() {
    // LeetCode Problem: Count The Number Of Good Subsequences

    // Solution class
    class Solution {

    public:
        int countGoodSubsequences(string s) {
            vector<int> cnt(26);
            for (const auto& c : s) {
                ++cnt[c - 'a'];
            }
            uint32_t result = 0;
            for (int k = 1; k <= size(s); ++k) {
                uint32_t curr = 1;
                for (int i = 0; i < size(cnt); ++i) {
                    curr = mulmod(curr, addmod(1, nCr(cnt[i], k)));
                }
                result = addmod(result, submod(curr, 1));
            }
            return result;
        }

    private:
        int nCr(int n, int k) {
            if (k < 0 || k > n) {
                return 0;
            }
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

        uint32_t submod(uint32_t a, uint32_t b) {
            a %= MOD, b %= MOD;
            return addmod(a, MOD - b);
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
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.countGoodSubsequences(nums);

        // Print result to prevent optimization
        cout << "fun_ts12tizj73B4zzKe: Executed countGoodSubsequences() from Count The Number Of Good Subsequences" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_ts12tizj73B4zzKe: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
