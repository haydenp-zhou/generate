#include "fun_5rAz3s3kv1DBVaYt.hpp"

int fun_5rAz3s3kv1DBVaYt() {
    // LeetCode Problem: Video Stitching

    // Solution class
    class Solution {

    public:
        int videoStitching(vector<vector<int>>& clips, int T) {

            //sort the clips
            std::sort(clips.begin(), clips.end(), [](vector<int>& x, vector<int>& y) {
                return x[0] < y[0] || (x[0] == y[0] && x[1] < y[1]);
            });

            //print(clips);

            // dynamic programming
            // dp[i] is the minmal clips from [o,i]

            vector<int> dp(T+1, -1);
            for (auto c : clips) {
                //edge case: out of the range
                if (c[0] > T) continue;

                // if clip is started from 0, then just simple initalize to 1
                if (c[0] == 0) {
                    for (int i=c[0]; i<=min(T,c[1]); i++) dp[i] = 1;
                    continue;
                }

                //if clip is not started from 0, seprate the range to two parts
                //the first part is the greater than 0, then second part is -1
                // 1) for the first part, need figure the minimal number
                // 2) for the second part, just simple add 1 with minimal number of first part.

                if (dp[c[0]] == -1 ) continue;

                int m = dp[c[0]];

                for (int i = c[0] + 1; i<= min(T, c[1]); i++) {
                    if ( dp[i] > 0 ) m = min(m, dp[i]);
                    else dp[i] = m + 1;
                }
            }

            //print(dp);
            return dp[T];
        }



        //used for debug
        void print(vector<vector<int>>& clips) {
            for (auto c : clips) {
                cout << "[" << c[0] <<","<< c[1] << "]"<< " ";
            }
            cout << endl;
        }

        void print(vector<int>& v) {
            for (auto i : v) {
                cout << i << ", ";
            }
            cout << endl;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.videoStitching(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_5rAz3s3kv1DBVaYt: Executed videoStitching() from Video Stitching" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_5rAz3s3kv1DBVaYt: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
