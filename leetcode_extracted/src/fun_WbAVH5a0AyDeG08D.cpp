#include "fun_WbAVH5a0AyDeG08D.hpp"

int fun_WbAVH5a0AyDeG08D() {
    // LeetCode Problem: Array With Elements Not Equal To Average Of Neighbors

    // Solution class
    class Solution {

    public:
        vector<int> rearrangeArray(vector<int>& nums) {
            int mid = (size(nums) - 1) / 2;
            nth_element(begin(nums), begin(nums) + mid, end(nums));  // O(n) ~ O(n^2) time
            reversedTriPartitionWithVI(nums, nums[mid]);  // O(n) time, O(1) space
            return nums;
        }

    private:
        void reversedTriPartitionWithVI(vector<int>& nums, int val) {
            const int N = size(nums) / 2 * 2 + 1;
            #define Nums(i) nums[(1 + 2 * (i)) % N]
            for (int i = 0, j = 0, n = size(nums) - 1; j <= n;) {
                if (Nums(j) > val) {
                    swap(Nums(i++), Nums(j++));
                } else if (Nums(j) < val) {
                    swap(Nums(j), Nums(n--));
                } else {
                    ++j;
                }
            }
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.rearrangeArray(nums);

        // Print result to prevent optimization
        cout << "fun_WbAVH5a0AyDeG08D: Executed rearrangeArray() from Array With Elements Not Equal To Average Of Neighbors" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_WbAVH5a0AyDeG08D: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
