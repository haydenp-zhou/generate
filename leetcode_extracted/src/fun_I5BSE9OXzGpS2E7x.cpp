#include "fun_I5BSE9OXzGpS2E7x.hpp"

int fun_I5BSE9OXzGpS2E7x() {
    // LeetCode Problem: Maximum Absolute Sum Of Any Subarray

    // Solution class
    class Solution {

    public:
        int maxAbsoluteSum(vector<int>& nums) {
            return maxAbsoluteSum02(nums); //56ms
            return maxAbsoluteSum01(nums); //56ms
        }



        int maxAbsoluteSum01(vector<int>& nums) {
            return std::max(maxSumArray(nums), std::abs(minSumArray(nums)) );
        }

        //https://en.wikipedia.org/wiki/Maximum_subarray_problem
        int maxSumArray(vector<int>& nums) {
            int max = nums[0];
            int sum = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (sum < 0 ) sum = nums[i];
                else sum += nums[i];
                if (max < sum) max = sum;
            }
            return max;
        }

        int minSumArray(vector<int>& nums) {
            int min = nums[0];
            int sum = nums[0];
            for (int i = 1; i < nums.size(); i++) {
                if (sum > 0 ) sum = nums[i];
                else sum += nums[i];
                if (min > sum) min = sum;
            }
            return min;
        }

        // Becasue maxSumArray() & minSumArray() are two similar,
        // we can merge them together to save one loop
        int maxAbsoluteSum02(vector<int>& nums) {
            int max = nums[0];
            int max_sum = nums[0];

            int min = nums[0];
            int min_sum = nums[0];

            for (int i = 1; i < nums.size(); i++) {

                if (max_sum < 0 ) max_sum = nums[i];
                else max_sum += nums[i];
                if (max < max_sum) max = max_sum;


                if (min_sum > 0 ) min_sum = nums[i];
                else min_sum += nums[i];
                if (min > min_sum) min = min_sum;

            }

            return std::max(max, abs(min));
        }


    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.maxAbsoluteSum(nums);

        // Print result to prevent optimization
        cout << "fun_I5BSE9OXzGpS2E7x: Executed maxAbsoluteSum() from Maximum Absolute Sum Of Any Subarray" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_I5BSE9OXzGpS2E7x: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
