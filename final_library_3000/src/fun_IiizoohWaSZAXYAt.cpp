#include "fun_IiizoohWaSZAXYAt.hpp"

int fun_IiizoohWaSZAXYAt() {
    // LeetCode Problem: Maximum Total Importance Of Roads

    // Solution class
    class Solution {

    public:
        long long maximumImportance(int n, vector<vector<int>>& roads) {
            vector<int> degree(n);
            for (const auto& r : roads) {
                ++degree[r[0]];
                ++degree[r[1]];
            }
            inplace_counting_sort(&degree, false);
            int64_t result = 0;
            for (int i = 0; i < n; ++i) {
                result += (i + 1ll) * degree[i];
            }
            return result;
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
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.maximumImportance(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_IiizoohWaSZAXYAt: Executed maximumImportance() from Maximum Total Importance Of Roads" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_IiizoohWaSZAXYAt: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
