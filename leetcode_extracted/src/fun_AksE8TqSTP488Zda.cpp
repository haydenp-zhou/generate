#include "fun_AksE8TqSTP488Zda.hpp"

int fun_AksE8TqSTP488Zda() {
    // LeetCode Problem: Arithmetic Subarrays

    // Solution class
    class Solution {

    public:
        vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
            vector<bool> result(size(l));
            for (int i = 0; i < size(l); ++i) {
                result[i] = isArith(vector<int>(cbegin(nums) + l[i], cbegin(nums) + r[i] + 1));
            }
            return result;
        }

    private:
        bool isArith(const vector<int>& nums) {
            unordered_set<int> lookup(cbegin(nums), cend(nums));
            int mn = *min_element(cbegin(nums), cend(nums));
            int mx = *max_element(cbegin(nums), cend(nums));
            if (mx == mn) {
                return true;
            }
            if ((mx - mn) % (size(nums) - 1)) {
                return false;
            }
            int d = (mx - mn) / (size(nums) - 1);
            for (int i = mn; i <= mx; i += d) {
                if (!lookup.count(i)) {
                    return false;
                }
            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.checkArithmeticSubarrays(nums);

        // Print result to prevent optimization
        cout << "fun_AksE8TqSTP488Zda: Executed checkArithmeticSubarrays() from Arithmetic Subarrays" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_AksE8TqSTP488Zda: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
