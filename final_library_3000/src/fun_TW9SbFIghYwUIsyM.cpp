#include "fun_TW9SbFIghYwUIsyM.hpp"

int fun_TW9SbFIghYwUIsyM() {
    // LeetCode Problem: Summary Ranges

    // Solution class
    class Solution {

    public:
        string makeRange(int start, int end) {
            ostringstream oss;
            if (start != end) {
                oss << start << "->" << end;
            } else {
                oss << start;
            }
            return oss.str();
        }

        vector<string> summaryRanges(vector<int>& nums) {
            vector<string> result;
            int len = nums.size();
            if (len == 0) return result;

            // we have two pointer for range-starter and range-ender
            int start=nums[0], end=nums[0];

            for (int i=1; i<len; i++) {
                // if it is continous number, move the end pointer;
                if (nums[i] == end + 1) {
                    end = nums[i];
                    continue;
                }

                //if the number is not continous, push the range into result
                //and reset the start and end pointer
                result.push_back(makeRange(start, end));
                start = end = nums[i];

            }

            //for the last range
            result.push_back(makeRange(start, end)); 

            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.makeRange(nums);

        // Print result to prevent optimization
        cout << "fun_TW9SbFIghYwUIsyM: Executed makeRange() from Summary Ranges" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_TW9SbFIghYwUIsyM: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
