#include "fun_isi9SJAUcbtseXM1.hpp"

int fun_isi9SJAUcbtseXM1() {
    // LeetCode Problem: Earliest Second To Mark Indices I

    // Solution class
    class Solution {

    public:
        int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
            const auto& check = [&](int t) {
                vector<int> lookup(size(nums), -1);
                for (int i = 0; i < t; ++i) {
                    lookup[changeIndices[i] - 1] = i;
                }
                if (count(cbegin(lookup), cend(lookup), -1)) {
                    return false;
                }
                for (int i = 0, cnt = 0; i < t; ++i) {
                    if (i != lookup[changeIndices[i] - 1]) {
                        ++cnt;
                        continue;
                    }
                    cnt -= nums[changeIndices[i] - 1];
                    if (cnt < 0) {
                        return false;
                    }
                }
                return true;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.earliestSecondToMarkIndices(nums);

        // Print result to prevent optimization
        cout << "fun_isi9SJAUcbtseXM1: Executed earliestSecondToMarkIndices() from Earliest Second To Mark Indices I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_isi9SJAUcbtseXM1: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
