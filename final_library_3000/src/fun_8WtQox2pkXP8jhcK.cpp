#include "fun_8WtQox2pkXP8jhcK.hpp"

int fun_8WtQox2pkXP8jhcK() {
    // LeetCode Problem: Binary Watch

    // Solution class
    class Solution {

    public:
        vector<string> readBinaryWatch(int num) {
            vector<string> result;
            for (int h = 0; h < 12; ++h) {
                for (int m = 0; m < 60; ++m) {
                    if (bit_count(h) + bit_count(m) == num) {
                        const auto hour = to_string(h);
                        const auto minute = m < 10 ? "0" + to_string(m) : to_string(m);
                        result.emplace_back(hour + ":" + minute);
                    }
                }
            }
            return result;
        }

    private:
        int bit_count(int bits) {
            int count = 0;
            for (; bits; bits &= bits - 1) {
                ++count;
            }
            return count;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.readBinaryWatch(strs);

        // Print result to prevent optimization
        cout << "fun_8WtQox2pkXP8jhcK: Executed readBinaryWatch() from Binary Watch" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_8WtQox2pkXP8jhcK: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
