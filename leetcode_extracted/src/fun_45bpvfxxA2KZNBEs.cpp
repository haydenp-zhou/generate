#include "fun_45bpvfxxA2KZNBEs.hpp"

int fun_45bpvfxxA2KZNBEs() {
    // LeetCode Problem: Maximum Number Of Intersections On The Chart

    // Solution class
    class Solution {

    public:
        int maxIntersectionCount(vector<int>& y) {
            unordered_set<int> set_y(cbegin(y), cend(y));
            vector<int> sorted_set_y(cbegin(set_y), cend(set_y));
            sort(begin(sorted_set_y), end(sorted_set_y));
            unordered_map<int, int> val_to_idx;
            for (int i = 0; i < size(sorted_set_y); ++i) {
                val_to_idx[sorted_set_y[i]] = i;
            }
            vector<int> cnts(2 * size(val_to_idx) + 1);
            for (int i = 0; i + 1 < size(y); ++i) {
                // [y[i], y[i+1]) <=> [y[i], y[i+1]-0.5] <=> [2*y[i], 2*y[i+1]-1]
                const int left = 2 * val_to_idx[y[i]], right = 2 * val_to_idx[y[i + 1]] + (y[i] < y[i + 1] ? -1 : +1);
                ++cnts[min(left, right)];
                --cnts[max(left, right) + 1];
            }
            // [y[i], y[i]] <=> [2*y[i], 2*y[i]]
            ++cnts[2 * val_to_idx[y.back()]];
            --cnts[2 * val_to_idx[y.back()] + 1];
            int result = 0, cnt = 0;
            for (const auto& c : cnts) {
                cnt += c;
                result = max(result, cnt);
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
        volatile auto result = sol.maxIntersectionCount(nums);

        // Print result to prevent optimization
        cout << "fun_45bpvfxxA2KZNBEs: Executed maxIntersectionCount() from Maximum Number Of Intersections On The Chart" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_45bpvfxxA2KZNBEs: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
