#include "fun_q4znRlbCpelOwope.hpp"

int fun_q4znRlbCpelOwope() {
    // LeetCode Problem: Squares Of A Sorted Array

    // Solution class
    class Solution {

    public:
        vector<int> sortedSquares(vector<int>& A) {
            // find the place, negative numbers are right, positive number are right.
            // two pointer, one goes left, another goes right.

            //using binary search algorithm
            const int len = A.size();
            int low = 0, high = len- 1;
            int mid =0;
            while (low <= high) {
                mid = low + (high - low)/2;
                if (A[mid] >= 0 ) high = mid - 1;
                if (A[mid] < 0 ) low = mid + 1;
            }

            //TRICKY: make sure  A[mid] <= 0 or A[mid] is A[0]
            if (A[mid] > 0 && mid > 0 ) mid--;
            //cout << mid << " - "<< A[mid]<<  endl;

            vector<int> result;
            low = mid; high = mid+1;
            while ( low >=0 && high < len ) {
                if ( abs(A[low]) < abs(A[high]) ) {
                    result.push_back(A[low] * A[low]);
                    low --;
                }else {
                    result.push_back(A[high] * A[high]);
                    high++;
                }
            }

            for (;low >= 0; low--) result.push_back(A[low] * A[low]);
            for (;high<len; high++) result.push_back(A[high] * A[high] );

            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.sortedSquares(nums);

        // Print result to prevent optimization
        cout << "fun_q4znRlbCpelOwope: Executed sortedSquares() from Squares Of A Sorted Array" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_q4znRlbCpelOwope: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
