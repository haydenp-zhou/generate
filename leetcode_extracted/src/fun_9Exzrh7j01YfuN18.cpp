#include "fun_9Exzrh7j01YfuN18.hpp"

int fun_9Exzrh7j01YfuN18() {
    // LeetCode Problem: Smallest Palindromic Rearrangement Ii

    // Solution class
    class Solution {

    public:
        string smallestPalindrome(string s, int k) {
            vector<int> cnt(26);
            for (int i = 0; i < size(s) / 2; ++i) {
                ++cnt[s[i] - 'a'];
            }
            int total = 0, count = 1, remain = 0;
            int i;
            for (i = size(cnt) - 1; i >= 0; --i) {
                for (int c = 1; c <= cnt[i]; ++c) {
                    ++total;
                    count = count * total / c;
                    if (count >= k) {
                        remain = cnt[i] - c;
                        break;
                    }
                }
                if (count >= k) {
                    break;
                }
            }
            if (count < k) {
                return "";
            }
            string result(size(s), 0);
            int l = 0;
            for (int j = 0; j <= i; ++j) {
                const char x = 'a' + j;
                const int c = j != i ? cnt[j] : remain;
                for (int _ = 0; _ < c; ++_) {
                    --cnt[j];
                    result[l++] = x;
                }
            }
            while (total) {
                for (int j = i; j < size(cnt); ++j) {
                    if (!cnt[j]) {
                        continue;
                    }
                    const auto new_count = static_cast<int64_t>(count) * cnt[j] / total;
                    if (new_count < k) {
                        k -= new_count;
                        continue;
                    }
                    count = new_count;
                    --cnt[j];
                    --total;
                    result[l++] = 'a' + j;
                    break;
                }
            }
            if (size(s) % 2) {
                result[l++] = s[size(s) / 2];
            }
            for (int i = l - 1 - size(s) % 2; i >= 0; --i) {
                result[l++] = result[i];
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.smallestPalindrome(nums);

        // Print result to prevent optimization
        cout << "fun_9Exzrh7j01YfuN18: Executed smallestPalindrome() from Smallest Palindromic Rearrangement Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_9Exzrh7j01YfuN18: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
