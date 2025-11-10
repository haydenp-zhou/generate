#include "fun_Y2At5SMzmoyAZzcT.hpp"

int fun_Y2At5SMzmoyAZzcT() {
    // LeetCode Problem: Triples With Bitwise And Equal To Zero

    // Solution class
    class Solution {

    public:
        int countTriplets(vector<int>& A) {
            static const int k = 3;
            const auto max_A = *max_element(A.cbegin(), A.cend());
            int n = 1;
            for (; n <= max_A; n <<= 1);
            vector<int> B(n); 
            for (const auto& x : A) {
                ++B[x];
            }

            FWT(&B, 1);
            for(auto& x : B) {
                x = pow(x, k);
            }
            FWT(&B, -1);

            return B[0];
        }

    private:
        void FWT(vector<int> *A, int v) {
            for (int d = 1; d < A->size(); d <<= 1) {
                for (int m = d << 1, i = 0; i < A->size(); i += m) {
                    for (int j = 0; j < d ; ++j) {  
                        (*A)[i + j] += (*A)[i + j + d] * v;
                    }
                }  
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
        volatile auto result = sol.countTriplets(nums);

        // Print result to prevent optimization
        cout << "fun_Y2At5SMzmoyAZzcT: Executed countTriplets() from Triples With Bitwise And Equal To Zero" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Y2At5SMzmoyAZzcT: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
