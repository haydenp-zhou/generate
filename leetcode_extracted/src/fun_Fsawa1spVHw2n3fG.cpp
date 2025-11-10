#include "fun_Fsawa1spVHw2n3fG.hpp"

int fun_Fsawa1spVHw2n3fG() {
    // LeetCode Problem: Minimum Operations To Make Elements Within K Subarrays Equal

    // Solution class
    class Solution {

    public:
        long long minOperations(vector<int>& nums, int x, int k) {
            static const int64_t INF = numeric_limits<int64_t>::max();

            Slidingsw sw;
            vector<int64_t> cost(size(nums) + 1, INF);
            for (int i = 0; i < size(nums); ++i) {
                if (i - x >= 0) {
                    sw.remove(nums[i - x]);
                }
                sw.add(nums[i]);
                if (i >= x - 1) {
                    cost[i + 1] = (sw.median() * size(sw.left) - sw.total1) + (sw.total2 - sw.median() * size(sw.right));
                }
            }
            vector<int64_t> dp(size(nums) + 1);
            for (int i = 0; i < k; ++i) {
                vector<int64_t> new_dp(size(nums) + 1, INF);
                for (int j = (i + 1) * x; j <= size(nums); ++j) {
                    if (dp[j - x] != INF) {
                        new_dp[j] = min(new_dp[j - 1], dp[j - x] + cost[j]);
                    }
                }
                dp = move(new_dp);
            }
            return dp.back();
        }

    private:
        struct Slidingsw {
            Slidingsw() {

            }

            void add(int val) {
                if (empty(left) || val <= *begin(left)) {
                    left.emplace(val);
                    total1 += val;
                } else {
                    right.emplace(val);
                    total2 += val;
                }
                rebalance();
            }

            void remove(int val) {
                if (val <= *begin(left)) {
                    left.erase(left.find(val));
                    total1 -= val;
                } else {
                    right.erase(right.find(val));
                    total2 -= val;
                }
                rebalance();
            }

            void rebalance() {
                if (size(left) < size(right)) {
                    total2 -= *begin(right);
                    total1 += *begin(right);
                    left.emplace(*begin(right));
                    right.erase(begin(right));
                } else if (size(left) > size(right) + 1) {
                    total1 -= *begin(left);
                    total2 += *begin(left);
                    right.emplace(*begin(left));
                    left.erase(begin(left));
                }
            }

            int median() {
                return *begin(left);
            }

            multiset<int, greater<int>> left;
            multiset<int, less<int>> right;
            int64_t total1 = 0;
            int64_t total2 = 0;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minOperations(nums);

        // Print result to prevent optimization
        cout << "fun_Fsawa1spVHw2n3fG: Executed minOperations() from Minimum Operations To Make Elements Within K Subarrays Equal" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Fsawa1spVHw2n3fG: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
