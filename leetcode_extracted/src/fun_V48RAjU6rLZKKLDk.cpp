#include "fun_V48RAjU6rLZKKLDk.hpp"

int fun_V48RAjU6rLZKKLDk() {
    // LeetCode Problem: Construct Binary Tree From Inorder And Postorder Traversal

    // Solution class
    class Solution {

    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            unordered_map<int, size_t> in_entry_idx_map;
            for (size_t i = 0; i < inorder.size(); ++i) {
                in_entry_idx_map.emplace(inorder[i], i);
            }
            return ReconstructPostInOrdersHelper(postorder, 0, postorder.size(), inorder, 0, inorder.size(),
                                                 in_entry_idx_map);
        }

        TreeNode * ReconstructPostInOrdersHelper(const vector<int>& postorder, size_t post_s, size_t post_e,
                                                 const vector<int>& inorder, size_t in_s, size_t in_e,
                                                 const unordered_map<int, size_t>& in_entry_idx_map) {
            if (post_s == post_e || in_s == in_e) {
                return nullptr;
            }

            auto idx = in_entry_idx_map.at(postorder[post_e - 1]);
            auto left_tree_size = idx - in_s;

            TreeNode *node = new TreeNode(postorder[post_e - 1]);
            // Recursively builds the left subtree.
            node->left =ReconstructPostInOrdersHelper(postorder, post_s, post_s + left_tree_size,
                                                      inorder, in_s, idx, in_entry_idx_map);
            // Recursively builds the right subtree.
            node->right = ReconstructPostInOrdersHelper(postorder, post_s + left_tree_size, post_e - 1,
                                                        inorder, idx + 1, in_e, in_entry_idx_map);
            return node;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.buildTree(nums);

        // Print result to prevent optimization
        cout << "fun_V48RAjU6rLZKKLDk: Executed buildTree() from Construct Binary Tree From Inorder And Postorder Traversal" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_V48RAjU6rLZKKLDk: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
