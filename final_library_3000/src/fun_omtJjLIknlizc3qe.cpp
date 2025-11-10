#include "fun_omtJjLIknlizc3qe.hpp"

int fun_omtJjLIknlizc3qe() {
    // LeetCode Problem: Delete Nodes And Return Forest

    // Solution class
    class Solution {

    public:
        vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
            vector<TreeNode *> result;
            unordered_set<int> to_delete_set(to_delete.cbegin(), to_delete.cend());
            delNodesHelper(to_delete_set, root, true, &result);
            return result;
        }

    private:
        TreeNode *delNodesHelper(const unordered_set<int>& to_delete_set,
                                 TreeNode *root,
                                 bool is_root,
                                 vector<TreeNode *> *result) {
            if (!root) {
                return nullptr;
            }
            bool is_deleted = to_delete_set.count(root->val) != 0;
            if (is_root && !is_deleted) {
                result->emplace_back(root);
            }
            root->left = delNodesHelper(to_delete_set, root->left, is_deleted, result);
            root->right = delNodesHelper(to_delete_set, root->right, is_deleted, result);
            return is_deleted ? nullptr : root;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.delNodes(nums);

        // Print result to prevent optimization
        cout << "fun_omtJjLIknlizc3qe: Executed delNodes() from Delete Nodes And Return Forest" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_omtJjLIknlizc3qe: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
