#include "fun_gmcjNKOD5EH2iFhm.hpp"

int fun_gmcjNKOD5EH2iFhm() {
    // LeetCode Problem: Valid Perfect Square

    // Solution class
    class Solution {

    public:
        // time limited error for  the MAX_INT.
        bool isPerfectSquare1(int num) {
            //binary searching...
            int left = 0, right = num;

            while (left <= right) {
                //cout << left << "," << right << endl;
                int mid = left + (right - left)/2;
                int n = mid * mid;
                if ( n == num) return true;
                if ( n < num ) left = mid + 1;
                else right = mid - 1;
            }

            return false; 

        }

        // the stupid way is best & fast.
        bool isPerfectSquare2(int num) {
            for (int i=1; i <= num/i ; i++ ) {
                if ( i*i == num) return true;
            }

            return false;
        }


        bool isPerfectSquare(int num) {
            return isPerfectSquare2(num);
            return isPerfectSquare1(num);
        }


    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.isPerfectSquare1(n);

        // Print result to prevent optimization
        cout << "fun_gmcjNKOD5EH2iFhm: Executed isPerfectSquare1() from Valid Perfect Square" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_gmcjNKOD5EH2iFhm: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
