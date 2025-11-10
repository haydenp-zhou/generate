#include "fun_9eNY9mO02G1aj5fq.hpp"

int fun_9eNY9mO02G1aj5fq() {
    // LeetCode Problem: Minimum Number Of Swaps To Make The Binary String Alternating

    // Solution class
    class Solution {

    public:
        int minSwaps(string s) {
            int ones = count(cbegin(s), cend(s), '1');
            int zeros = size(s) - ones;
            if (abs(ones - zeros) > 1) {
                return -1;
            }
            if (ones > zeros) {
                return cost(s, 1);
            }
            if (ones < zeros) {
                return cost(s, 0);
            }
            return min(cost(s, 1), cost(s, 0));
        }

    private:
        int cost(const string& s, int x) {
            int diff = 0;
            for (const auto& c : s) {
                diff += (c - '0' != x);
                x ^= 1;
            }
            return diff / 2;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.minSwaps(s);

        // Print result to prevent optimization
        cout << "fun_9eNY9mO02G1aj5fq: Executed minSwaps() from Minimum Number Of Swaps To Make The Binary String Alternating" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_9eNY9mO02G1aj5fq: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
