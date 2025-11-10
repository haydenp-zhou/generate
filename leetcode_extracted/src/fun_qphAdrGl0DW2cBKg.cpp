#include "fun_qphAdrGl0DW2cBKg.hpp"

int fun_qphAdrGl0DW2cBKg() {
    // LeetCode Problem: Count Equal And Divisible Pairs In An Array

    // Solution class
    class Solution {

    public:
        int countPairs(vector<int>& nums, int k) {
            unordered_map<int, vector<int>> idxs;
            for (int i = 0; i < size(nums); ++i) {
                idxs[nums[i]].emplace_back(i);
            }
            int result = 0;
            for (const auto& [_, idx] : idxs) {
                unordered_map<int, int> gcds;
                for (const auto& i : idx) {
                    const int gcd_i = gcd(i, k);
                    for (const auto& [gcd_j, cnt] : gcds) {
                        if (gcd_i * gcd_j % k == 0) {
                            result += cnt;
                        }
                    }
                    ++gcds[gcd_i];
                }
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
        volatile auto result = sol.countPairs(nums);

        // Print result to prevent optimization
        cout << "fun_qphAdrGl0DW2cBKg: Executed countPairs() from Count Equal And Divisible Pairs In An Array" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_qphAdrGl0DW2cBKg: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
