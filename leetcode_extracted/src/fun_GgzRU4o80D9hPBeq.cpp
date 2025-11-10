#include "fun_GgzRU4o80D9hPBeq.hpp"

int fun_GgzRU4o80D9hPBeq() {
    // LeetCode Problem: Add To Array Form Of Integer

    // Solution class
    class Solution {

    public:
        vector<int> addToArrayForm(vector<int>& A, int K) {
            reverse(A.begin(), A.end());
            int carry = K, i = 0;
            A[i] += carry;
            carry = A[i] / 10;
            A[i] %= 10;
            while (carry) {
                ++i;
                if (i < A.size()) {
                    A[i] += carry;
                } else {
                    A.emplace_back(carry);
                }
                carry = A[i] / 10;
                A[i] %= 10;
            }
            reverse(A.begin(), A.end());
            return A;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.addToArrayForm(nums);

        // Print result to prevent optimization
        cout << "fun_GgzRU4o80D9hPBeq: Executed addToArrayForm() from Add To Array Form Of Integer" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_GgzRU4o80D9hPBeq: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
