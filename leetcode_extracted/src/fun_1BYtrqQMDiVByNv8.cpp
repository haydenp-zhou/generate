#include "fun_1BYtrqQMDiVByNv8.hpp"

int fun_1BYtrqQMDiVByNv8() {
    // LeetCode Problem: Cousins In Binary Tree

    // Solution class
    class Solution {

    public:
        bool isCousins(TreeNode* root, int x, int y) {
            int dx=0, dy=0;
            TreeNode *px=root, *py=root;
            dx = DepthAndParent(root, px, 0, x);
            dy = DepthAndParent(root, py, 0, y);
            if (dx && dy){
                return (dx == dy && px != py);
            }

            return false;

        }

        int DepthAndParent(TreeNode* root, TreeNode*& parent, int depth, int x) {
            if (!root) return 0;
            if ( root->val == x) return depth;

            int d=0;
            parent = root;
            if  ( ( d = DepthAndParent(root->left, parent, depth+1, x)) > 0 ) return d;

            parent = root;
            if ( ( d = DepthAndParent(root->right, parent, depth+1, x)) > 0 ) return d;
            return 0;
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
        cout << "fun_1BYtrqQMDiVByNv8: Executed isCousins() from Cousins In Binary Tree" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_1BYtrqQMDiVByNv8: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
