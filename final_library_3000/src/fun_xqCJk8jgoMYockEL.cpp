#include "fun_xqCJk8jgoMYockEL.hpp"

int fun_xqCJk8jgoMYockEL() {
    // LeetCode Problem: Minimum Number Of Operations To Move All Balls To Each Box

    // Solution class
    class Solution {


    public:
        vector<int> minOperations(string boxes) {
            vector<int> result(boxes.size());
            //minOperations01(boxes, result); //128ms
            minOperations02(boxes, result); //4s
            return result;
        }

        void minOperations01(string& boxes, vector<int>& result ) {
            vector<int> balls;
            for(int i=0; i<boxes.size(); i++) {
                if(boxes[i] == '1') balls.push_back(i);
            }

            for (int i=0; i<boxes.size(); i++) {
                int steps = 0;
                for (int j=0; j<balls.size(); j++) {
                    steps += abs(balls[j] - i);
                }
                result[i] = steps;
            }
        }
        void minOperations02(string& boxes, vector<int>& result ) {
            //from left to right
            for(int i=0, ops=0, balls=0; i< boxes.size(); i++) {
                result[i] += ops;
                balls += (boxes[i] == '1' ? 1 : 0);
                ops += balls;
            }
            //from right to left
            for(int i=boxes.size()-1, ops=0, balls=0; i>=0; i--) {
                result[i] += ops;
                balls += (boxes[i] == '1' ? 1 : 0);
                ops += balls;
            }
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.minOperations(nums);

        // Print result to prevent optimization
        cout << "fun_xqCJk8jgoMYockEL: Executed minOperations() from Minimum Number Of Operations To Move All Balls To Each Box" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_xqCJk8jgoMYockEL: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
