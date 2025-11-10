#include "fun_UanhdZ9XgqwNle2v.hpp"

int fun_UanhdZ9XgqwNle2v() {
    // LeetCode Problem: Change Minimum Characters To Satisfy One Of Three Conditions

    // Solution class
    class Solution {

    public:
        int minCharacters(string a, string b) {
            vector<int> count1(26), count2(26);
            for (const auto& c : a) {
                ++count1[c - 'a'];
            }
            for (const auto& c : b) {
                ++count2[c - 'a'];
            }
            int result = size(a) + size(b);
            for (int i = 0; i < 26; ++i) {
                result = min(result, int(size(a)) + int(size(b)) - count1[i] - count2[i]);  // condition 3
                if (i > 0) {
                    count1[i] += count1[i - 1];
                    count2[i] += count2[i - 1];
                }
                if (i < 25) {
                    result = min(result, int(size(a)) - count1[i] + count2[i]);  // condition 1
                    result = min(result, int(size(b)) - count2[i] + count1[i]);  // condition 2
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.minCharacters(nums);

        // Print result to prevent optimization
        cout << "fun_UanhdZ9XgqwNle2v: Executed minCharacters() from Change Minimum Characters To Satisfy One Of Three Conditions" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_UanhdZ9XgqwNle2v: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
