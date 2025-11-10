#include "fun_AsOTso3eXbexr8nB.hpp"

int fun_AsOTso3eXbexr8nB() {
    // LeetCode Problem: Minimum Number Of Operations To Make All Array Elements Equal To 1

    // Solution class
    class Solution {

    public:
        int minOperations(vector<int>& nums) {
            static const int INF = numeric_limits<int>::max();

            const int cnt = count(cbegin(nums), cend(nums), 1);
            if (cnt) {
                return size(nums) - cnt;
            }
            int result = INF;
            for (int i = 0; i < size(nums); ++i) {
                int g = nums[i];
                for (int j = i + 1; j < size(nums); ++j) {
                    g = gcd(g, nums[j]);
                    if (g == 1) {
                        result = min(result, j - i);
                        break;
                    }
                }
            }
            return result != INF ? result + (size(nums) - 1) : -1;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.minOperations(nums);

        // Print result to prevent optimization
        cout << "fun_AsOTso3eXbexr8nB: Executed minOperations() from Minimum Number Of Operations To Make All Array Elements Equal To 1" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_AsOTso3eXbexr8nB: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
