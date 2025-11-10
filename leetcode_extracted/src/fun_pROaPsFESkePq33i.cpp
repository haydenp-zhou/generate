#include "fun_pROaPsFESkePq33i.hpp"

int fun_pROaPsFESkePq33i() {
    // LeetCode Problem: Maximum Elegance Of A K Length Subsequence

    // Solution class
    class Solution {

    public:
        long long findMaximumElegance(vector<vector<int>>& items, int k) {
            partial_sort(begin(items), begin(items) + k, end(items), greater<vector<int>>());
            vector<bool> lookup(size(items));
            vector<int> stk;
            int64_t curr = 0, l = 0;
            for (int i = 0; i < k; ++i) {
                if (lookup[items[i][1] - 1]) {
                    stk.emplace_back(items[i][0]);
                }
                curr += items[i][0];
                if (!lookup[items[i][1] - 1]) {
                    lookup[items[i][1] - 1] = true;
                    ++l;
                }
            }
            set<pair<int, int>> bst;
            vector<int> lookup2(size(items));
            for (int i = k; i < size(items); ++i) {
                const auto& p = items[i][0], &c = items[i][1];
                if (lookup[c - 1]) {
                    continue;
                }
                if (lookup2[c - 1]) {
                    if (lookup2[c - 1] >= p) {
                        continue;
                    }
                    bst.erase({lookup2[c - 1], c});
                }
                bst.emplace(p, c);
                lookup2[c - 1] = p;
                if (size(bst) > size(stk)) {
                    auto it = begin(bst);
                    lookup2[it->second - 1] = 0;
                    bst.erase(it);
                }
            }
            int64_t result = curr + l * l;
            for (auto rit = rbegin(bst); rit != rend(bst); ++rit) {
                curr += rit->first - stk.back(); stk.pop_back();
                ++l;
                result = max(result, curr + l * l);
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.findMaximumElegance(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_pROaPsFESkePq33i: Executed findMaximumElegance() from Maximum Elegance Of A K Length Subsequence" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_pROaPsFESkePq33i: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
