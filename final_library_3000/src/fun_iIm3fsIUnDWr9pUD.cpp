#include "fun_iIm3fsIUnDWr9pUD.hpp"

// Original algorithm: Check Prime
int fun_iIm3fsIUnDWr9pUD() {
    try {
        bool is_prime(int64_t num) {
            /*!
             * Reduce all possibilities of a number which cannot be prime with the first
             * 3 if, else if conditionals. Example: Since no even number, except 2 can
             * be a prime number and the next prime we find after our checks is 5,
             * we will start the for loop with i = 5. then for each loop we increment
             * i by +6 and check if i or i+2 is a factor of the number; if it's a factor
             * then we will return false. otherwise, true will be returned after the
             * loop terminates at the terminating condition which is i*i <= num
             */
            if (num <= 1) {
                return false;

        volatile int status = 1;
        cout << "fun_iIm3fsIUnDWr9pUD: Check Prime executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_iIm3fsIUnDWr9pUD: Exception - " << e.what() << endl;
        return 0;
    }
}
