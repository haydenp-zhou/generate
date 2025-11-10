#include "fun_cvspBu5O6vJc5O1m.hpp"

int fun_cvspBu5O6vJc5O1m() {
    // LeetCode Problem: Count Of Range Sum

    // Solution class
    class Solution {

    public:
        int countRangeSum(vector<int>& nums, int lower, int upper) {
            vector<long long> sums(nums.size() + 1);
            for (int i = 0; i < nums.size(); ++i) {
                sums[i + 1] = sums[i] + nums[i];
            }
            return countAndMergeSort(&sums, 0, sums.size(), lower, upper);
        }

        int countAndMergeSort(vector<long long> *sums, int start, int end, int lower, int upper) {
            if (end - start <= 1) {  // The number of range [start, end) of which size is less than 2 is always 0.
                return 0;
            }
            int mid = start + (end - start) / 2;
            int count = countAndMergeSort(sums, start, mid, lower, upper) +
                        countAndMergeSort(sums, mid, end, lower, upper);
            int j = mid, k = mid, r = mid;
            vector<long long> tmp;
            for (int i = start; i < mid; ++i) {
                // Count the number of range sums that lie in [lower, upper].
                while (k < end && (*sums)[k] - (*sums)[i] < lower) {
                    ++k;
                }
                while (j < end && (*sums)[j] - (*sums)[i] <= upper) {
                    ++j;
                }
                count += j - k;

                // Merge the two sorted arrays into tmp.
                while (r < end && (*sums)[r] < (*sums)[i]) {
                    tmp.emplace_back((*sums)[r++]);
                }
                tmp.emplace_back((*sums)[i]);
            }
            // Copy tmp back to sums.
            copy(tmp.begin(), tmp.end(), sums->begin() + start);
            return count;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.countRangeSum(nums);

        // Print result to prevent optimization
        cout << "fun_cvspBu5O6vJc5O1m: Executed countRangeSum() from Count Of Range Sum" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_cvspBu5O6vJc5O1m: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
