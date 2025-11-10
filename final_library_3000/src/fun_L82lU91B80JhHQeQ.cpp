#include "fun_L82lU91B80JhHQeQ.hpp"

int fun_L82lU91B80JhHQeQ() {
    // LeetCode Problem: Snakes And Ladders

    // Solution class
    class Solution {

    public:
        int snakesAndLadders(vector<vector<int>>& board) {
            const int n = board.size();
            unordered_map<int, int> lookup;
            lookup[1] = 0;
            queue<int> q({1});
            while (!q.empty()) {
                const auto s = q.front(); q.pop();
                if (s == n * n) {
                    return lookup[s];
                }
                for (int i = s + 1; i < min(s + 6, n * n) + 1; ++i) {
                    int r, c;
                    tie(r, c) = coordinate(n, i);
                    int s2 = i;
                    if (board[r][c] != -1) {
                        s2 = board[r][c];
                    }
                    if (!lookup.count(s2)) {
                        lookup[s2] = lookup[s] + 1;
                        q.emplace(s2);
                    }
                }
            }
            return -1;
        }

    private:
        pair<int, int> coordinate(int n, int s) {
            const int a = (s - 1) / n;
            const int b = (s - 1) % n;
            const int r = n - 1 - a;
            const int c = (r % 2 != n % 2) ? b : n - 1 - b;
            return {r, c
    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.snakesAndLadders(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_L82lU91B80JhHQeQ: Executed snakesAndLadders() from Snakes And Ladders" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_L82lU91B80JhHQeQ: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
