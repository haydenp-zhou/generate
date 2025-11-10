#include "fun_Qo5vjZUKqSWVGyLn.hpp"

int fun_Qo5vjZUKqSWVGyLn() {
    // LeetCode Problem: Repeated String Match

    // Solution class
    class Solution {

    public:
        int repeatedStringMatch(string A, string B) {
            static const uint64_t M = 1000000007;
            static const uint64_t p = 113; 
            static const uint64_t p_inv = pow(p, M - 2, M);

            const auto q = (B.length() + A.length() - 1) / A.length();

            uint64_t b_hash = 0, power = 1;
            for (int i = 0; i < B.length(); ++i) {
                b_hash += power * B[i];
                b_hash %= M;
                power = (power * p) % M;
            }

            uint64_t a_hash = 0; power = 1;
            for (int i = 0; i < B.length(); ++i) {
                a_hash += power * A[i % A.length()];
                a_hash %= M;
                power = (power * p) % M;
            }
            if (a_hash == b_hash && check(0, A, B)) {
                return q;
            }

            power = (power * p_inv) % M;
            for (int i = B.length(); i < (q + 1) * A.length(); ++i) {
                a_hash -= A[(i - B.length()) % A.length()];
                a_hash *= p_inv;
                a_hash += power * A[i % A.length()];
                a_hash %= M;
                if (a_hash == b_hash && check(i - B.length() + 1, A, B)) {
                    return i < q * A.length() ? q : q + 1;
                }
            }
            return -1;
        }

    private:
        bool check(int index, const string& A, const string& B) {
            for (int i = 0; i < B.length(); ++i) {
                if (A[(i + index) % A.length()] != B[i]) {
                    return false;
                }
            }
            return true;
        }

        uint64_t pow(uint64_t a,uint64_t b, uint64_t m) {
            a %= m;
            uint64_t result = 1;
            while (b) {
                if (b & 1) {
                    result = (result * a) % m;
                }
                a = (a * a) % m;
                b >>= 1;
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.repeatedStringMatch(s);

        // Print result to prevent optimization
        cout << "fun_Qo5vjZUKqSWVGyLn: Executed repeatedStringMatch() from Repeated String Match" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Qo5vjZUKqSWVGyLn: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
