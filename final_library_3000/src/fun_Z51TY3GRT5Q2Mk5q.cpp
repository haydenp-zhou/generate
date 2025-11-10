#include "fun_Z51TY3GRT5Q2Mk5q.hpp"

int fun_Z51TY3GRT5Q2Mk5q() {
    // LeetCode Problem: Maximum Sum Obtained Of Any Permutation

    // Solution class
    class Solution {

    public:
        int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
            static const int MOD = 1e9 + 7;

            vector<int> count(size(nums));
            for (const auto& req : requests) {
                ++count[req[0]];
                if (req[1] + 1 < size(count)) {
                    --count[req[1] + 1];
                }
            }
            partial_sum(begin(count), end(count), begin(count));
            sort(begin(nums), end(nums));
            sort(begin(count), end(count));
            int result = 0;
            for (int i = 0; i < size(nums); ++i) {
                result = addmod(result, mulmod(nums[i], count[i], MOD), MOD);
            }
            return result;
        }

    private:
        uint32_t addmod(uint32_t a, uint32_t b, uint32_t mod) {  // avoid overflow
            a %= mod, b %= mod;
            if (mod - a <= b) {
                b -= mod;  // relied on unsigned integer overflow in order to give the expected results
            }
            return a + b;
        }

        // reference: https://stackoverflow.com/questions/12168348/ways-to-do-modulo-multiplication-with-primitive-types
        uint32_t mulmod(uint32_t a, uint32_t b, uint32_t mod)  {  // avoid overflow
            a %= mod, b %= mod;
            uint32_t result = 0;
            if (a < b) {
                swap(a, b);
            }
            while (b > 0)  { 
                if (b % 2 == 1) {
                    result = addmod(result, a, mod);
                }
                a = addmod(a, a, mod);
                b /= 2; 
            } 
            return result; 
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.maxSumRangeQuery(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_Z51TY3GRT5Q2Mk5q: Executed maxSumRangeQuery() from Maximum Sum Obtained Of Any Permutation" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Z51TY3GRT5Q2Mk5q: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
