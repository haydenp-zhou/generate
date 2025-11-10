#include "fun_rt6MFCfxy73gD8Si.hpp"

int fun_rt6MFCfxy73gD8Si() {
    // LeetCode Problem: Find The Maximum Number Of Elements In Subset

    // Solution class
    class Solution {

    public:
        int maximumLength(vector<int>& nums) {
            unordered_map<int64_t, int> cnt;
            for (const auto& x : nums) {
                ++cnt[x];
            }
            unordered_map<int64_t, int> dp;
            int result = 0;
            for (const auto& k_v : cnt) {
                int64_t x = k_v.first;
                if (x == 1) {
                    result = max(result, cnt[x] - (cnt[x] % 2 == 0 ? 1 : 0));
                    continue;
                }
                vector<int> stk;
                for (; !dp.count(x) && cnt.count(x) && cnt[x] >= 2; x *= x) {
                    stk.emplace_back(x);
                }
                if (!dp.count(x)) {
                    if (!cnt.count(x)) {
                        x = stk.back(); stk.pop_back();
                    }
                    dp[x] = 1;
                }
                int l = dp[x];
                while (!empty(stk)) {
                    l += 2;
                    dp[stk.back()] = l; stk.pop_back();
                }
                result = max(result, l);
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
        volatile auto result = sol.maximumLength(nums);

        // Print result to prevent optimization
        cout << "fun_rt6MFCfxy73gD8Si: Executed maximumLength() from Find The Maximum Number Of Elements In Subset" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_rt6MFCfxy73gD8Si: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
