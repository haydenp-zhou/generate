#include "fun_9xRk4p9z2Smigwhj.hpp"

int fun_9xRk4p9z2Smigwhj() {
    // LeetCode Problem: Permutation In String

    // Solution class
    class Solution {

    public:
        bool checkInclusion(string s1, string s2) {
            vector<int> counts(256);
            for (const auto& c : s1) {
                ++counts[c];
            }
            for (int i = 0, l = s1.length(); i < s2.length(); ++i) {
                if (counts[s2[i]]-- > 0) {
                    --l;
                }
                if (l == 0) {
                    return true;
                }
                int start = i + 1 - s1.length();
                if (start >= 0 && ++counts[s2[start]] > 0) {
                    ++l;
                }
            }
            return false;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.checkInclusion(nums);

        // Print result to prevent optimization
        cout << "fun_9xRk4p9z2Smigwhj: Executed checkInclusion() from Permutation In String" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_9xRk4p9z2Smigwhj: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
