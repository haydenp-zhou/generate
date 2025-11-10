#include "fun_lMNfoZyeAFoiQXj0.hpp"

int fun_lMNfoZyeAFoiQXj0() {
    // LeetCode Problem: Maximum Total From Optimal Activation Order

    // Solution class
    class Solution {

    public:
        long long maxTotal(vector<int>& value, vector<int>& limit) {
            vector<int> idxs(size(value));
            iota(begin(idxs), end(idxs), 0);
            sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b) {
                return limit[a] != limit[b] ? limit[a] < limit[b] : value[a] > value[b];
            });
            int64_t result = 0;
            for (int i = 0, cnt = 0, prev = 0; i < size(idxs); ++i) {
                const auto& l = limit[idxs[i]];
                const auto& v = value[idxs[i]];
                if (l != prev) {
                    cnt = 0;
                    prev = l;
                }
                if (cnt < l) {
                    result += v;
                    ++cnt;
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
        volatile auto result = sol.maxTotal(nums);

        // Print result to prevent optimization
        cout << "fun_lMNfoZyeAFoiQXj0: Executed maxTotal() from Maximum Total From Optimal Activation Order" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_lMNfoZyeAFoiQXj0: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
