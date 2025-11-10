#include "fun_9MGYYcivNCqRyG8W.hpp"

int fun_9MGYYcivNCqRyG8W() {
    // LeetCode Problem: Binary Tree Longest Consecutive Sequence

    // Solution class
    class Solution {

    public:
        int longestConsecutive(TreeNode* root) {
            int max_len = 0;
            longestConsecutiveHelper(root, &max_len);
            return max_len;
        }

        int longestConsecutiveHelper(TreeNode *root, int *max_len) {
            if (!root) {
                return 0;
            }

            const int left_len = longestConsecutiveHelper(root->left, max_len);
            const int right_len = longestConsecutiveHelper(root->right, max_len);

            int cur_len = 1;
            if (root->left && root->left->val == root->val + 1) {
                cur_len = max(cur_len, left_len + 1);
            }
            if (root->right && root->right->val == root->val + 1) {
                cur_len = max(cur_len, right_len + 1);
            }
            *max_len = max(*max_len, max(cur_len, max(left_len, right_len)));
            return cur_len;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.longestConsecutive(testValue);

        // Print result to prevent optimization
        cout << "fun_9MGYYcivNCqRyG8W: Executed longestConsecutive() from Binary Tree Longest Consecutive Sequence" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_9MGYYcivNCqRyG8W: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
