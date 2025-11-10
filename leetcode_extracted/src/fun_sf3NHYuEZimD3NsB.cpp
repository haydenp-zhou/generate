#include "fun_sf3NHYuEZimD3NsB.hpp"

int fun_sf3NHYuEZimD3NsB() {
    // LeetCode Problem: The Number Of Good Subsets

    // Solution class
    class Solution {

    public:
        int numberOfGoodSubsets(vector<int>& nums) {
            static const int MOD = 1e9 + 7;
            const auto& primes = sieve_of_eratosthenes(*max_element(cbegin(nums), cend(nums)));
            vector<int> dp(1 << size(primes));  // dp[i] = the number of different good subsets of which the total product equals to the product of the primes in bitset i
            dp[0] = 1;
            unordered_map<int, int> cnts;
            for (const auto& x : nums) {
                ++cnts[x];
            }
            for (const auto& [x, cnt] : cnts) {
                if (x == 1 || any_of(cbegin(primes), cend(primes), [&x=x](const auto& p) { return p * p <= x && x % (p * p) == 0;} )) {  // [&x=x] is to avoid the problem that lambda function captures variables declared from structured binding
                    continue;
                }
                const uint32_t mask = to_mask(primes, x);
                for (int i = 0; i < size(dp) - 1; ++i) {
                    if (i & mask) {
                        continue;
                    }
                    dp[i | mask] = (dp[i | mask] + static_cast<uint64_t>(cnt) * dp[i]) % MOD;
                }
            }
            return powmod(2, cnts[1], MOD) * (accumulate(cbegin(dp), cend(dp), 0ull,
                                                         [](const auto& total, const auto& x) {
                                                             return (total + x) % MOD;
                                                         }) - 1) % MOD;
        }

    private:
        vector<int> sieve_of_eratosthenes(int n) {  // Time: O(n * log(logn)), Space: O(n)
            if (n < 2) {
                return {
    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.numberOfGoodSubsets(nums);

        // Print result to prevent optimization
        cout << "fun_sf3NHYuEZimD3NsB: Executed numberOfGoodSubsets() from The Number Of Good Subsets" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_sf3NHYuEZimD3NsB: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
