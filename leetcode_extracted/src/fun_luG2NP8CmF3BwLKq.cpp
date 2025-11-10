#include "fun_luG2NP8CmF3BwLKq.hpp"

int fun_luG2NP8CmF3BwLKq() {
    // LeetCode Problem: Maximum Product After K Increments

    // Solution class
    class Solution {

    public:
        int maximumProduct(vector<int>& nums, int k) {
            static const int MOD = 1e9 + 7;
            sort(begin(nums), end(nums));
            auto total = accumulate(cbegin(nums), cend(nums), 0ll);
            int i = size(nums) - 1;
            for (; i >= 0; --i) {
                if (nums[i] * static_cast<int64_t>(i + 1) - total <= k) {
                    break;
                }
                total -= nums[i];
            }
            const int q = (k + total) / (i + 1);
            const int r = (k + total) % (i + 1);
            return ((static_cast<uint64_t>(powmod(q, (i + 1) - r, MOD)) * powmod(q + 1, r, MOD) % MOD) *
                    accumulate(cbegin(nums) + i + 1, cend(nums), 1ull,
                              [=](const auto& total, const auto& x) {
                                  return total * x % MOD;
                              })) % MOD;
        }

    private:
        uint32_t powmod(uint32_t a, uint32_t b, uint32_t mod) {
            a %= mod;
            uint64_t result = 1;
            while (b) {
                if (b & 1) {
                    result = result * a % mod;
                }
                a = uint64_t(a) * a % mod;
                b >>= 1;
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.maximumProduct(nums);

        // Print result to prevent optimization
        cout << "fun_luG2NP8CmF3BwLKq: Executed maximumProduct() from Maximum Product After K Increments" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_luG2NP8CmF3BwLKq: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
