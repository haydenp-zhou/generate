#include "fun_CDDmH1aRnFmVYkHO.hpp"

int fun_CDDmH1aRnFmVYkHO() {
    // LeetCode Problem: Minimum Operations To Make A Subsequence

    // Solution class
    class Solution {

    public:
        int minOperations(vector<int>& target, vector<int>& arr) {
            unordered_map<int, int> lookup;
            for (int i = 0; i < size(target); ++i) {
                lookup[target[i]] = i;
            }
            vector<int> lis;
            for (const auto& x : arr) {
                if (!lookup.count(x)) {
                    continue;
                }
                auto it = lower_bound(begin(lis), end(lis), lookup[x]);
                if (it == end(lis)) {
                    lis.emplace_back(lookup[x]);
                } else {
                    *it = lookup[x];
                }
            }
            return size(target) - size(lis);
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
        cout << "fun_CDDmH1aRnFmVYkHO: Executed minOperations() from Minimum Operations To Make A Subsequence" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_CDDmH1aRnFmVYkHO: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
