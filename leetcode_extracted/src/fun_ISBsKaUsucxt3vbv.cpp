#include "fun_ISBsKaUsucxt3vbv.hpp"

int fun_ISBsKaUsucxt3vbv() {
    // LeetCode Problem: Minimum Speed To Arrive On Time

    // Solution class
    class Solution {

    public:
        int minSpeedOnTime(vector<int>& dist, double hour) {
            static const double MAX_SPEED = 1e7;
            if (!check(dist, hour, MAX_SPEED)) {
                return -1;
            }
            int left = 1, right = MAX_SPEED;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (check(dist, hour, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

    private:
        int ceil(int a, int b) {
            return (a + b - 1) / b;
        }

        double total_time(const vector<int>& dist, int x) {
            return accumulate(cbegin(dist), prev(cend(dist)), 0,
                              [this, &x](int total, int i) {
                                  return total + ceil(i, x);
                              }) +
                   double(dist.back()) / x;
        }

        bool check(const vector<int>& dist, double hour, int x) {
            return total_time(dist, x) <= hour;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.minSpeedOnTime(nums);

        // Print result to prevent optimization
        cout << "fun_ISBsKaUsucxt3vbv: Executed minSpeedOnTime() from Minimum Speed To Arrive On Time" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_ISBsKaUsucxt3vbv: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
