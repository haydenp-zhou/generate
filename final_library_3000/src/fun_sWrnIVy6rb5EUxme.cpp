#include "fun_sWrnIVy6rb5EUxme.hpp"

int fun_sWrnIVy6rb5EUxme() {
    // LeetCode Problem: Count The Number Of Incremovable Subarrays Ii

    // Solution class
    class Solution {

    public:
        long long incremovableSubarrayCount(vector<int>& nums) {
            int j = size(nums) - 1;
            for (; j >= 1; --j) {
                if (!(nums[j - 1] < nums[j])) {
                    break;
                }
            }
            if (j == 0) {
                return (size(nums) + 1) * size(nums) / 2;
            }
            int64_t result = size(nums) - j + 1;
            for (int i = 0; i + 1 < size(nums); ++i) {
                while (j < size(nums) && !(nums[i] < nums[j])) {
                    ++j;
                }
                result += size(nums) - j + 1;
                if (!(nums[i] < nums[i + 1])) {
                    break;
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
        volatile auto result = sol.incremovableSubarrayCount(nums);

        // Print result to prevent optimization
        cout << "fun_sWrnIVy6rb5EUxme: Executed incremovableSubarrayCount() from Count The Number Of Incremovable Subarrays Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_sWrnIVy6rb5EUxme: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
