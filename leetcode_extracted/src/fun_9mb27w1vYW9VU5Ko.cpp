#include "fun_9mb27w1vYW9VU5Ko.hpp"

int fun_9mb27w1vYW9VU5Ko() {
    // LeetCode Problem: Find K Th Smallest Pair Distance

    // Solution class
    class Solution {

    public:
        int smallestDistancePair(vector<int>& nums, int k) {
            sort(nums.begin(), nums.end());
            int left = 0, right = nums.back() - nums.front() + 1;
            while (left < right) {
                const auto mid = left + (right - left) / 2;
                if (possible(mid, nums, k)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

    private:
        bool possible(const int guess, const vector<int>& nums, const int k) {
            int count = 0, left = 0;
            for (int right = 0; right < nums.size(); ++right) {
                while ((nums[right] - nums[left]) > guess) {
                    ++left;
                }
                count += right - left;
            }
            return count >= k;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.smallestDistancePair(nums);

        // Print result to prevent optimization
        cout << "fun_9mb27w1vYW9VU5Ko: Executed smallestDistancePair() from Find K Th Smallest Pair Distance" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_9mb27w1vYW9VU5Ko: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
