#include "fun_5gzT6X2lECFtJR7Y.hpp"

int fun_5gzT6X2lECFtJR7Y() {
    // LeetCode Problem: Can Make Palindrome From Substring

    // Solution class
    class Solution {

    public:
        vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
            static const int CHARSET_SIZE = 26;
            vector<int> curr(CHARSET_SIZE);
            vector<vector<int>> count(1, vector<int>(CHARSET_SIZE));
            for (const auto& c : s) {
                ++curr[c - 'a'];
                count.emplace_back(curr);
            }
            vector<bool> result;
            for (const auto& query : queries) {
                int left = query[0], right = query[1], k = query[2];
                int total = 0;
                for (int i = 0; i < CHARSET_SIZE; ++i) {
                    total += (count[right + 1][i] - count[left][i]) % 2;
                }
                result.emplace_back(total / 2 <= k);
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.canMakePaliQueries(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_5gzT6X2lECFtJR7Y: Executed canMakePaliQueries() from Can Make Palindrome From Substring" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_5gzT6X2lECFtJR7Y: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
