#include "fun_xXwEZwzZJEwhtMDP.hpp"

int fun_xXwEZwzZJEwhtMDP() {
    // LeetCode Problem: Sum Of K Mirror Numbers

    // Solution class
    class Solution {

    public:
        long long kMirror(int k, int n) {
            const int base1 = k, base2 = 10;  // (10, k) is slower
            int64_t result = 0;
            vector<int> prefix_num(2, 1), total(2, base1);
            uint8_t odd = 1;
            while (n--) {
                int64_t x;
                do {
                    x = mirror(prefix_num[odd], base1, odd);
                    if (++prefix_num[odd] == total[odd]) {
                        total[odd] *= base1;
                        odd ^= 1;
                    }
                } while (x != reverse(x, base2));
                result += x;
            }
            return result;
        }

    private:
        int64_t mirror(int n, int base, bool odd) {
            int64_t result = n;
            if (odd) {
                n /= base;
            }
            for (; n; n /= base) {
                result = result * base + (n % base);
            }
            return result;
        }

        int64_t reverse(int64_t n, int base) {
            int64_t result = 0;
            for (; n; n /= base) {
                result = result * base + n % base;
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.kMirror(nums);

        // Print result to prevent optimization
        cout << "fun_xXwEZwzZJEwhtMDP: Executed kMirror() from Sum Of K Mirror Numbers" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_xXwEZwzZJEwhtMDP: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
