#include "fun_gypCHZ5y0XnzVrQL.hpp"

int fun_gypCHZ5y0XnzVrQL() {
    // LeetCode Problem: Lexicographically Smallest Palindromic Permutation Greater Than Target

    // Solution class
    class Solution {

    public:
        string lexPalindromicPermutation(string s, string target) {
            vector<int> cnt(26);
            for (const auto& x : s) {
                ++cnt[x - 'a'];
            }
            int c = 0;
            for (int i = 0; i < size(cnt); ++i) {
                c += cnt[i] % 2;
            }
            if (c > 1) {
                return "";
            }
            int x = -1;
            if (size(s) % 2) {
                for (int i = 0; i < size(cnt); ++i) {
                    if (cnt[i] % 2) {
                        x = i;
                        --cnt[i];
                        break;
                    }
                }
            }
            string result;
            int i = 0;
            for (; i < size(target) / 2; ++i) {
                cnt[target[i] - 'a'] -= 2;
                result.push_back(target[i]);
                if (cnt[target[i] - 'a'] < 0) {
                    break;
                }
            }
            if (i == size(target) / 2) {
                if (size(target) % 2) {
                    result.push_back('a' + x);
                }
                string ret(result);
                copy(crbegin(result) + (size(target) % 2), crend(result), std::back_inserter(ret));
                if (ret > target) {
                    return ret;
                }
                if (size(target) % 2) {
                    result.pop_back();
                }
            }
            while (!empty(result)) {
                const auto& c = result.back() - 'a'; result.pop_back();
                cnt[c] += 2;
                for (int i = c + 1; i < size(cnt); ++i) {
                    if (!cnt[i]) {
                        continue;
                    }
                    cnt[i] -= 2;
                    result.push_back('a' + i);
                    for (int j = 0; j < size(cnt); ++j) {
                        if (!cnt[j]) {
                            continue;
                        }
                        while (cnt[j]) {
                            cnt[j] -= 2;
                            result.push_back('a' + j);
                        }

                    }
                    if (size(target) % 2) {
                        result.push_back('a' + x);
                    }
                    string ret(result);
                    copy(crbegin(result) + (size(target) % 2), crend(result), std::back_inserter(ret));
                    return ret;
                }
            }
            return "";
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.lexPalindromicPermutation(nums);

        // Print result to prevent optimization
        cout << "fun_gypCHZ5y0XnzVrQL: Executed lexPalindromicPermutation() from Lexicographically Smallest Palindromic Permutation Greater Than Target" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_gypCHZ5y0XnzVrQL: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
