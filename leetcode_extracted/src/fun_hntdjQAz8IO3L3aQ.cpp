#include "fun_hntdjQAz8IO3L3aQ.hpp"

int fun_hntdjQAz8IO3L3aQ() {
    // LeetCode Problem: Count Complete Substrings

    // Solution class
    class Solution {

    public:
        int countCompleteSubstrings(string word, int k) {
            const int d = size(unordered_set<char>(cbegin(word), cend(word)));
            int result = 0, valid = 0;
            vector<int> cnt(26);
            for (int c = 1; c <= d; ++c) {
                int left = 0;
                for (int right = 0; right < size(word); ++right) {
                    const int curr = ++cnt[word[right] - 'a'];
                    valid += curr == k ? 1 : curr == k + 1 ? -1 : 0;
                    if (right - left + 1 == c * k + 1) {
                        const int curr = cnt[word[left++] - 'a']--;
                        valid -= curr == k ? 1 : curr == k + 1 ? -1 : 0;
                    }
                    if (valid == c) {
                        ++result;
                    }
                    if (right + 1 == size(word) || abs(word[right + 1] - word[right]) > 2) {
                        while (left < right + 1) {
                            const int curr = cnt[word[left++] - 'a']--;
                            valid -= curr == k ? 1 : curr == k + 1 ? -1 : 0;
                        }
                    }
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
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.countCompleteSubstrings(nums);

        // Print result to prevent optimization
        cout << "fun_hntdjQAz8IO3L3aQ: Executed countCompleteSubstrings() from Count Complete Substrings" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_hntdjQAz8IO3L3aQ: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
