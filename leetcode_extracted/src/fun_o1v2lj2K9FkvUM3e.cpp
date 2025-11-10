#include "fun_o1v2lj2K9FkvUM3e.hpp"

int fun_o1v2lj2K9FkvUM3e() {
    // LeetCode Problem: Binary Tree Level Order Traversal Ii

    // Solution class
    class Solution {

    public:
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> result;
            queue<TreeNode *> que;

            if (root != nullptr) {
                que.emplace(root);
            }

            while (!que.empty()) {
                vector<int> level;
                int size = que.size();
                for (int i = 0; i < size; i++) {
                    auto *front = que.front();
                    que.pop();
                    level.emplace_back(front->val);
                    if (front->left != nullptr) {
                        que.emplace(front->left);
                    }
                    if (front->right != nullptr) {
                        que.emplace(front->right);
                    }
                }
                result.emplace_back(move(level));
            }

            // The only difference between binary-tree-level-order-traversal
            // and binary-tree-level-order-traversal-ii
            reverse(result.begin(), result.end());

            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.levelOrderBottom(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_o1v2lj2K9FkvUM3e: Executed levelOrderBottom() from Binary Tree Level Order Traversal Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_o1v2lj2K9FkvUM3e: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
