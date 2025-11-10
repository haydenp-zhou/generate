#include "fun_abDnXbLvSbcbj8eb.hpp"

int fun_abDnXbLvSbcbj8eb() {
    // LeetCode Problem: Find Minimum Time To Finish All Jobs

    // Solution class
    class Solution {

    public:
        int minimumTimeRequired(vector<int>& jobs, int k) {
            sort(begin(jobs), end(jobs), greater<int>());
            int left = *max_element(cbegin(jobs), cend(jobs));
            int right = accumulate(cbegin(jobs), cend(jobs), 0);
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                vector<int> counts(k);
                if (backtracking(jobs, 0, mid, &counts)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }

    private:
        bool backtracking(const vector<int>& jobs,
                          int i, int cap,
                          vector<int> *counts) {
            if (i == size(jobs)) {
                return true;
            }
            for (int j = 0; j < size(*counts); ++j) {
                if ((*counts)[j] + jobs[i] <= cap) {
                    (*counts)[j] += jobs[i];
                    if (backtracking(jobs, i + 1, cap, counts)) {
                        return true;
                    }
                    (*counts)[j] -= jobs[i];
                }
                if ((*counts)[j] == 0) {
                    break;
                }
            }
            return false;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minimumTimeRequired(nums);

        // Print result to prevent optimization
        cout << "fun_abDnXbLvSbcbj8eb: Executed minimumTimeRequired() from Find Minimum Time To Finish All Jobs" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_abDnXbLvSbcbj8eb: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
