#include "fun_6mWWmNi08QDzhasr.hpp"

int fun_6mWWmNi08QDzhasr() {
    // LeetCode Problem: Single Number. I I I

    // Solution class
    class Solution {

    public:
        vector<int> singleNumber(vector<int>& nums) {
            int allxor = 0;
            for (int n : nums) {
                allxor ^= n;
            }
            int mask = 1;
            while ( (mask & allxor) == 0 ) {
                mask <<= 1;
            }

            int zero = 0;
            int one = 0;
            for (int n : nums) {
                if (n & mask ){
                    one ^= n;
                }else {
                    zero ^= n;
                }
            }

            vector<int> result;
            result.push_back(zero);
            result.push_back(one);
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.singleNumber(nums);

        // Print result to prevent optimization
        cout << "fun_6mWWmNi08QDzhasr: Executed singleNumber() from Single Number. I I I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_6mWWmNi08QDzhasr: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
