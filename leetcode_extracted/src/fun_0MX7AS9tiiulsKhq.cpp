#include "fun_0MX7AS9tiiulsKhq.hpp"

int fun_0MX7AS9tiiulsKhq() {
    // LeetCode Problem: Count  Different  Palindromic  Subsequences

    // Solution class
    class Solution {

    public:
        int countPalindromicSubsequences(string s) {
            long n=s.size();
            // Created a db and initialize to 0
            long dp[n][n];
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dp[i][j]=0;
                }
            }

            for(int i=n-1;i>=0;i--)
            {
                for(int j=i;j<n;j++)
                {
                    if(i==j)
                        dp[i][j]=1; // every char of s is a palindrome
                    else if(s[i] == s[j]) //if 2 char matched, we have the ans of dp[i+1][j-1], lets find for dp[i][j] from dp[i+1][j-1]
                    {
                        int low = i+1;
                        int high = j-1;
                        // checking is any char is there in between i, j
                        while(low<j && s[low]!=s[j]){
                            low++;
                        }
                        while(high>i && s[high]!=s[j]){
                            high--;
                        }

                        if(low>high)
                        {
                            dp[i][j] = dp[i+1][j-1]*2 + 2;  // no other same char is there..between i, j
                                                            // in case bccb,i=0,j=3, dp[1][2] = 2(c, cc)...so, dp[0][3] = 2*2+2(b, bcb, bccb, c, cc, bb)
                        }
                        else if(low == high)
                        {
                            dp[i][j] = dp[i+1][j-1]*2 + 1;  // 1 same char is there..between i, j
                        }                                   // in case bcbb,i=0,j=3, dp[1][2] = 2(c, b)...so, dp[0][3] = 2*2+1(b, bcb, bb, c, bbb)
                        else
                        {
                            dp[i][j] = (dp[i+1][j-1]*2 - dp[low+1][high-1]); // more than 1 same char is there..between i, j
                                                                             // in case bbbb,i=0,j=3, dp[1][2] = 2(b, bb)...so, dp[0][3] = 2*2 - 0(b, bb, bbb, bbbb)
                        }
                    }
                    else
                    {
                        dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1]; //edge chars does not mach... 
                    }                                                      // in case abcd,i=0,j=3, dp[0][2] = 3, dp[1][3] = 3, dp[1][2] = 2...so, dp[0][3] = 3 + 3 - 2(a, b, c, d)

                    // just safe..as we are subtracting..earlier in code 
                    if(dp[i][j]<0)
                        dp[i][j]+=1000000007;

                    dp[i][j]=dp[i][j]%1000000007; // ans could be very big

                }

            }
            return dp[0][n-1];//ans
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.countPalindromicSubsequences(s);

        // Print result to prevent optimization
        cout << "fun_0MX7AS9tiiulsKhq: Executed countPalindromicSubsequences() from Count  Different  Palindromic  Subsequences" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_0MX7AS9tiiulsKhq: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
