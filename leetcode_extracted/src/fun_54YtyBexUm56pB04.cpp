#include "fun_54YtyBexUm56pB04.hpp"

int fun_54YtyBexUm56pB04() {
    // LeetCode Problem: Maximum Product Of The Length Of Two Palindromic Subsequences

    // Solution class
    class Solution {

    public:
        int maxProduct(string s) {
            vector<int> dp(1 << size(s));
            for (int mask = 0; mask < size(dp); ++mask) {
                dp[mask] = palindromic_subsequence_length(s, mask);
            }
            int result = 0;
            for (int mask = 0; mask < size(dp); ++mask) {
                if (dp[mask] * (size(s) - dp[mask]) <= result) {  // optimize
                    continue;
                }
                // submask enumeration:
                // => sum(nCr(n, k) * 2^k for k in xrange(n+1)) = (1 + 2)^n = 3^n
                // => Time: O(3^n), see https://cp-algorithms.com/algebra/all-submasks.html
                const int inverse_mask = (size(dp) - 1) ^ mask;
                for (int submask = inverse_mask; submask; submask = (submask - 1) & inverse_mask) {
                    result = max(result, dp[mask] * dp[submask]);
                }
            }
            return result;
        }

    private:
        int palindromic_subsequence_length(const string& s, int mask) {
            int result = 0;
            int left = 0, right = size(s) - 1;
            int left_bit = 1 << left, right_bit = 1 << right;
            while (left <= right) {
                if ((mask & left_bit) == 0) {
                    ++left, left_bit <<= 1;
                } else if ((mask & right_bit) == 0) {
                    --right, right_bit >>= 1;
                } else if (s[left] == s[right]) {
                    result += (left == right) ? 1 : 2;
                    ++left, left_bit <<= 1;
                    --right, right_bit >>= 1;
                } else {
                    return 0;
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

    // Execute solution
    try {
        volatile auto result = sol.maxProduct(nums);

        // Print result to prevent optimization
        cout << "fun_54YtyBexUm56pB04: Executed maxProduct() from Maximum Product Of The Length Of Two Palindromic Subsequences" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_54YtyBexUm56pB04: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
