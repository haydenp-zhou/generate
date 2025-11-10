#include "fun_QZ97H52NuDMxiPJc.hpp"

int fun_QZ97H52NuDMxiPJc() {
    // LeetCode Problem: Count Almost Equal Pairs I

    // Solution class
    class Solution {

    public:
        int countPairs(vector<int>& nums) {
            static const int L = 7;
            vector<int> POW10(L);
            POW10[0] = 1;
            for (int i = 0; i + 1 < L; ++i) {
                POW10[i+1] = POW10[i] * 10;
            }
            unordered_map<int, int> cnt1;
            for (const auto& x : nums) {
                ++cnt1[x];
            }
            unordered_map<int, int> cnt2;
            for (const auto& [x, v] : cnt1) {
                for (int i = 0; i < L; ++i) {
                    const int a = x / POW10[i] % 10;
                    for (int j = i + 1; j < L; ++j) {
                        const int b = x /POW10[j] % 10;
                        if (a == b || !cnt1.count(x - a * (POW10[i] - POW10[j]) + b * (POW10[i] - POW10[j]))) {
                            continue;
                        }
                        cnt2[x - a * (POW10[i] - POW10[j]) + b * (POW10[i] - POW10[j])] += v;
                    }
                }
            }
            int result = 0;
            for (const auto& [_, v] : cnt1) {
                result += v * (v - 1) / 2;
            }
            int total = 0;
            for (const auto& [x, v] : cnt1) {
                total += v * cnt2[x];
            }
            return result + total / 2;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.countPairs(nums);

        // Print result to prevent optimization
        cout << "fun_QZ97H52NuDMxiPJc: Executed countPairs() from Count Almost Equal Pairs I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_QZ97H52NuDMxiPJc: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
