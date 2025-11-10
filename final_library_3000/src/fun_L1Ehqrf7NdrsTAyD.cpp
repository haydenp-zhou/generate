#include "fun_L1Ehqrf7NdrsTAyD.hpp"

int fun_L1Ehqrf7NdrsTAyD() {
    // LeetCode Problem: Average Of Levels In Binary Tree

    // Solution class
    class Solution {

    public:
        vector<double> averageOfLevels(TreeNode* root) {
            vector<double> result;
            vector<TreeNode *> q;
            q.emplace_back(root);
            while (!q.empty()) {
                long long sum = 0, count = 0;
                vector<TreeNode *> next_q;
                for (const auto& n : q) {
                    sum += n->val;
                    ++count;
                    if (n->left) {
                        next_q.emplace_back(n->left);
                    }
                    if (n->right) {
                        next_q.emplace_back(n->right);
                    }
                }
                swap(q, next_q);
                result.emplace_back(sum * 1.0 / count);
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.averageOfLevels(testValue);

        // Print result to prevent optimization
        cout << "fun_L1Ehqrf7NdrsTAyD: Executed averageOfLevels() from Average Of Levels In Binary Tree" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_L1Ehqrf7NdrsTAyD: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
