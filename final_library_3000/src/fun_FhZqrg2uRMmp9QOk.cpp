#include "fun_FhZqrg2uRMmp9QOk.hpp"

int fun_FhZqrg2uRMmp9QOk() {
    // LeetCode Problem: Form Array By Concatenating Subarrays Of Another Array

    // Solution class
    class Solution {

    public:
        bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
            int pos = 0;
            for (const auto& group : groups) {
                pos = KMP(nums, group, pos);
                if (pos == -1) {
                    return false;
                }
                pos += size(group);
            }
            return true;
        }

    private:
        int KMP(const vector<int>& text, const vector<int>& pattern, int start) {
            const auto& prefix = getPrefix(pattern);
            int j = -1;
            for (int i = start; i < size(text); ++i) {
                while (j + 1 > 0 && pattern[j + 1] != text[i]) {
                    j = prefix[j];
                }
                if (pattern[j + 1] == text[i]) {
                    ++j;
                }
                if (j + 1 == size(pattern)) {
                    return i - j;
                }
            }
            return -1;
        }

        vector<int> getPrefix(const vector<int>& pattern) {
            vector<int> prefix(size(pattern), -1);
            int j = -1;
            for (int i = 1; i < size(pattern); ++i) {
                while (j + 1 > 0 && pattern[j + 1] != pattern[i]) {
                    j = prefix[j];
                }
                if (pattern[j + 1] == pattern[i]) {
                    ++j;
                }
                prefix[i] = j;
            }
            return prefix;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.canChoose(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_FhZqrg2uRMmp9QOk: Executed canChoose() from Form Array By Concatenating Subarrays Of Another Array" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_FhZqrg2uRMmp9QOk: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
