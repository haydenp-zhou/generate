#include "fun_kyKTRV1II2VrmBf1.hpp"

int fun_kyKTRV1II2VrmBf1() {
    // LeetCode Problem: Watering Plants Ii

    // Solution class
    class Solution {

    public:
        int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
            int result = 0 ;
            int left = 0, right = size(plants) - 1;
            int canA = capacityA, canB = capacityB;
            while (left < right) {
                if (canA < plants[left]) {
                     ++result;
                    canA = capacityA;
                }
                canA -= plants[left++];
                if (canB < plants[right]) {
                     ++result;
                    canB = capacityB;
                }
                canB -= plants[right--];
            }
            if (left == right) {
                if (max(canA, canB) < plants[left]) {
                    ++result;
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
        volatile auto result = sol.minimumRefill(nums);

        // Print result to prevent optimization
        cout << "fun_kyKTRV1II2VrmBf1: Executed minimumRefill() from Watering Plants Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_kyKTRV1II2VrmBf1: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
