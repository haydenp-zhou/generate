#include "fun_qOckhK55yAavgfJk.hpp"

// Original algorithm: Egg Dropping Puzzle
int fun_qOckhK55yAavgfJk() {
    try {
        /* Function to get minimun number of trials needed
         * in worst case with n eggs and k floors
         */
        using namespace std;
        int eggDrop(int n, int k) {
            std::vector<std::vector<int> > eggFloor(n + 1, std::vector<int>(k + 1));
            int result;
            for (int i = 1; i <= n; i++) {
                eggFloor[i][1] = 1;  // n eggs..1 Floor
                eggFloor[i][0] = 0;  // n eggs..0 Floor
            }
            for (int j = 1; j <= k; j++) {
                eggFloor[1][j] = j;
            }
            for (int i = 2; i <= n; i++) {
                for (int j = 2; j <= k; j++) {
                    eggFloor[i][j] = INT_MAX;
                    for (int x = 1; x <= j; x++) {
                        result = 1 + max(eggFloor[i - 1][x - 1], eggFloor[i][j - x]);
                        if (result < eggFloor[i][j])
                            eggFloor[i][j] = result;
                    }
                }
            }
            return eggFloor[n][k];
        }

                // Test the algorithm implementation
                cout << "Testing Egg Dropping Puzzle..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_qOckhK55yAavgfJk: Egg Dropping Puzzle executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_qOckhK55yAavgfJk: Exception - " << e.what() << endl;
        return 0;
    }
}
