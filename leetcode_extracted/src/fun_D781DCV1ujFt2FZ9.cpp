#include "fun_D781DCV1ujFt2FZ9.hpp"

int fun_D781DCV1ujFt2FZ9() {
    // LeetCode Problem: Integer Replacement

    // Solution class
    class Solution {

    public:


        int integerReplacement_recursion(int n) {
            if ( n <= 1) return 0; // recursive exited point
            if ( n == INT_MAX ) return 32; // special case to avoid integer overflow.
            if ( n % 2 == 0 ) return integerReplacement(n/2) + 1;
            return min( integerReplacement(n+1), integerReplacement(n-1) ) + 1;
        }

        int integerReplacement_recursionWithCache(int n) {
            static unordered_map<int, int> cache;
            //if hitted the cache, just return the result
            if (cache.find(n) != cache.end()) return cache[n];

            int result;
            if ( n <= 1) return 0; // recursive exited point
            if ( n == INT_MAX ) return 32; // special case to avoid integer overflow.
            if ( n % 2 == 0 ) result = integerReplacement(n/2) + 1;
            else result = min( integerReplacement(n+1), integerReplacement(n-1) ) + 1;

            //add into cache
            cache[n] = result;
            return result;
        }

        int integerReplacement_simple(int n){
            int ans = 0;
            size_t m = n;
            while (1 != m) {
                if (1 == (m & 1)) {
                    if (m==3) --m; //special case
                    else m = (m&0b11^0b01) ? m + 1 : m - 1;
                }
                else m >>= 1;
                ++ans;
            }
        return ans;
        }

        int integerReplacement(int n) {
            return integerReplacement_recursionWithCache(n);
            return integerReplacement_simple(n);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.integerReplacement_recursion(n);

        // Print result to prevent optimization
        cout << "fun_D781DCV1ujFt2FZ9: Executed integerReplacement_recursion() from Integer Replacement" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_D781DCV1ujFt2FZ9: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
