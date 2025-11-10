#include "fun_fVScLMZ56I8gEOo3.hpp"

int fun_fVScLMZ56I8gEOo3() {
    // LeetCode Problem: Maximum Average Subarray Ii

    // Solution class
    class Solution {

    public:
        double findMaxAverage(vector<int>& nums, int k) {
            double left = *min_element(nums.begin(), nums.end());
            double delta = numeric_limits<double>::max();
            while (delta > 1e-5) {
                delta = getDelta(left, nums, k);
                left += delta;
            }
            return left;
        }

    private:
        double getDelta(double avg, const vector<int>& nums, int k) {
            vector<double> accu(nums.size() + 1);
            int minval_pos = -1;
            double delta = 0.0;
            for (int i = 0; i < nums.size(); ++i) {
                accu[i + 1] = nums[i] + accu[i] - avg;
                if (i >= k - 1) {
                    if (minval_pos == -1 || accu[i - k + 1] < accu[minval_pos]) {
                        minval_pos = i - k + 1;
                    }
                    if (accu[i+1] - accu[minval_pos] >= 0) {
                        delta = max(delta, (accu[i + 1] - accu[minval_pos]) / (i + 1 - minval_pos));
                    }
                }
            }
            return delta;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.findMaxAverage(nums);

        // Print result to prevent optimization
        cout << "fun_fVScLMZ56I8gEOo3: Executed findMaxAverage() from Maximum Average Subarray Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_fVScLMZ56I8gEOo3: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
