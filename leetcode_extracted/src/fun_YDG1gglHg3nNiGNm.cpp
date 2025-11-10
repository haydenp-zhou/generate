#include "fun_YDG1gglHg3nNiGNm.hpp"

int fun_YDG1gglHg3nNiGNm() {
    // LeetCode Problem: Ways To Split Array Into Three Subarrays

    // Solution class
    class Solution {

    public:
        int waysToSplit(vector<int>& nums) {
            static const int MOD = 1e9 + 7;

            vector<int> prefix(1);
            for (const auto& x : nums) {
                prefix.emplace_back(prefix.back() + x);
            }

            int result = 0, left = 0, right = 0;
            for (int i = 0; i < size(nums); ++i) {
                left = max(left, i + 1);
                while (left + 1 < size(nums) && prefix[i + 1] > prefix[left + 1] - prefix[i + 1]) {
                    ++left;
                }
                right = max(right, left);
                while (right + 1 < size(nums) && prefix[right + 1] - prefix[i + 1] <= prefix.back() - prefix[right + 1]) {
                    ++right;
                }
                result = (result + (right - left)) % MOD;
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.waysToSplit(nums);

        // Print result to prevent optimization
        cout << "fun_YDG1gglHg3nNiGNm: Executed waysToSplit() from Ways To Split Array Into Three Subarrays" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_YDG1gglHg3nNiGNm: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
