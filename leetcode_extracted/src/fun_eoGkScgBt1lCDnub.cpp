#include "fun_eoGkScgBt1lCDnub.hpp"

int fun_eoGkScgBt1lCDnub() {
    // LeetCode Problem: Find The Number Of Subsequences With Equal Gcd

    // Solution class
    class Solution {

    public:
        int subsequencePairCount(vector<int>& nums) {
            const int mx = ranges::max(nums);
            vector<int> cnt(mx + 1);
            for (const auto& x : nums) {
                ++cnt[x];
            }
            for (int i = 1; i <= mx; ++i) {
                for (int j = i + i; j <= mx; j += i) {
                    cnt[i] = (cnt[i] + cnt[j]) % MOD;
                }
            }
            vector<vector<int>> f(mx + 1, vector<int>(mx + 1));
            for (int g1 = 1; g1 <= mx; ++g1) {
                for (int g2 = g1; g2 <= mx; ++g2) {
                    const int l = LCM[g1][g2];
                    const int c = l < size(cnt) ? cnt[l] : 0;
                    const int c1 = cnt[g1], c2 = cnt[g2];
                    f[g1][g2] = f[g2][g1] = ((static_cast<int64_t>(POW3[c]) * POW2[(c1 - c) + (c2 - c)] - POW2[c1] - POW2[c2] + 1) % MOD + MOD) % MOD;
                }
            }
            const auto& count = [&](int g) {
                int result = 0;
                for (int i = 1; i <= mx / g; ++i) {
                    for (int j = 1; j <= mx / g; ++j) {
                        result = ((result + MU[i] * MU[j] * f[i * g][j * g]) % MOD + MOD) % MOD;
                    }
                }
                return result;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.subsequencePairCount(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_eoGkScgBt1lCDnub: Executed subsequencePairCount() from Find The Number Of Subsequences With Equal Gcd" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_eoGkScgBt1lCDnub: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
