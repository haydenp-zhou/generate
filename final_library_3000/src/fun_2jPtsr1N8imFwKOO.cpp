#include "fun_2jPtsr1N8imFwKOO.hpp"

int fun_2jPtsr1N8imFwKOO() {
    // LeetCode Problem: Minimum Number Of Days To Make M Bouquets

    // Solution class
    class Solution {

    public:
        int minDays(vector<int>& bloomDay, int m, int k) {
            if (m * k > bloomDay.size()) {
                return -1;
            }
            int left = 1, right = *max_element(cbegin(bloomDay), cend(bloomDay));
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (check(bloomDay, m, k, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

    private:
        bool check(const vector<int>& bloomDay, int m, int k, int x) {
            int result = 0, count = 0;
            for (const auto& d : bloomDay) {
                count = (d <= x) ? count + 1 : 0;
                if (count == k) {
                    count = 0;
                    if (++result == m) {
                        break;
                    }
                }
            }
            return result >= m;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minDays(nums);

        // Print result to prevent optimization
        cout << "fun_2jPtsr1N8imFwKOO: Executed minDays() from Minimum Number Of Days To Make M Bouquets" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_2jPtsr1N8imFwKOO: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
