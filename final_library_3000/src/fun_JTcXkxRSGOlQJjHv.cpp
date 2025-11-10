#include "fun_JTcXkxRSGOlQJjHv.hpp"

int fun_JTcXkxRSGOlQJjHv() {
    // LeetCode Problem: Count All Possible Routes

    // Solution class
    class Solution {

    public:
        int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
            static const int MOD = 1e9 + 7;

            int s = locations[start];
            int f = locations[finish];
            sort(begin(locations), end(locations));
            start = distance(cbegin(locations), lower_bound(cbegin(locations), cend(locations), s));
            finish = distance(cbegin(locations), lower_bound(cbegin(locations), cend(locations), f));

            vector<vector<int>> left(locations.size(), vector<int>(fuel + 1));  // left[i][f], last move is toward left to location i by f fuel
            vector<vector<int>> right(locations.size(), vector<int>(fuel + 1));  // right[i][f], last move is toward right to location i by f fuel
            for (int f = 1; f <= fuel; ++f) {
                for (int j = 0; j < locations.size() - 1; ++j) {
                    int d = locations[j + 1] - locations[j];
                    if (f > d) {
                        // left[j][f] = right[j+1][f-d(j, j+1)] + 2*right[j+2][f-d(j, j+2)] + ... + 2^(k-1)*right[j+k][f-d(j, j+k)]
                        // => left[j+1][f] = (ight[j+2][f-d(j+1, j+2)] + 2*right[j+3][f-d(j+1, j+3)] + ... + 2^(k-2)*right[j+1+k-1][f-d(j+1, j+1+k-1)]
                        // => left[j+1][f-d(j, j+1)] = right[j+2][f-d(j, j+2)] + 2*right[j+3][f-d(j, j+3)] + ... + 2^(k-2)*right[j+k][f-d(j, j+k)]
                        // => left[j][f] = right[j+1][f-d(j, j+1)] + 2*left[j+1][f-d(j, j+1)]
                        left[j][f] = (right[j + 1][f - d] + 2 * left[j + 1][f - d] % MOD) % MOD;
                    } else if (f == d) {
                        left[j][f] = int(j + 1 == start);
                    }
                }
                for (int j = 1; j < locations.size(); ++j) {
                    int d = locations[j] - locations[j - 1];
                    if (f > d) {
                        // right[j][f] = left[j-1][f-d(j, j-1)] + 2*left[j-2][f-d(j, j-2)] + ... + 2^(k-1)*left[j-k][f-d(j, j-k)]
                        // => right[j-1][f] = left[j-2][f-d(j-1, j-2)] + 2*left[j-3][f-d(j-1, j-3)] + ... + 2^(k-2)*left[j-1-k+1][f-d(j-1, j-1-k+1)]
                        // => right[j-1][f-d(j, j-1)] = left[j-2][f-d(j, j-2)] + 2*left[j-3][f-d(j, j-3)] + ... + 2^(k-2)*left[j-k][f-d(j, j-k)]
                        // => right[j][f] = left[j-1][f-d(j, j-1)] + 2*right[j-1][f-d(j, j-1)]
                        right[j][f] = (left[j - 1][f - d] + 2 * right[j - 1][f - d] % MOD) % MOD;
                    } else if (f == d) {
                        right[j][f] = int(j - 1 == start);
                    }
                }
            }
            int result = int(start == finish);
            for (int f = 1; f <= fuel; ++f) {
                result = ((result + left[finish][f]) % MOD + right[finish][f]) % MOD;
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.countRoutes(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_JTcXkxRSGOlQJjHv: Executed countRoutes() from Count All Possible Routes" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_JTcXkxRSGOlQJjHv: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
