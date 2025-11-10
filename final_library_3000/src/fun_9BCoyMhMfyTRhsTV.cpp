#include "fun_9BCoyMhMfyTRhsTV.hpp"

int fun_9BCoyMhMfyTRhsTV() {
    // LeetCode Problem: Cousins In Binary Tree

    // Solution class
    class Solution {

    public:
        bool isCousins(TreeNode* root, int x, int y) {
            int depth_x = 0, depth_y = 0;
            TreeNode *parent_x = nullptr, *parent_y = nullptr;
            return dfs(root, x, &depth_x, &parent_x) &&
                   dfs(root, y, &depth_y, &parent_y) &&
                   depth_x == depth_y &&
                   parent_x != parent_y;
        }

    private:
        bool dfs(TreeNode *root, int x, int *depth, TreeNode **parent) {
            if (!root) {
                return false;
            }
            if (root->val == x) {
                return true;
            }
            ++(*depth);
            auto prev_parent = (*parent);
            (*parent) = root;
            if (dfs(root->left, x, depth, parent)) {
                return true;
            }
            (*parent) = root;
            if (dfs(root->right, x, depth, parent)) {
                return true;
            }
            (*parent) = prev_parent;
            --(*depth);
            return false;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.isCousins(testValue);

        // Print result to prevent optimization
        cout << "fun_9BCoyMhMfyTRhsTV: Executed isCousins() from Cousins In Binary Tree" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_9BCoyMhMfyTRhsTV: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
