#include "fun_FqY6ljU2CeqwEmCc.hpp"

int fun_FqY6ljU2CeqwEmCc() {
    // LeetCode Problem: Image Smoother

    // Solution class
    class Solution {

    public:
        vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
            const auto& m = M.size(), &n = M[0].size();
            vector<vector<int>> result(M);
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    result[i][j] = getGray(M, i, j);
                }
            }
            return result;
        }

    private:
        int getGray(const vector<vector<int>>& M, int i, int j) {
            const auto& m = M.size(), &n = M[0].size();
            double total = 0.0;
            int count = 0;
            for (int r = -1; r < 2; ++r) {
                for (int c = -1; c < 2; ++c) {
                    const auto& ii = i + r;
                    const auto& jj = j + c;
                    if (0 <= ii && ii < m && 0 <= jj && jj < n) {
                        total += M[ii][jj];
                        ++count;
                    }
                }
            }
            return static_cast<int>(total / count);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.imageSmoother(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_FqY6ljU2CeqwEmCc: Executed imageSmoother() from Image Smoother" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_FqY6ljU2CeqwEmCc: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
