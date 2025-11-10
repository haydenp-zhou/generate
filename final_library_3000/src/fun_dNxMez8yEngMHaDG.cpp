#include "fun_dNxMez8yEngMHaDG.hpp"

int fun_dNxMez8yEngMHaDG() {
    // LeetCode Problem: Search In Rotated Sorted Array. I I

    // Solution class
    class Solution {

    public:
        bool search(int A[], int n, int key) {
            if (n<=0) return false;

            if (n==1){
                return (A[0]==key) ? true : false;
            }
            int low=0, high=n-1;
            while( low<=high ){

                if (A[low] < A[high] && ( key < A[low] || key > A[high]) ) {
                     return false;
                }

                //if dupilicates, remove the duplication
                while (low < high && A[low]==A[high]){
                    low++;
                }

                int mid = low + (high-low)/2;
                if ( A[mid] == key ) return true;

                //the target in non-rotated array
                if (A[low] < A[mid] && key >= A[low] && key< A[mid]){
                    high = mid - 1;
                    continue;
                }
                //the target in non-rotated array
                if (A[mid] < A[high] && key > A[mid] && key <= A[high] ){
                    low = mid + 1;
                    continue;
                }
                //the target in rotated array
                if (A[low] > A[mid] ){
                    high = mid - 1;
                    continue;
                }
                //the target in rotated array
                if (A[mid] > A[high] ){
                    low = mid + 1;
                    continue;
                }

                //reach here means nothing found.
                low++;
            }
            return false;
        }



    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.search(n);

        // Print result to prevent optimization
        cout << "fun_dNxMez8yEngMHaDG: Executed search() from Search In Rotated Sorted Array. I I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_dNxMez8yEngMHaDG: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
