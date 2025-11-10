#include "fun_tadRwx82KYxqUstt.hpp"

int fun_tadRwx82KYxqUstt() {
    // LeetCode Problem: How Many Numbers Are Smaller Than The Current Number

    // Solution class
    class Solution {

    public:
        vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
            const auto& m = *max_element(cbegin(nums), cend(nums));
            auto count = counter(nums);
            for (int i = 0; i <= m; ++i) {
                count[i] += count[i - 1];
            }
            vector<int> result;
            for (const auto& i : nums) {
                result.emplace_back(count[i - 1]);
            }
            return result;
        }

    private:
        unordered_map<int, int> counter(const vector<int>& nums) const {
            unordered_map<int, int> count;
            for (const auto& num : nums) {
                ++count[num];
            }
            return count;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.smallerNumbersThanCurrent(nums);

        // Print result to prevent optimization
        cout << "fun_tadRwx82KYxqUstt: Executed smallerNumbersThanCurrent() from How Many Numbers Are Smaller Than The Current Number" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_tadRwx82KYxqUstt: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
