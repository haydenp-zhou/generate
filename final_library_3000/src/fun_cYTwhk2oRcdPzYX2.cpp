#include "fun_cYTwhk2oRcdPzYX2.hpp"

int fun_cYTwhk2oRcdPzYX2() {
    // LeetCode Problem: Sorted Gcd Pair Queries

    // Solution class
    class Solution {

    public:
        vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
            unordered_map<int, int> cnt1;
            for (const auto& x : nums) {
                ++cnt1[x];
            }
            vector<int64_t> cnt2(ranges::max(nums) + 1);
            for (int g = size(cnt2) - 1; g >= 1; --g) {
                int64_t c = 0;
                for (int ng = g; ng < size(cnt2); ng += g) {
                    c += cnt1[ng];
                }
                cnt2[g] = c * (c - 1) / 2;
                for (int ng = g + g; ng < size(cnt2); ng += g) {
                    cnt2[g] -= cnt2[ng];
                }
            }
            vector<int64_t> prefix(size(cnt2) + 1);
            for (int i = 0; i < size(prefix) - 1; ++i) {
                prefix[i + 1] += prefix[i] + cnt2[i];
            }
            vector<int> result(size(queries));
            for (int i = 0; i < size(queries); ++i) {
                result[i] = distance(cbegin(prefix), upper_bound(cbegin(prefix), cend(prefix), queries[i])) - 1;
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
        volatile auto result = sol.gcdValues(nums);

        // Print result to prevent optimization
        cout << "fun_cYTwhk2oRcdPzYX2: Executed gcdValues() from Sorted Gcd Pair Queries" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_cYTwhk2oRcdPzYX2: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
