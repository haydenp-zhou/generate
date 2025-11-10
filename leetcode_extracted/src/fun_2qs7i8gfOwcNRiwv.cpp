#include "fun_2qs7i8gfOwcNRiwv.hpp"

int fun_2qs7i8gfOwcNRiwv() {
    // LeetCode Problem: Query Kth Smallest Trimmed Number

    // Solution class
    class Solution {

    public:
        vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
            int max_t = 0;
            for (int i = 0; i < size(queries); ++i) {
                max_t = max(max_t, queries[i][1]);
            }
            vector<vector<pair<int, int>>> lookup(max_t + 1);
            for (int i = 0; i < size(queries); ++i) {
                lookup[queries[i][1]].emplace_back(queries[i][0], i);
            }
            vector<int> idxs(size(nums));
            iota(begin(idxs), end(idxs), 0);
            vector<int> result(size(queries));
            for (int l = 1; l <= max_t; ++l) {
                vector<int> cnt(10);
                for (int i = 0; i < size(idxs); ++i) {
                    const int d = nums[idxs[i]][size(nums[idxs[i]]) - l]- '0';
                    ++cnt[d];
                }
                for (int d = 0; d < 9; ++d) {
                    cnt[d + 1] += cnt[d];
                }
                vector<int> new_idxs(size(nums));
                for (int i = size(idxs) - 1; i >= 0; --i) {
                    const int d = nums[idxs[i]][size(nums[idxs[i]]) - l] - '0';
                    --cnt[d];
                    new_idxs[cnt[d]] = idxs[i];
                }
                idxs = move(new_idxs);
                for (const auto& [k, i] : lookup[l]) {
                    result[i] = idxs[k - 1];
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.smallestTrimmedNumbers(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_2qs7i8gfOwcNRiwv: Executed smallestTrimmedNumbers() from Query Kth Smallest Trimmed Number" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_2qs7i8gfOwcNRiwv: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
