#include "fun_cOPQpOvXYHvNZTD6.hpp"

int fun_cOPQpOvXYHvNZTD6() {
    // LeetCode Problem: Count Nodes With The Highest Score

    // Solution class
    class Solution {

    public:
        int countHighestScoreNodes(vector<int>& parents) {
            vector<vector<int>> adj(size(parents));  // Space: O(n)
            for (int i = 1; i < size(parents); ++i) {
                adj[parents[i]].emplace_back(i);
            }
            return iter_dfs(adj);
        }
    private:
        int iter_dfs(const vector<vector<int>>& adj) {
            pair<int64_t, int> result;
            using RET = shared_ptr<int>;
            auto ret = make_shared<int>();
            vector<tuple<int, int, vector<RET>, RET>> stk;
            stk.emplace_back(1, 0, vector<RET>(), ret);
            while (!empty(stk)) {
                auto [step, i, cnts, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    vector<RET> cnts(size(adj[i]));
                    for (auto& cnt : cnts) {
                        cnt = make_shared<int>();
                    }
                    stk.emplace_back(2, i, cnts, ret);
                    for (int j = 0; j < size(adj[i]); ++j) {
                        stk.emplace_back(1, adj[i][j], vector<RET>(), cnts[j]);
                    }
                } else if (step == 2) {
                    *ret = accumulate(cbegin(cnts), cend(cnts), 0,
                                      [](const auto& total, const auto& x) {
                                          return total + *x;
                                      }) + 1;
                    const int64_t score = max(static_cast<int64_t>(size(adj)) - *ret, 1l) *
                                          accumulate(cbegin(cnts), cend(cnts), 1ul,
                                                     [](const auto& total, const auto& x) {
                                                         return total * *x;
                                                     });
                    if (score > result.first) {
                        result = {score, 1
    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.countHighestScoreNodes(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_cOPQpOvXYHvNZTD6: Executed countHighestScoreNodes() from Count Nodes With The Highest Score" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_cOPQpOvXYHvNZTD6: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
