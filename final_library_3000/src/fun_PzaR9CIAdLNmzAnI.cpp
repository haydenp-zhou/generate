#include "fun_PzaR9CIAdLNmzAnI.hpp"

int fun_PzaR9CIAdLNmzAnI() {
    // LeetCode Problem: Split Array Largest Sum

    // Solution class
    class Solution {

    public:
        // Idea
        //   1) The max of the result is the sum of the whole array.
        //   2) The min of the result is the max num among the array.
        //   3) Then, we use Binary Search to find the resullt between the `min` and  the `max`

        int splitArray(vector<int>& nums, int m) {
            int min = 0, max = 0;
            for (int n : nums) {
                min = std::max(min, n);
                max += n;
            }
            while (min < max) {
                int mid = min + (max - min) / 2;
                if (hasSmallerSum(nums, m, mid)) max = mid;
                else min = mid + 1;
            }
            return min;
        }


        // Using a specific `sum` to check wheter we can get `smaller sum`
        // The idea here as below:
        //   find all of possible `sub array` whose sum greater than `sum`
        //   1) if the number of `sub array` >  m, whcih means the actual result is greater than `sum`
        //   2) if the number of `sub array` <= m, whcih means we can have `smaller sum`
        //
        bool hasSmallerSum(vector<int>& nums, int m, int sum) {
            int cnt = 1, curSum = 0;
            for (int n : nums) {
                curSum += n;
                if (curSum > sum) {
                    curSum = n;
                    cnt++;
                    if (cnt > m) return false;
                }
            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.splitArray(nums);

        // Print result to prevent optimization
        cout << "fun_PzaR9CIAdLNmzAnI: Executed splitArray() from Split Array Largest Sum" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_PzaR9CIAdLNmzAnI: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
