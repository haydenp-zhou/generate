#include "fun_M3gTnBuLSMtXQUxN.hpp"

int fun_M3gTnBuLSMtXQUxN() {
    // LeetCode Problem: Maximum Product Of Word Lengths

    // Solution class
    class Solution {

    public:
        //
        // there are two algorithms:
        //
        // 1) compare two words is same or not 
        //    - we can use bit-mask to solve that. 
        //    - we need be careful about one word is subset of another one, such as: "abc" is subset of "abcabc"
        //
        // 2) find out the max product - that needs O(N^2) time complexity algorithm.
        //

        int maxProduct(vector<string>& words) {
            //Key is the word's bitmask, and the value the max length of that bit mask
            unordered_map<int, int> maxLens;
            //constructing the bitmask.
            for(auto& w: words) {
                int mask = 0;
                for (auto& c: w) {
                    mask = mask | ( 1 << (c-'a') );
                }
                if ( maxLens.find(mask) == maxLens.end() || maxLens[mask] < w.size() ) {
                    maxLens[mask] = w.size();
                }
            }

            //find out the max product
            int result = 0;
            for (auto a : maxLens) {
                for (auto b: maxLens) {
                    // if `a` and `b` is same, then just simply continue
                    if (a.first & b.first) continue; // there are common letters
                    result = max( result, a.second * b.second );
                }
            }

            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.O(strs);

        // Print result to prevent optimization
        cout << "fun_M3gTnBuLSMtXQUxN: Executed O() from Maximum Product Of Word Lengths" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_M3gTnBuLSMtXQUxN: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
