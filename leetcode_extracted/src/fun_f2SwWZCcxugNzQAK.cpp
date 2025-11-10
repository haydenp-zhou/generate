#include "fun_f2SwWZCcxugNzQAK.hpp"

int fun_f2SwWZCcxugNzQAK() {
    // LeetCode Problem: Count Univalue Subtrees

    // Solution class
    class Solution {

    public:
        int countUnivalSubtrees(TreeNode* root) {
            int count = 0;
            isUnivalSubtrees(root, &count);
            return count;
        }

        bool isUnivalSubtrees(TreeNode* root, int *count) {
            if (root == nullptr) {
                return true;
            }
            bool left = isUnivalSubtrees(root->left, count);
            bool right = isUnivalSubtrees(root->right, count);
            if (isSame(root, root->left, left) &&
                isSame(root, root->right, right)) {
                    ++(*count);
                    return true;
            }
            return false;
        }

        bool isSame(TreeNode* root, TreeNode* child, bool is_uni) {
            return child == nullptr || (is_uni && root->val == child->val);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.countUnivalSubtrees(testValue);

        // Print result to prevent optimization
        cout << "fun_f2SwWZCcxugNzQAK: Executed countUnivalSubtrees() from Count Univalue Subtrees" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_f2SwWZCcxugNzQAK: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
