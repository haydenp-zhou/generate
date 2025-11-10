#include "fun_M0Gz5a1dBy2rE1Tq.hpp"

int fun_M0Gz5a1dBy2rE1Tq() {
    // LeetCode Problem: K Th Smallest Prime Fraction

    // Solution class
    class Solution {

    public:
        vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
            vector<int> result;
            double left = 0.0, right = 1.0;
            while (right - left > 1e-8) {
                double mid = left + (right - left) / 2.0;
                if (check(mid, A, K, &result)) {
                    right = mid;
                } else {
                    left = mid;
                }
                if (!result.empty()) {
                    break;
                }
            }
            return result;
        }

    private:
        bool check(double mid, const vector<int>& A, int K, vector<int> *result) {
            vector<int> tmp(2);
            int count = 0;
            for (int i = 0, j = 0; i < A.size(); ++i) {
                for (; j < A.size(); ++j) {
                    if (i < j && A[i] < A[j] * mid) {
                        if (tmp[0] == 0 || tmp[0] * A[j] < tmp[1] * A[i]) {
                            tmp[0] = A[i];
                            tmp[1] = A[j];
                        }
                        break;
                    }
                }
                count += A.size() - j;
            }
            if (count == K) {
                *result = move(tmp);
            }
            return count >= K;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.kthSmallestPrimeFraction(nums);

        // Print result to prevent optimization
        cout << "fun_M0Gz5a1dBy2rE1Tq: Executed kthSmallestPrimeFraction() from K Th Smallest Prime Fraction" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_M0Gz5a1dBy2rE1Tq: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
