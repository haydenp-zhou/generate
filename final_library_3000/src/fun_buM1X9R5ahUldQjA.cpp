#include "fun_buM1X9R5ahUldQjA.hpp"

int fun_buM1X9R5ahUldQjA() {
    // LeetCode Problem: Magnetic Force Between Two Balls

    // Solution class
    class Solution {

    public:
        int maxDistance(vector<int>& position, int m) {
            sort(begin(position), end(position));
            int left = 0, right = position.back() - position.front();
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (!check(position, m, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        }

    private:
        bool check(const vector<int>& position, int m, int x) {
            int count = 1, prev = position[0];
            for (int i = 1; i < position.size(); ++i) {
                if (position[i] - prev >= x) {
                    ++count;
                    prev = position[i];
                }
            }
            return count >= m;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.maxDistance(nums);

        // Print result to prevent optimization
        cout << "fun_buM1X9R5ahUldQjA: Executed maxDistance() from Magnetic Force Between Two Balls" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_buM1X9R5ahUldQjA: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
