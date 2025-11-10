#include "fun_D9ErNpABed8UW3BD.hpp"

int fun_D9ErNpABed8UW3BD() {
    // LeetCode Problem: Unique 3 Digit Even Numbers

    // Solution class
    class Solution {

    public:
        int totalNumbers(vector<int>& digits) {
            vector<int> cnt(10);
            for (const auto& x : digits) {
                ++cnt[x];
            }
            int odd = 0, even = 0;
            for (int i = 0; i < size(cnt); ++i) {
                if (cnt[i] == 0) {
                    continue;
                }
                if (i % 2) {
                    ++odd;
                } else {
                    ++even;
                }
            }

            int result = 0;
            // 3 same digits
            for (int i = 2; i < size(cnt); i += 2) {
                if (cnt[i] >= 3) {
                    ++result;  // eee
                }
            }
            // 3 distinct digits
            result += even * (odd + even - 1) * (odd + even - 2);  // xye
            if (cnt[0]) {
                result -= 1 * (even - 1) * (odd + even - 2);  // 0xe
            }
            // 2 same digits, 1 different digit
            for (int i = 0; i < size(cnt); ++i) {
                if (cnt[i] < 2) {
                    continue;
                }
                if (i == 0) {
                    result += (odd + even) - 1;  // x00
                } else if (i % 2) {
                    result += even;  // ooe
                } else {
                    result += 3 * (even - 1) - (cnt[0] != 0 ? 1 : 0);  // eeE, eEe, Eee excluding 0ee
                    result += 2 * odd;  // eoe, oee
                }
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
        volatile auto result = sol.totalNumbers(nums);

        // Print result to prevent optimization
        cout << "fun_D9ErNpABed8UW3BD: Executed totalNumbers() from Unique 3 Digit Even Numbers" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_D9ErNpABed8UW3BD: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
