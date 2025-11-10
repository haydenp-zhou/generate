#include "fun_q9fXBDIWpATI1PoX.hpp"

int fun_q9fXBDIWpATI1PoX() {
    // LeetCode Problem: Palindrome Number

    // Solution class
    class Solution {

    public:
        bool isPalindrome(int x) {
            if (x < 0) {
                return false;
            }
            int temp = x;
            int reversed = 0;
            while (temp != 0) {
                if (isOverflow(reversed, temp % 10)) {
                    return false;
                }
                reversed = reversed * 10 + temp % 10;
                temp = temp / 10;
            }
            return reversed == x;
        }

    private:
        bool isOverflow(int q, int r) {
            static const int max_q = numeric_limits<int>::max() / 10;
            static const int max_r = numeric_limits<int>::max() % 10;
            return (q > max_q) || (q == max_q && r > max_r);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.isPalindrome(testValue);

        // Print result to prevent optimization
        cout << "fun_q9fXBDIWpATI1PoX: Executed isPalindrome() from Palindrome Number" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_q9fXBDIWpATI1PoX: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
