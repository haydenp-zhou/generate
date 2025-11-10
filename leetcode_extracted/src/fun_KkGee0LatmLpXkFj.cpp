#include "fun_KkGee0LatmLpXkFj.hpp"

int fun_KkGee0LatmLpXkFj() {
    // LeetCode Problem: Delete Columns To Make Sorted Ii

    // Solution class
    class Solution {

    public:
        int minDeletionSize(vector<string>& A) {
            int result = 0;
            unordered_set<int> unsorted;
            for (int i = 0; i < A.size() - 1; ++i) {
                unsorted.emplace(i);
            }
            for (int j = 0; j < A[0].size(); ++j) {
                if (any_of(unsorted.begin(), unsorted.end(),
                           [&](int i) {
                               return A[i][j] > A[i + 1][j];
                           })
                   ) {
                    ++result;
                } else {
                    unordered_set<int> tmp(unsorted);
                    for (const auto& i : tmp) {
                        if (A[i][j] < A[i + 1][j]) {
                            unsorted.erase(i);
                        }
                    }
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.minDeletionSize(strs);

        // Print result to prevent optimization
        cout << "fun_KkGee0LatmLpXkFj: Executed minDeletionSize() from Delete Columns To Make Sorted Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_KkGee0LatmLpXkFj: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
