#include "fun_z0Y3BGr2o0ZH2MT3.hpp"

int fun_z0Y3BGr2o0ZH2MT3() {
    // LeetCode Problem: Cracking The Safe

    // Solution class
    class Solution {

    public:
        string crackSafe(int n, int k) {
            const int M = pow(k, n - 1);
            vector<int> P;
            for (int i = 0; i < k; ++i) {
                for (int q = 0; q < M; ++q) {
                    P.emplace_back(q * k + i);  // rotate: i*k^(n-1) + q => q*k + i
                }
            }
            const int total = pow(k, n);
            string result(n - 1, '0' + k - 1);
            for (int i = 0; i < total; ++i) {
                int j = i;
                // concatenation in lexicographic order of Lyndon words
                while (P[j] >= 0) {
                    result.push_back('0' + j / M);
                    auto Pj = P[j];
                    P[j] = -1;
                    j = Pj;
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.crackSafe(nums);

        // Print result to prevent optimization
        cout << "fun_z0Y3BGr2o0ZH2MT3: Executed crackSafe() from Cracking The Safe" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_z0Y3BGr2o0ZH2MT3: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
