#include "fun_A1JLixtWtWIoXQOM.hpp"

int fun_A1JLixtWtWIoXQOM() {
    // LeetCode Problem: Probability Of A Two Boxes Having The Same Number Of Distinct Balls

    // Solution class
    class Solution {

    public:
        double getProbability(vector<int>& balls) {
            unordered_map<pair<int, int>, uint64_t, PairHash<int>> dp;
            dp[pair(0, 0)] = 1;  // dp[i, j] is the ways of number difference i and color difference j
            for (const auto& n : balls) {  // O(k) times
                unordered_map<pair<int, int>, uint64_t, PairHash<int>> new_dp;
                for (const auto& kvp : dp) {  // O(k^2 * n) times
                    const auto& [ndiff, cdiff] = kvp.first;
                    for (int k = 0, new_count = 1; k <= n; ++k, new_count *= n - k + 1, new_count /= k) {  // O(n) times
                        const auto& new_ndiff = ndiff + (k - (n - k));
                        const auto& new_cdiff = (k == 0) ? cdiff - 1 : ((k == n) ? cdiff + 1 : cdiff);
                        new_dp[pair(new_ndiff, new_cdiff)] += kvp.second * new_count;
                    }
                }
                dp = move(new_dp);
            }
            const auto& total = accumulate(cbegin(balls), cend(balls), 0);
            return double(dp[pair(0, 0)]) / nCr(total, total / 2);
        }

    private:
        uint64_t nCr(int n, int r) {  // Time: O(n), Space: O(1)
            if (n - r < r) {
                return nCr(n, n - r);
            }
            uint64_t c = 1;
            for (int k = 1; k <= r; ++k) {
                c *= n - k + 1;
                c /= k;
            }
            return c;
        }

        template <typename T>
        struct PairHash {
            size_t operator()(const pair<T, T>& p) const {
                size_t seed = 0;
                seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
                seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
                return seed;
            }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.getProbability(nums);

        // Print result to prevent optimization
        cout << "fun_A1JLixtWtWIoXQOM: Executed getProbability() from Probability Of A Two Boxes Having The Same Number Of Distinct Balls" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_A1JLixtWtWIoXQOM: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
