#include "fun_YQ4LMdXf4nvmSUV3.hpp"

int fun_YQ4LMdXf4nvmSUV3() {
    // LeetCode Problem: Number Of Subsequences With Odd Sum

    // Solution class
    class Solution {

    public:
        int subsequenceCount(vector<int>& nums) {
            static const int MOD = 1e9 + 7;

            // 2^(odd-1)*2^even = 2^(len(nums)-1)
            return any_of(cbegin(nums), cend(nums), [](const auto& x) {
                return x % 2 == 1;
            }) ? powmod(2, size(nums) - 1, MOD) : 0;
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

    // Execute solution
    try {
        volatile auto result = sol.subsequenceCount(nums);

        // Print result to prevent optimization
        cout << "fun_YQ4LMdXf4nvmSUV3: Executed subsequenceCount() from Number Of Subsequences With Odd Sum" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_YQ4LMdXf4nvmSUV3: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
