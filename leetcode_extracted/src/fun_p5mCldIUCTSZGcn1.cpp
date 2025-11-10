#include "fun_p5mCldIUCTSZGcn1.hpp"

int fun_p5mCldIUCTSZGcn1() {
    // LeetCode Problem: Minimum Number Of Moves To Make Palindrome

    // Solution class
    class Solution {

    public:
        int minMovesToMakePalindrome(string s) {
            vector<vector<int>> idxs(26);
            for (int i = 0; i < size(s); ++i) {
                idxs[s[i] - 'a'].emplace_back(i);
            }
            vector<pair<int, int>> pairs;
            vector<int> targets(size(s));
            for (const auto& idx : idxs) {
                for (int i = 0; i < size(idx) / 2; ++i) {
                    pairs.emplace_back(idx[i], idx[(size(idx) - 1) - i]);
                }
                if (size(idx) % 2) {
                    targets[idx[size(idx) / 2]] = size(s) / 2;
                }
            }
            sort(begin(pairs), end(pairs));
            for (int i = 0; i < size(pairs); ++i) {
                targets[pairs[i].first] = i;
                targets[pairs[i].second] = (size(s) - 1) - i;
            }
            BIT bit(size(s));
            int result = 0;
            for (const auto& i : targets) {
                result += i - bit.query(i - 1);  // move from bit.query(i-1) to i
                bit.add(i, 1);
            }
            return result;
        }

    private:
        class BIT {
        public:
            BIT(int n) : bit_(n + 1) {  // 0-indexed
            }

            void add(int i, int val) {
                ++i;
                for (; i < size(bit_); i += lower_bit(i)) {
                    bit_[i] += val;
                }
            }

            int query(int i) const {
                ++i;
                int total = 0;
                for (; i > 0; i -= lower_bit(i)) {
                    total += bit_[i];
                }
                return total;
            }

        private:
            int lower_bit(int i) const {
                return i & -i;
            }

            vector<int> bit_;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minMovesToMakePalindrome(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_p5mCldIUCTSZGcn1: Executed minMovesToMakePalindrome() from Minimum Number Of Moves To Make Palindrome" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_p5mCldIUCTSZGcn1: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
