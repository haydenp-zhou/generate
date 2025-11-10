#include "fun_5Br7IukQDjALoPsi.hpp"

int fun_5Br7IukQDjALoPsi() {
    // LeetCode Problem: Linked List In Binary Tree

    // Solution class
    class Solution {

    public:
        bool isSubPath(ListNode* head, TreeNode* root) {
            if (!head) {
                return true;
            }
            const auto& [pattern, prefix] = getPrefix(head);
            return dfs(pattern, prefix, root, -1);
        }

    private:
        bool dfs(const vector<int>& pattern,
                 const vector<int>& prefix,
                 TreeNode *root, int j) {
            if (!root) {
                return false;
            }
            while (j + 1 && pattern[j + 1] != root->val) {
                j = prefix[j];
            }
            if (pattern[j + 1] == root->val) {
                ++j;
            }
            if (j + 1 == pattern.size()) {
                return true;
            }
            return dfs(pattern, prefix, root->left, j) ||
                   dfs(pattern, prefix, root->right, j);
        }

        pair<vector<int>, vector<int>> getPrefix(ListNode *head) {
            vector<int> pattern = {head->val
    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.isSubPath(nums);

        // Print result to prevent optimization
        cout << "fun_5Br7IukQDjALoPsi: Executed isSubPath() from Linked List In Binary Tree" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_5Br7IukQDjALoPsi: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
