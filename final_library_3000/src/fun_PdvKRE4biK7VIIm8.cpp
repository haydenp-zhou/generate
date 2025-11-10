#include "fun_PdvKRE4biK7VIIm8.hpp"

int fun_PdvKRE4biK7VIIm8() {
    // LeetCode Problem: Construct Binary Tree From Preorder And Inorder Traversal

    // Solution class
    class Solution {

    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            unordered_map<int, size_t> in_entry_idx_map;
            for (size_t i = 0; i < inorder.size(); ++i) {
                in_entry_idx_map.emplace(inorder[i], i);
            }
            return ReconstructPreInOrdersHelper(preorder, 0, preorder.size(), inorder, 0, inorder.size(),
                                                in_entry_idx_map);
        }

        // Reconstructs the binary tree from pre[pre_s : pre_e - 1] and
        // in[in_s : in_e - 1].
        TreeNode *ReconstructPreInOrdersHelper(const vector<int>& preorder, size_t pre_s, size_t pre_e,
                                               const vector<int>& inorder, size_t in_s, size_t in_e,
                                               const unordered_map<int, size_t>& in_entry_idx_map) {
            if (pre_s == pre_e || in_s == in_e) {
                return nullptr;
            }

            auto idx = in_entry_idx_map.at(preorder[pre_s]);
            auto left_tree_size = idx - in_s;

            auto node = new TreeNode(preorder[pre_s]);
            node->left = ReconstructPreInOrdersHelper(preorder, pre_s + 1, pre_s + 1 + left_tree_size,
                                                      inorder, in_s, idx, in_entry_idx_map);
            node->right = ReconstructPreInOrdersHelper(preorder, pre_s + 1 + left_tree_size, pre_e,
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
        cout << "fun_PdvKRE4biK7VIIm8: Executed buildTree() from Construct Binary Tree From Preorder And Inorder Traversal" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_PdvKRE4biK7VIIm8: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
