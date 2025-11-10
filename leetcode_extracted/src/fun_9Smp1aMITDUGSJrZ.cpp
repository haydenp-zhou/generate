#include "fun_9Smp1aMITDUGSJrZ.hpp"

int fun_9Smp1aMITDUGSJrZ() {
    // LeetCode Problem: Number Of Ways Where Square Of Number Is Equal To Product Of Two Numbers

    // Solution class
    class Solution {

    public:
        int numTriplets(vector<int>& nums1, vector<int>& nums2) {
            int result = 0;
            for (const auto& n : nums1) {
                result += twoProduct(nums2, static_cast<int64_t>(n) * n);
            }
            for (const auto& n : nums2) {
                result += twoProduct(nums1, static_cast<int64_t>(n) * n);
            }
            return result;
        }

    private:
        int twoProduct(const vector<int>& nums, int64_t i) {
            unordered_map<int, int> lookup;
            int count = 0;
            for (const auto& num : nums) {
                if (i % num) {
                    continue;
                }
                count += lookup[i / num];
                ++lookup[num];
            }
            return count;
        }  

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.numTriplets(nums);

        // Print result to prevent optimization
        cout << "fun_9Smp1aMITDUGSJrZ: Executed numTriplets() from Number Of Ways Where Square Of Number Is Equal To Product Of Two Numbers" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_9Smp1aMITDUGSJrZ: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
