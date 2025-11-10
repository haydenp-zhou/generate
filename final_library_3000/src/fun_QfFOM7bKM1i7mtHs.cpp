#include "fun_QfFOM7bKM1i7mtHs.hpp"

int fun_QfFOM7bKM1i7mtHs() {
    // LeetCode Problem: Friend Circles

    // Solution class
    class Solution {

    public:

        // -----------------------------------------------------------------------------
        //DFS solution is quite easy to understand, just like the "Number of Island"
        int findCircleNum_DFS(vector<vector<int>>& M) {
            int n = 0;
            for (int i=0; i<M.size(); i++) {
                for (int j=0; j<M[0].size(); j++) {
                    if ( M[i][j] == 1 ) {
                        n++;
                        M[i][j] = 2;
                        mark(M, j);
                    }
                }
            }
            return n;
        }

        void mark(vector<vector<int>>& M, int i ) {
            for ( int j=0;  j<M[i].size(); j++ ){
                if ( M[i][j] == 1 ) {
                    M[i][j] = 2;
                    mark(M, j);
                }
            }
        }

        // -----------------------------------------------------------------------------
        //Union Find Solution
        int findCircleNum_UF(vector<vector<int>>& M) {

            vector<int> relations(M.size());
            for (int i=0; i<relations.size(); i++){
                relations[i] = i;
            }

            int n = M.size(); //by default, there are N friend cicles
            for (int i=0; i<M.size(); i++) {
                for (int j=0; j<M[0].size(); j++) {
                    if ( M[i][j] == 1 && i != j ) {
                        if ( join(relations, i, j) ) n--;
                    }
                }
            }
            return n;
        }

        //find the tail node.
        //   if a -> b -> c -> d, then find(a),find(b) or find(c) would return d;
        int find(vector<int>& relations, int i ) {
            while( relations[i] != i ) {
                i = relations[i];
            }
            return i;
        }
        // join the x cicle with y cicle,
        // if x and y are already in same friend cicle, then return false, else return true;
        bool join(vector<int> &relations, int x, int y) {
            int tx = find(relations, x);
            int ty = find(relations, y);
            if ( tx != ty ) relations[tx] = ty;
            return tx != ty;
        }

        // -----------------------------------------------------------------------------

        int findCircleNum(vector<vector<int>>& M) {
            return findCircleNum_UF(M);
            return findCircleNum_DFS(M);
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
        volatile auto result = sol.findCircleNum_DFS(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_QfFOM7bKM1i7mtHs: Executed findCircleNum_DFS() from Friend Circles" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_QfFOM7bKM1i7mtHs: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
