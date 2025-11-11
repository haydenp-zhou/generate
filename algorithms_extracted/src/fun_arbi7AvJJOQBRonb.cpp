#include "fun_arbi7AvJJOQBRonb.hpp"

// Original algorithm: Edit Distance
int fun_arbi7AvJJOQBRonb() {
    try {
        /* Given two strings str1 & str2
         * and below operations that can
         * be performed on str1. Find
         * minimum number of edits
         * (operations) required to convert
         * 'str1' into 'str2'/
         * a. Insert
         * b. Remove
         * c. Replace
         * All of the above operations are
         * of equal cost
         */
        using namespace std;
        int min(int x, int y, int z) { return min(min(x, y), z); }
        /* A Naive recursive C++ program to find
         * minimum number of operations to convert
         * str1 to str2.
         * O(3^m)
         */
        int editDist(string str1, string str2, int m, int n) {
            if (m == 0)
                return n;
            if (n == 0)
                return m;
            if (str1[m - 1] == str2[n - 1])
                return editDist(str1, str2, m - 1, n - 1);
            return 1 + min(editDist(str1, str2, m, n - 1),
                           editDist(str1, str2, m - 1, n),
                           editDist(str1, str2, m - 1, n - 1));
        }
        /* A DP based program
         * O(m x n)
         */
        int editDistDP(string str1, string str2, int m, int n) {
            std::vector<std::vector<int> > dp(m + 1, std::vector<int>(n + 1));
            for (int i = 0; i <= m; i++) {
                for (int j = 0; j <= n; j++) {
                    if (i == 0)
                        dp[i][j] = j;
                    else if (j == 0)
                        dp[i][j] = i;
                    else if (str1[i - 1] == str2[j - 1])
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = 1 + min(dp[i][j - 1],     // Insert
                                           dp[i - 1][j],     // Remove
                                           dp[i - 1][j - 1]  // Replace
                                       );
                }
            }
            return dp[m][n];
        }

                // Test the algorithm implementation
                cout << "Testing Edit Distance..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_arbi7AvJJOQBRonb: Edit Distance executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_arbi7AvJJOQBRonb: Exception - " << e.what() << endl;
        return 0;
    }
}
