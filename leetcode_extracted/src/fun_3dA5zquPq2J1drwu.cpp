#include "fun_3dA5zquPq2J1drwu.hpp"

int fun_3dA5zquPq2J1drwu() {
    // LeetCode Problem: Degree Of An Array

    // Solution class
    class Solution {

    public:
        int findShortestSubArray(vector<int>& nums) {
            unordered_map<int, int> left, right;
            unordered_map<int, int> counts;
            for (int i = 0; i < nums.size(); ++i) {
                if (left.count(nums[i]) == 0) {
                    left[nums[i]] = i;
                }
                right[nums[i]] = i;
                ++counts[nums[i]];
            }
            auto degree = max_element(counts.begin(), counts.end(),
                                      [](const pair<int, int>& a,
                                         const pair<int, int>& b) {
                                          return a.second < b.second;
                                      })->second;
            auto result = numeric_limits<int>::max();
            for (const auto& kvp : counts) {
                if (kvp.second == degree) {
                    result = min(result, right[kvp.first] - left[kvp.first] + 1);
                }
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
        volatile auto result = sol.findShortestSubArray(nums);

        // Print result to prevent optimization
        cout << "fun_3dA5zquPq2J1drwu: Executed findShortestSubArray() from Degree Of An Array" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_3dA5zquPq2J1drwu: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
