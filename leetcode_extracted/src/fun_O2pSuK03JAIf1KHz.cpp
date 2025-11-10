#include "fun_O2pSuK03JAIf1KHz.hpp"

int fun_O2pSuK03JAIf1KHz() {
    // LeetCode Problem: Subtree Of Another Tree

    // Solution class
    class Solution {

    public:
        bool isSubtree(TreeNode* s, TreeNode* t) {
            return preOrderTraverse(s, t);
        }

    private:
        bool preOrderTraverse(TreeNode *s, TreeNode *t) {
            return s && (isSame(s, t) ||
                         preOrderTraverse(s->left, t) ||
                         preOrderTraverse(s->right, t));
        }

        bool isSame(TreeNode *x,TreeNode *y) {
            if (!x && !y) {
                return true;
            }
            if (!x || !y) {
                return false;
            }
            return x->val == y->val &&
                   isSame(x->left, y->left) &&
                   isSame(x->right, y->right);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.isSubtree(testValue);

        // Print result to prevent optimization
        cout << "fun_O2pSuK03JAIf1KHz: Executed isSubtree() from Subtree Of Another Tree" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_O2pSuK03JAIf1KHz: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
