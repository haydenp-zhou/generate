#include "fun_QJo8vBFOsIGVkpTh.hpp"

int fun_QJo8vBFOsIGVkpTh() {
    // LeetCode Problem: Minimum Speed To Arrive On Time

    // Solution class
    class Solution {

    public:
        bool verify(vector<int>& dist, double hour, int speed) {
            double t = 0;
            int n = dist.size();
            for (int i=0; i<n-1; i++){
                t += (dist[i] + speed -1) / speed;
            }
            t += (double)dist[n-1]/speed;
            return t <= hour;
        }

        int minSpeedOnTime(vector<int>& dist, double hour) {
            int n = dist.size();
            if (hour <= n-1) return -1;

            int low = 1, high = 1e7;
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (verify(dist, hour, mid)) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }
            return high;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.verify(nums);

        // Print result to prevent optimization
        cout << "fun_QJo8vBFOsIGVkpTh: Executed verify() from Minimum Speed To Arrive On Time" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_QJo8vBFOsIGVkpTh: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
