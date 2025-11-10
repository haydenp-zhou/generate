#include "fun_hf1PRBiYceaFFfqC.hpp"

int fun_hf1PRBiYceaFFfqC() {
    // LeetCode Problem: Capacity To Ship Packages Within D Days

    // Solution class
    class Solution {

    public:
        int shipWithinDays(vector<int>& weights, int D) {    
            int left = *max_element(weights.cbegin(), weights.cend());
            int right = accumulate(weights.cbegin(), weights.cend(), 0);
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (possible(weights, D, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

    private:
        int possible(const vector<int>& weights, int D, int mid) const {
            int result = 1, curr = 0;
            for (const auto& w : weights) {
                if (curr + w > mid) {
                    ++result;
                    curr = 0;
                }
                curr += w;
            }
            return result <= D;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.shipWithinDays(nums);

        // Print result to prevent optimization
        cout << "fun_hf1PRBiYceaFFfqC: Executed shipWithinDays() from Capacity To Ship Packages Within D Days" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_hf1PRBiYceaFFfqC: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
