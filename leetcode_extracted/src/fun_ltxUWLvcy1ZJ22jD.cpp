#include "fun_ltxUWLvcy1ZJ22jD.hpp"

int fun_ltxUWLvcy1ZJ22jD() {
    // LeetCode Problem: Distribute Repeating Integers

    // Solution class
    class Solution {

    public:
        bool canDistribute(vector<int>& nums, vector<int>& quantity) {
            unordered_map<int, int> count;
            for(int i = 0; i < size(nums); ++i) {
                ++count[nums[i]];
            }
            int total = (1 << size(quantity)) - 1;
            vector<int> requirement(total + 1);
            for (int mask = 0; mask < size(requirement); ++mask) {  // Time: O(2^m)
                for (int i = 0; i < size(quantity); ++i) {  // Time: O(m)
                    if (mask & (1 << i)) {
                        requirement[mask] += quantity[i];
                    }
                }
            }
            vector<vector<int>> dp(2, vector<int>(total + 1));
            dp[0][0] = 1;
            int i = 0;
            vector<int> cnts;
            for (const auto& [_, cnt] : count) {
                cnts.emplace_back(cnt);
            }
            if (size(quantity) < size(cnts)) {  // at most use top m cnts
                nth_element(begin(cnts), begin(cnts) + size(quantity) - 1, end(cnts), greater<int>());
                cnts.resize(size(quantity));
            }
            for (int i = 0; i < size(cnts); ++i) {  // Time: O(m)
                dp[(i + 1) % 2] = vector<int>(total + 1);
                // submask enumeration:
                // => sum(nCr(m, k) * 2^k for k in xrange(m+1)) = (1 + 2)^m = 3^m
                // => Time: O(3^m), see https://cp-algorithms.com/algebra/all-submasks.html
                for (int mask = total; mask >= 0; --mask) {
                    dp[(i + 1) % 2][mask] |= dp[i % 2][mask];
                    for (int submask = mask; submask > 0; submask = (submask - 1) & mask) {
                        if (requirement[submask] <= cnts[i] && dp[i % 2][mask ^ submask]) {
                            dp[(i + 1) % 2][mask] = 1;
                        }
                    }
                }
            }
            return dp[size(cnts) % 2][total];
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.canDistribute(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_ltxUWLvcy1ZJ22jD: Executed canDistribute() from Distribute Repeating Integers" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_ltxUWLvcy1ZJ22jD: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
