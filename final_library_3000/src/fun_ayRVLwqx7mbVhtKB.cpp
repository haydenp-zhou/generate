#include "fun_ayRVLwqx7mbVhtKB.hpp"

int fun_ayRVLwqx7mbVhtKB() {
    // LeetCode Problem: Android Unlock Patterns

    // Solution class
    class Solution {

    public:
        int numberOfPatterns(int m, int n) {
            // dp[i][j]: i is the set of the numbers in binary representation,
            //           dp[i][j] is the number of ways ending with the number j.
            vector<vector<int>> dp(1 << 9 , vector<int>(9, 0));
            for (int i = 0; i < 9; ++i) {
                dp[merge(0, i)][i] = 1;
            }

            int res = 0;
            for (int used = 0; used < dp.size(); ++used) {
                const auto number = number_of_keys(used);
                if (number > n) {
                    continue;
                }
                for (int i = 0; i < 9; ++i) {
                    if (!contain(used, i)) {
                        continue;
                    }
                    if (m <= number && number <= n) {
                        res += dp[used][i];
                    }

                    const auto x1 = i / 3;
                    const auto y1 = i % 3;
                    for (int j = 0; j < 9; ++j) {
                        if (contain(used, j)) {
                            continue;
                        }
                        const auto x2 = j / 3;
                        const auto y2 = j % 3;
                        if (((x1 == x2 && abs(y1 - y2) == 2) ||
                             (y1 == y2 && abs(x1 - x2) == 2) ||
                             (abs(x1 - x2) == 2 && abs(y1 - y2) == 2)) &&
                            !contain(used, convert((x1 + x2) / 2, (y1 + y2) / 2))) {
                                 continue;
                        }
                        dp[merge(used, j)][j] += dp[used][i];
                    }
                }
            }

            return res;
        }

    private:
        inline int merge(int i, int j) {
            return i | (1 << j);
        }

        inline int number_of_keys(int i) {
            int number = 0;
            for (; i; i &= i - 1) {
                ++number;
            }
            return number;
        }

        inline bool contain(int i, int j) {
            return i & (1 << j);
        }

        inline int convert(int i, int j) {
            return 3 * i + j;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.numberOfPatterns(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_ayRVLwqx7mbVhtKB: Executed numberOfPatterns() from Android Unlock Patterns" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_ayRVLwqx7mbVhtKB: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
