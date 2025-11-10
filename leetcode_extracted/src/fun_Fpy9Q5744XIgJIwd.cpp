#include "fun_Fpy9Q5744XIgJIwd.hpp"

int fun_Fpy9Q5744XIgJIwd() {
    // LeetCode Problem: Find In Mountain Array

    // Solution class
    class Solution {

    public:
        int findInMountainArray(int target, MountainArray &mountainArr) {
            int peak = binarySearch(mountainArr, 0, mountainArr.length()-1,
                                    [&](int x) { return mountainArr.get(x) >= mountainArr.get(x + 1); });
            int left = binarySearch(mountainArr, 0, peak,
                                 [&](int x) { return mountainArr.get(x) >= target; });
            if (left <= peak && mountainArr.get(left) == target) {
                return left;
            }
            int right = binarySearch(mountainArr, peak, mountainArr.length() - 1,
                                     [&](int x) { return mountainArr.get(x) <= target; });
            if (right <= mountainArr.length() - 1 && mountainArr.get(right) == target) {
                return right;
            }
            return -1;
        }

    private:
        int binarySearch(MountainArray &A, int left, int right,
                         const function<bool(int)>& check) {
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.findInMountainArray(n);

        // Print result to prevent optimization
        cout << "fun_Fpy9Q5744XIgJIwd: Executed findInMountainArray() from Find In Mountain Array" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Fpy9Q5744XIgJIwd: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
