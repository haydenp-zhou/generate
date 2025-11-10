#include "fun_rVxS77724cOvpTvc.hpp"

int fun_rVxS77724cOvpTvc() {
    // LeetCode Problem: Maximum Score Of A Good Subarray

    // Solution class
    class Solution {

    public:
        int maximumScore(vector<int>& nums, int k) {
            int score = nums[k];
            int m = score;
            int left = k, right = k;
            int l = left, r = right;
            while (left>0 || right < nums.size()-1){

                if ( left > 0 && right < nums.size()-1 ) {
                    if (nums[left-1] > nums[right+1]) {
                        left--;
                    } else if (nums[left-1] < nums[right+1]) {
                        right++;
                    } else {
                        left--;right++;
                    }
                }else if ( left <= 0 ) {
                    right++;
                }else if ( right >= nums.size() -1 ) { 
                    left--;
                }else {
                    break;
                }

                m = min(m, min( nums[left], nums[right]));
                int s = m * (right - left + 1);
                if ( s > score) {
                    score = s;
                    l = left;  r = right;
                }
            }

            //cout << "[" << l << "," << r << "] = " << score << endl;

            return score;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.maximumScore(nums);

        // Print result to prevent optimization
        cout << "fun_rVxS77724cOvpTvc: Executed maximumScore() from Maximum Score Of A Good Subarray" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_rVxS77724cOvpTvc: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
