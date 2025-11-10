#include "fun_OpRVb0I0QPjtGNQW.hpp"

int fun_OpRVb0I0QPjtGNQW() {
    // LeetCode Problem: Reduce Array Size To The Half

    // Solution class
    class Solution {

    public:
        int minSetSize(vector<int>& arr) {
            vector<int> counting_sort(arr.size());
            unordered_map<int, int> count;
            for (const auto& x : arr) {
                ++count[x];
            }
            for (const auto& [_, c] : count) {
                ++counting_sort[c - 1];
            }
            int result = 0, total = 0;
            for (int c = arr.size() - 1; c >= 0; --c) {
                if (!counting_sort[c]) {
                    continue;
                }
                int count = min(counting_sort[c],
                                ((int(arr.size()) + 1) / 2 - total - 1) / (c + 1) + 1);
                result += count;
                total += count * (c + 1);
                if (total >= (arr.size() + 1) / 2) {
                    break;
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
        volatile auto result = sol.minSetSize(nums);

        // Print result to prevent optimization
        cout << "fun_OpRVb0I0QPjtGNQW: Executed minSetSize() from Reduce Array Size To The Half" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_OpRVb0I0QPjtGNQW: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
