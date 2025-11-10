#include "fun_TAyeV4hrEUk7N2hh.hpp"

int fun_TAyeV4hrEUk7N2hh() {
    // LeetCode Problem: Rearranging Fruits

    // Solution class
    class Solution {

    public:
        long long minCost(vector<int>& basket1, vector<int>& basket2) {
            unordered_map<int, int> cnt;
            for (const auto& x : basket1) {
                ++cnt[x];
            }
            for (const auto& x : basket2) {
                --cnt[x];
            }
            const int mn = min_element(cbegin(cnt), cend(cnt))->first;
            vector<int> swaps;
            for (const auto& [k, v] : cnt) {
                if (v % 2) {
                    return -1;
                }
                for (int _ = 0; _ < abs(v) / 2; ++_) {
                    swaps.emplace_back(k);
                }   
            }
            nth_element(begin(swaps), begin(swaps) + size(swaps) / 2, end(swaps));
            int64_t result = 0;
            for (int i = 0; i < size(swaps) / 2; ++i) {
                result += min(swaps[i], mn * 2);
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
        volatile auto result = sol.minCost(nums);

        // Print result to prevent optimization
        cout << "fun_TAyeV4hrEUk7N2hh: Executed minCost() from Rearranging Fruits" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_TAyeV4hrEUk7N2hh: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
