#include "fun_un7N1BPJOh0fE9KF.hpp"

int fun_un7N1BPJOh0fE9KF() {
    // LeetCode Problem: Partition Array Into Two Equal Product Subsets

    // Solution class
    class Solution {

    public:
        bool checkEqualPartitions(vector<int>& nums, long long target) {
            __int128 total = 1;
            for (const auto& x : nums) {
                total *= x;
                if (total > static_cast<__int128>(target) * target) {
                    return false;
                }
            }
            if (total != static_cast<__int128>(target) * target) {
                return false;
            }
            for (int mask = 1; mask < (1 << size(nums)) - 1; ++mask) {
                __int128 curr = 1;
                for (int i = 0; i < size(nums); ++i) {
                    if (!(mask & (1 << i))) {
                        continue;
                    }
                    curr *= nums[i];
                    if (curr > target) {
                        break;
                    }
                }
                if (curr == target) {
                    return true;
                }
            }
            return false;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.checkEqualPartitions(nums);

        // Print result to prevent optimization
        cout << "fun_un7N1BPJOh0fE9KF: Executed checkEqualPartitions() from Partition Array Into Two Equal Product Subsets" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_un7N1BPJOh0fE9KF: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
