#include "fun_gFVjvfsi8nP6m6dP.hpp"

int fun_gFVjvfsi8nP6m6dP() {
    // LeetCode Problem: Least Number Of Unique Integers After K Removals

    // Solution class
    class Solution {

    public:
        int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
            const auto& count = counter(arr);
            const auto& count_count = counter(count);
            int result = count.size();
            for (int c = 1; c <= arr.size(); ++c) {
                if (!count_count.count(c)) {
                    continue;
                }
                if (k < c * count_count.at(c)) {
                    result -= k / c;
                    break;
                }
                k -= c * count_count.at(c);
                result -= count_count.at(c);
            }
            return result;
        }

    private:
        unordered_map<int, int> counter(const vector<int>& arr) {
            unordered_map<int, int> result;
            for (const auto& i : arr) {
                ++result[i];
            }
            return result;
        }

        unordered_map<int, int> counter(const unordered_map<int, int>& count) {
            unordered_map<int, int> result;
            for (const auto& [_, i] : count) {
                ++result[i];
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.findLeastNumOfUniqueInts(nums);

        // Print result to prevent optimization
        cout << "fun_gFVjvfsi8nP6m6dP: Executed findLeastNumOfUniqueInts() from Least Number Of Unique Integers After K Removals" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_gFVjvfsi8nP6m6dP: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
