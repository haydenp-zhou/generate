#include "fun_XEblBpGylyCYcR2m.hpp"

int fun_XEblBpGylyCYcR2m() {
    // LeetCode Problem: Number Of Squareful Arrays

    // Solution class
    class Solution {

    public:
        int numSquarefulPerms(vector<int>& A) {
            unordered_map<int, int> count;
            for (const auto& a : A) {
                ++count[a];
            }
            unordered_map<int, unordered_set<int>> candidate;
            for (const auto& i : count) {
                for (const auto& j : count) {
                    int x = i.first, y = j.first, s = sqrt(x + y);
                    if (s * s == x + y) {
                        candidate[x].emplace(y);
                    }
                }
            }

            int result = 0;
            for (const auto& i : count) {
                dfs(candidate, i.first, A.size() - 1, &count, &result);
            }
            return result;
        }

    private:
        void dfs(const unordered_map<int, unordered_set<int>>& candidate,
                 int x,
                 int left,
                 unordered_map<int, int> *count,
                 int *result) {

            --(*count)[x];
            if (!left) {
                ++(*result);
            }
            if (candidate.count(x)) {
                for (const auto& y : candidate.at(x)) {
                    if ((*count)[y] > 0) {
                        dfs(candidate, y, left - 1, count, result);
                    }
                }
            }
            ++(*count)[x];
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.numSquarefulPerms(nums);

        // Print result to prevent optimization
        cout << "fun_XEblBpGylyCYcR2m: Executed numSquarefulPerms() from Number Of Squareful Arrays" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_XEblBpGylyCYcR2m: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
