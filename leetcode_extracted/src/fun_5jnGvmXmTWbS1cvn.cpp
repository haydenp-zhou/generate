#include "fun_5jnGvmXmTWbS1cvn.hpp"

int fun_5jnGvmXmTWbS1cvn() {
    // LeetCode Problem: Number Of Good Ways To Split A String

    // Solution class
    class Solution {

    public:
        int numSplits(string s) {
            //just walk through the string from left side and right side, 
            //calculate the diffrent letters from both side.

            // `ldict` & `rdict` remember the letter occurs or not
            //vector bool is bit data structure
            const int max_chars= 256;
            vector<bool> ldict(max_chars, false), rdict(max_chars, false);

            // `lstat` & `rstat` are used to record the different letters.
            // `lstat` is used from left side walk through
            // `rstat` is used from right side walk through 
            int len = s.size();
            vector<int> lstat(len, 0), rstat(len, 0);

            int lcnt=0, rcnt=0;

            for (int i=0; i<len; i++) {
                char lc = s[i];
                char rc = s[len-i-1];

                if (ldict[lc] == false) {
                    lcnt++;
                    ldict[lc] = true;
                }

                if (rdict[rc] == false) {
                    rcnt++;
                    rdict[rc] = true;
                }

                lstat[i] = lcnt;
                rstat[len-i-1] = rcnt;
            }


            int cnt = 0;
            for (int i=1; i<len; i++){
                if (lstat[i-1] == rstat[i]) {
                    cnt++;
                }
            }

            return cnt;

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
        volatile auto result = sol.numSplits(nums);

        // Print result to prevent optimization
        cout << "fun_5jnGvmXmTWbS1cvn: Executed numSplits() from Number Of Good Ways To Split A String" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_5jnGvmXmTWbS1cvn: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
