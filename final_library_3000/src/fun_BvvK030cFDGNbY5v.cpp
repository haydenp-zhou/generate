#include "fun_BvvK030cFDGNbY5v.hpp"

int fun_BvvK030cFDGNbY5v() {
    // LeetCode Problem: Palindrome Number

    // Solution class
    class Solution {

    public:

        bool isPalindrome(int x) {    
            return isPalindrome1(x);
            return isPalindrome2(x);
        }

        bool isPalindrome1(int x) {
            if (x<0) {
                return false;
            }

            int len=1;
            for (len=1; (x/len) >= 10; len*=10 );

            while (x != 0 ) {
                int left = x / len;
                int right = x % 10;

                if(left!=right){
                    return false;
                }

                x = (x%len) / 10;
                len /= 100;
            }
            return true;
        }

        bool isPalindrome2(int x) {
            return (x>=0 && x == reverse(x));
        }

    private:    
        int reverse(int x) {
            int y=0;

            int n;
            while( x!=0 ){
                n = x%10;
                //check if y is overflowed or not. 
                //if it is, then it's not palindrome
                if ( y > INT_MAX/10 - n) return x-1;
                y = y*10 + n;
                x /= 10;
            }
            return y;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.isPalindrome(n);

        // Print result to prevent optimization
        cout << "fun_BvvK030cFDGNbY5v: Executed isPalindrome() from Palindrome Number" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_BvvK030cFDGNbY5v: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
