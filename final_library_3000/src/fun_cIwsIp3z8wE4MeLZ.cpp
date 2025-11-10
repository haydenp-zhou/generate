#include "fun_cIwsIp3z8wE4MeLZ.hpp"

int fun_cIwsIp3z8wE4MeLZ() {
    // LeetCode Problem: Interval List Intersections

    // Solution class
    class Solution {

    public:
        //return true if lhs starts earlier than  rhs
        bool compareInterval(Interval& lhs, Interval& rhs) {
            return lhs.start < rhs.start;
        }
        //check two interval overlapped or not
        bool overlapped(Interval& lhs, Interval& rhs) {
            return (compareInterval(lhs, rhs)) ?
                                 lhs.end >= rhs.start:
                                 rhs.end >= lhs.start;

        }
        //merge two interval - return the intersections of two intervals
        Interval mergeTwoInterval(Interval& lhs, Interval& rhs) {
            Interval result;
            result.start = max(lhs.start, rhs.start);
            result.end = min(lhs.end, rhs.end);
            return result;
        }

        vector<Interval> intervalIntersection(vector<Interval>& A, vector<Interval>& B) {
            int lenA = A.size();
            int lenB = B.size();

            vector<Interval> result;
            if (lenA <=0 || lenB<=0) return result; //edge case

            int i=0, j=0;
            while ( i < lenA && j < lenB ) {
                if( overlapped(A[i], B[j]) ) {
                    result.push_back(mergeTwoInterval(A[i], B[j]));
                    // if the current interval is not overlapped with next one,
                    // then we move the next interval.
                    int nexti = i;
                    if ( j==lenB-1 || !overlapped(A[i], B[j+1]) ) nexti=i+1;
                    if ( i==lenA-1 || !overlapped(A[i+1], B[j]) ) j++;
                    i = nexti;
                }else{
                    //if not overlapped, we just move the next one
                    compareInterval(A[i], B[j]) ? i++ : j++;
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.compareInterval();

        // Print result to prevent optimization
        cout << "fun_cIwsIp3z8wE4MeLZ: Executed compareInterval() from Interval List Intersections" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_cIwsIp3z8wE4MeLZ: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
