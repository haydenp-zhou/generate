#include "fun_l4ukqIPznNXf2WLm.hpp"

int fun_l4ukqIPznNXf2WLm() {
    // LeetCode Problem: Minimum Sum Of Four Digit Number After Splitting Digits

    // Solution class
    class Solution {

    public:
        int minimumSum(int num) {
            vector<int> nums;
            for (; num; num /= 10) {
                nums.emplace_back(num % 10);
            }
            inplace_counting_sort(&nums, false);
            int a = 0, b = 0;
            for (const auto& x: nums) {
                a = a * 10 + x;
                swap(a, b);
            }
            return a + b;
        }

    private:
        void inplace_counting_sort(vector<int> *nums, bool is_reverse) {
            const int max_num = *max_element(cbegin(*nums), cend(*nums));
            vector<int> count(max_num + 1);
            for (const auto& num : *nums) {
                ++count[num];
            }
            for (int i = 1; i < size(count); ++i) {
                count[i] += count[i - 1];
            }
            for (int i = size(*nums) - 1; i >= 0; --i) {  // inplace but unstable sort
                while ((*nums)[i] >= 0) {
                    --count[(*nums)[i]];
                    const int j = count[(*nums)[i]];
                    tie((*nums)[i], (*nums)[j]) = pair((*nums)[j], ~(*nums)[i]);
                }
            }
            for (auto& num : *nums) {
                num = ~num;  // restore values
            }
            if (is_reverse) {  // unstable sort
                reverse(begin(*nums), end(*nums));
            }
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minimumSum(nums);

        // Print result to prevent optimization
        cout << "fun_l4ukqIPznNXf2WLm: Executed minimumSum() from Minimum Sum Of Four Digit Number After Splitting Digits" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_l4ukqIPznNXf2WLm: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
