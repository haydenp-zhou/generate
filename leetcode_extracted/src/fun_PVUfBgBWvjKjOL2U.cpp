#include "fun_PVUfBgBWvjKjOL2U.hpp"

int fun_PVUfBgBWvjKjOL2U() {
    // LeetCode Problem: Maximum Number Of Subsequences After One Inserting

    // Solution class
    class Solution {

    public:
        long long numOfSubsequences(string s) {
            int64_t cnt_l = 0, cnt_c = 0;
            int64_t cnt_t = count(cbegin(s), cend(s), 'T');
            int64_t mx_cnt_lt = 0, cnt_lct = 0, cnt_lc = 0, cnt_ct = 0;
            for (const auto& x : s) {
                mx_cnt_lt = max(mx_cnt_lt, cnt_l * cnt_t);
                if (x == 'L') {
                    ++cnt_l;
                } else if (x == 'C') {
                    ++cnt_c;
                    cnt_lc += cnt_l;
                } else if (x == 'T') {
                    --cnt_t;
                    cnt_ct += cnt_c;
                    cnt_lct += cnt_lc;
                }
            }
            mx_cnt_lt = max(mx_cnt_lt, cnt_l * cnt_t);
            return cnt_lct + max({cnt_ct, mx_cnt_lt, cnt_lc});
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.numOfSubsequences(s);

        // Print result to prevent optimization
        cout << "fun_PVUfBgBWvjKjOL2U: Executed numOfSubsequences() from Maximum Number Of Subsequences After One Inserting" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_PVUfBgBWvjKjOL2U: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
