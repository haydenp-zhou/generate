#include "fun_sT4JY6wBekj5srz7.hpp"

int fun_sT4JY6wBekj5srz7() {
    // LeetCode Problem: Construct String With Repeat Limit

    // Solution class
    class Solution {

    public:
        string repeatLimitedString(string s, int repeatLimit) {
            vector<int> cnt(26);
            for (const auto& c : s) {
                ++cnt[c - 'a'];
            }
            string result;
            int top1 = 25;
            for (;;) {
                for (; top1 >= 0; --top1) {
                    if (cnt[top1]) {
                        break;
                    }
                }
                if (top1 == -1) {
                    break;
                }
                const int c = min(cnt[top1], repeatLimit - static_cast<int>(!empty(result) && result.back() == 'a' + top1));
                cnt[top1] -= c;
                result.append(c, 'a' + top1);
                int top2 = top1 - 1;
                for (; top2 >= 0; --top2) {
                    if (cnt[top2]) {
                        break;
                    }
                }
                if (top2 == -1) {
                    break;
                }
                --cnt[top2];
                result.push_back('a' + top2);
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
        volatile auto result = sol.repeatLimitedString(nums);

        // Print result to prevent optimization
        cout << "fun_sT4JY6wBekj5srz7: Executed repeatLimitedString() from Construct String With Repeat Limit" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_sT4JY6wBekj5srz7: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
