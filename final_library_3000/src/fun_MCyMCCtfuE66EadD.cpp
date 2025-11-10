#include "fun_MCyMCCtfuE66EadD.hpp"

int fun_MCyMCCtfuE66EadD() {
    // LeetCode Problem: Minimum Number Of Operations To Reinitialize A Permutation

    // Solution class
    class Solution {

    private: 
        bool check(vector<int>& a) {
            for(int i=0; i<a.size(); i++) {
                if (a[i] != i) return false;
            }
            return true;
        }
    public:
        int reinitializePermutation(int n) {
            vector<int> perm(n);
            vector<int> arr(n);
            for(int i=0; i<n; i++) {
                perm[i] = i;
            }
            int cnt = 0;
            while(1){
                cnt++;
                for(int i=0; i<n; i++) {
                    if (i%2==0) arr[i] = perm[i / 2];
                    else arr[i] = perm[n / 2 + (i - 1) / 2];
                }
                if (check(arr)) break;
                perm = arr;
            }

            return cnt;

        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.reinitializePermutation(nums);

        // Print result to prevent optimization
        cout << "fun_MCyMCCtfuE66EadD: Executed reinitializePermutation() from Minimum Number Of Operations To Reinitialize A Permutation" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_MCyMCCtfuE66EadD: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
