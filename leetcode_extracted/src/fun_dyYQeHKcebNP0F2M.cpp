#include "fun_dyYQeHKcebNP0F2M.hpp"

int fun_dyYQeHKcebNP0F2M() {
    // LeetCode Problem: Subarrays With K Different Integers

    // Solution class
    class Solution {

    public:
        int subarraysWithKDistinct(vector<int>& A, int K) {
            return atMostK(A, K) - atMostK(A, K - 1);
        }

    private:
        int atMostK(const vector<int>& A, int K) {
            int result = 0, left = 0;
            unordered_map<int, int> count;
            for (int right = 0; right < A.size(); ++right) {
                ++count[A[right]];
                while (count.size() > K) {
                    if (!--count[A[left]]) {
                        count.erase(A[left]);
                    }
                    ++left;
                }
                result += right - left + 1;
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
        volatile auto result = sol.subarraysWithKDistinct(nums);

        // Print result to prevent optimization
        cout << "fun_dyYQeHKcebNP0F2M: Executed subarraysWithKDistinct() from Subarrays With K Different Integers" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_dyYQeHKcebNP0F2M: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
