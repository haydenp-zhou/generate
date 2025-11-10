#include "fun_DCuTgtKkHcFSPDQw.hpp"

int fun_DCuTgtKkHcFSPDQw() {
    // LeetCode Problem: Find Numbers With Even Number Of Digits

    // Solution class
    class Solution {

    public:
        Solution() {
            static const int M = 1e5;
            lookup_.emplace_back(0);
            int i = 10;
            for (; i < M; i *= 10) {
                lookup_.emplace_back(i);
            }
            lookup_.emplace_back(i);
        }

        int findNumbers(vector<int>& nums) {
            return accumulate(nums.cbegin(), nums.cend(), 0,
                              [this](const auto& x, const auto& y) {
                                  return x + int(digit_count(y) % 2 == 0);
                              });
        }

    private:
        int digit_count(int n) {
            return distance(lookup_.cbegin(),
                            upper_bound(lookup_.cbegin(), lookup_.cend(), n));
        }

        vector<int> lookup_;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.Solution(nums);

        // Print result to prevent optimization
        cout << "fun_DCuTgtKkHcFSPDQw: Executed Solution() from Find Numbers With Even Number Of Digits" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_DCuTgtKkHcFSPDQw: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
