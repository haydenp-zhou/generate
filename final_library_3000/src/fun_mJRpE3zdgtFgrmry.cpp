#include "fun_mJRpE3zdgtFgrmry.hpp"

// Original algorithm: Longest Common Subsequence
int fun_mJRpE3zdgtFgrmry() {
    try {
        using namespace std;
        void Print(int trace[20][20], int m, int n, string a) {
            if (m == 0 || n == 0) {
                return;
            }
            if (trace[m][n] == 1) {
                Print(trace, m - 1, n - 1, a);
                cout << a[m - 1];
            } else if (trace[m][n] == 2) {
                Print(trace, m - 1, n, a);
            } else if (trace[m][n] == 3) {
                Print(trace, m, n - 1, a);
            }
        }
        int lcs(string a, string b) {
            int m = a.length(), n = b.length();
            std::vector<std::vector<int> > res(m + 1, std::vector<int>(n + 1));
            int trace[20][20];
            for (int i = 0; i < m + 1; i++) {
                for (int j = 0; j < n + 1; j++) {
                    res[i][j] = 0;
                    trace[i][j] = 0;
                }
            }
            for (int i = 0; i < m + 1; ++i) {
                for (int j = 0; j < n + 1; ++j) {
                    if (i == 0 || j == 0) {
                        res[i][j] = 0;
                        trace[i][j] = 0;
                    }
                    else if (a[i - 1] == b[j - 1]) {
                        res[i][j] = 1 + res[i - 1][j - 1];
                        trace[i][j] = 1;  // 1 means trace the matrix in upper left
                    } else {
                        if (res[i - 1][j] > res[i][j - 1]) {
                            res[i][j] = res[i - 1][j];
                            trace[i][j] =
                                2;  // 2 means trace the matrix in upwards direction.
                        } else {
                            res[i][j] = res[i][j - 1];
                            trace[i][j] =
                                3;  //  means trace the matrix in left direction.
                        }
                    }
                }
            }
            Print(trace, m, n, a);
            return res[m][n];
        }

                // Test the algorithm implementation
                cout << "Testing Longest Common Subsequence..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_mJRpE3zdgtFgrmry: Longest Common Subsequence executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_mJRpE3zdgtFgrmry: Exception - " << e.what() << endl;
        return 0;
    }
}
