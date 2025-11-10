#include "fun_4oWs3J8A8AgqFmrj.hpp"

int fun_4oWs3J8A8AgqFmrj() {
    // LeetCode Problem: Find Building Where Alice And Bob Can Meet

    // Solution class
    class Solution {

    public:
        vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
            vector<int> result(size(queries), -1);
            SegmentTree st(heights);
            for (int i = 0; i < size(queries); ++i) {
                int a = queries[i][0], b = queries[i][1];
                if (a > b) {
                    swap(a, b);
                }
                if (a == b || heights[a] < heights[b]) {
                    result[i] = b;
                    continue;
                }
                result[i] = st.binary_search(b + 1, size(heights) - 1, 0, size(heights) - 1, 1, heights[a]);
            }
            return result;
        }

    private:
        class SegmentTree {
        public:
            explicit SegmentTree(const vector<int>& heights)
              : tree(size(heights) > 1 ? 1 << (__lg(size(heights) - 1) + 2) : 2),
                heights(heights) {

                build(0, size(heights) - 1, 1);
            }

            void build(int left, int right, int idx) {
                if (left == right) {
                    tree[idx] = heights[left];
                    return;
                }
                const int mid = left + (right - left) / 2;
                build(left, mid, idx * 2);
                build(mid + 1, right, idx * 2 + 1);
                tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
            }

            int binary_search(int L, int R, int left, int right, int idx, int h) {
                if (right < L || left > R) {
                    return -1;
                }
                if (L <= left && right <= R) {
                    if (!(tree[idx] > h)) {
                        return -1;
                    }
                    if (left == right) {
                        return left;
                    }
                }
                const int mid = left + (right - left) / 2;
                const int i = binary_search(L, R, left, mid, idx * 2, h);
                return i != -1 ? i : binary_search(L, R, mid + 1, right, idx * 2 + 1, h);
            }

            vector<int> tree;
            const vector<int>& heights;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.leftmostBuildingQueries(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_4oWs3J8A8AgqFmrj: Executed leftmostBuildingQueries() from Find Building Where Alice And Bob Can Meet" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_4oWs3J8A8AgqFmrj: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
