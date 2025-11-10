#include "fun_eFlbCNvZnzIYrRED.hpp"

int fun_eFlbCNvZnzIYrRED() {
    // LeetCode Problem: Reverse Pairs

    // Solution class
    class Solution {

    public:
        int reversePairs(vector<int>& nums) {
            return countAndMergeSort(nums.begin(), nums.end());
        }

    private:
        int countAndMergeSort(vector<int>::iterator begin, vector<int>::iterator end) {
            if (end - begin <= 1) {
                return 0;
            }
            auto mid = begin + (end - begin) / 2;
            int count = countAndMergeSort(begin, mid) + countAndMergeSort(mid, end);
            for (auto i = begin, j = mid; i != mid; ++i) {
                while (j != end && *i > 2L * *j) {
                    ++j;
                }
                count += j - mid;
            }
            inplace_merge(begin, mid, end);
            return count;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.reversePairs(nums);

        // Print result to prevent optimization
        cout << "fun_eFlbCNvZnzIYrRED: Executed reversePairs() from Reverse Pairs" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_eFlbCNvZnzIYrRED: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
