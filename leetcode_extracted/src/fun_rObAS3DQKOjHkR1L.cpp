#include "fun_rObAS3DQKOjHkR1L.hpp"

int fun_rObAS3DQKOjHkR1L() {
    // LeetCode Problem: Abbreviating The Product Of A Range

    // Solution class
    class Solution {

    public:
        string abbreviateProduct(int left, int right) {
            static const int PREFIX_LEN = 5;
            static const int SUFFIX_LEN = 5;
            static const int64_t MOD = pow(10, PREFIX_LEN + SUFFIX_LEN);

            int64_t curr = 1, zeros = 0;
            bool abbr = false;
            double decimal = 0.0;
            for (int64_t i = left; i <= right; ++i, curr %= MOD) {
                curr *= i;
                decimal += log10(i);
                while (curr % 10 == 0) {
                    curr /= 10;
                    ++zeros;
                }            
                if (curr >= MOD) {
                    abbr = true;
                }
            }  
            if (!abbr) {
                return to_string(curr) + "e" + to_string(zeros);
            }
            decimal -= int(decimal);
            const auto& prefix = to_string(static_cast<int>(pow(10, decimal + (PREFIX_LEN - 1))));
            const auto& suffix = to_string(curr % static_cast<int>(pow(10, SUFFIX_LEN)));
            return prefix + "..." + string(SUFFIX_LEN - size(suffix), '0') + suffix + "e" + to_string(zeros);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.abbreviateProduct(s);

        // Print result to prevent optimization
        cout << "fun_rObAS3DQKOjHkR1L: Executed abbreviateProduct() from Abbreviating The Product Of A Range" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_rObAS3DQKOjHkR1L: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
