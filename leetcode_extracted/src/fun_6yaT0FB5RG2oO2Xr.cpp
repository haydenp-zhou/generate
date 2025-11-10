#include "fun_6yaT0FB5RG2oO2Xr.hpp"

int fun_6yaT0FB5RG2oO2Xr() {
    // LeetCode Problem: Koko Eating Bananas

    // Solution class
    class Solution {

    public:
        int minEatingSpeed(vector<int>& piles, int H) {
            int left = 1, right = *max_element(piles.cbegin(), piles.cend());
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (possible(piles, H, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

    private:
        bool possible(const vector<int>& piles, int H, int K) {
            int time = 0;
            for (const auto& pile : piles) {
                time += (pile - 1) / K + 1;
            }
            return time <= H;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.minEatingSpeed(nums);

        // Print result to prevent optimization
        cout << "fun_6yaT0FB5RG2oO2Xr: Executed minEatingSpeed() from Koko Eating Bananas" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_6yaT0FB5RG2oO2Xr: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
