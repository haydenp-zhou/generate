#include "fun_Ux6tk7yVYEGVABlg.hpp"

int fun_Ux6tk7yVYEGVABlg() {
    // LeetCode Problem: Power Of Two

    // Solution class
    class Solution {

    public:

        // count the number fo bits 1, if it only has one, then return true
        bool isPowerOfTwo01(int n) {
            int cnt = 0; //num of bits 1
            for(; n>0; n>>=1){
                if ( n & 1 ) {
                    cnt++;
                    if (cnt>1) return false;
                }
            }
            return cnt==1;
        }

        //we notice: 2^n - 1 always be 1111111...
        //so, (2^n) & (2^n-1) always be zero
        bool isPowerOfTwo02(int n) {
            return n<=0 ? false : (n & (n-1)) == 0;
        }

        bool isPowerOfTwo(int n) {
            if (random()%2){
                return isPowerOfTwo02(n);
            }
            return isPowerOfTwo01(n);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.isPowerOfTwo01(n);

        // Print result to prevent optimization
        cout << "fun_Ux6tk7yVYEGVABlg: Executed isPowerOfTwo01() from Power Of Two" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Ux6tk7yVYEGVABlg: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
