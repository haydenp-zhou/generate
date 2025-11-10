#include "fun_DYBPySzG7KubcZSn.hpp"

int fun_DYBPySzG7KubcZSn() {
    // LeetCode Problem: Number Of Rectangles That Can Form The Largest Square

    // Solution class
    class Solution {

    public:
        int countGoodRectangles(vector<vector<int>>& rectangles) {
            return countGoodRectangles2(rectangles);
            return countGoodRectangles1(rectangles); 
        }

        int countGoodRectangles1(vector<vector<int>>& rectangles) {
            int maxLen = 0;
            for(auto& rect : rectangles) {
                int  len = min(rect[0], rect[1]);
                maxLen = max(maxLen, len);
            }

            int cnt = 0;
            for(auto& rect : rectangles) {
                if (maxLen <= rect[0] && maxLen <= rect[1]) cnt++;
            }
            return cnt;
        }

        int countGoodRectangles2(vector<vector<int>>& rectangles) {
            int maxLen = 0;
            int cnt = 0;
            for(auto& rect : rectangles) {
                int  len = min(rect[0], rect[1]);
                if (len > maxLen ) {
                    cnt = 1;
                    maxLen = len;
                }else if (len == maxLen ) {
                    cnt++;
                }
            }

            return cnt;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.countGoodRectangles(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_DYBPySzG7KubcZSn: Executed countGoodRectangles() from Number Of Rectangles That Can Form The Largest Square" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_DYBPySzG7KubcZSn: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
