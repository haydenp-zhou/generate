#include "fun_hPv7fzI7FVaJWRs9.hpp"

int fun_hPv7fzI7FVaJWRs9() {
    // LeetCode Problem: Binary Tree Paths

    // Solution class
    class Solution {

    public:
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> result;
            vector<TreeNode *> path;
            binaryTreePathsRecu(root, &path, &result);
            return result;
        }

        void binaryTreePathsRecu(TreeNode *node, vector<TreeNode *> *path, vector<string> *result) {
            if (!node) {
                return;
            }

            if (!node->left && !node->right) {
                string ans = "";
                for (const auto& n : *path) {
                    ans.append(to_string(n->val).append("->"));
                }
                result->emplace_back(move(ans.append(to_string(node->val))));
            }

            if (node->left) {
                path->emplace_back(node);
                binaryTreePathsRecu(node->left, path, result);
                path->pop_back();
            }

            if (node->right) {
                path->emplace_back(node);
                binaryTreePathsRecu(node->right, path, result);
                path->pop_back();
            }
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.binaryTreePaths(strs);

        // Print result to prevent optimization
        cout << "fun_hPv7fzI7FVaJWRs9: Executed binaryTreePaths() from Binary Tree Paths" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_hPv7fzI7FVaJWRs9: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
