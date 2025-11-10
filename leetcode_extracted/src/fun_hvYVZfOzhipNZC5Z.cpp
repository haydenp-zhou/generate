#include "fun_hvYVZfOzhipNZC5Z.hpp"

int fun_hvYVZfOzhipNZC5Z() {
    // LeetCode Problem: Binary Tree Postorder Traversal

    // Solution class
    class Solution {

    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> res;
            TreeNode dummy(INT_MIN);
            dummy.left = root;
            auto *cur = &dummy;
            while (cur) {
                if (!cur->left) {
                    cur = cur->right;
                } else {
                    auto *node = cur->left;
                    while (node->right && node->right != cur) {
                        node = node->right;
                    }
                    if (!node->right) {
                        node->right = cur;
                        cur = cur->left;
                    } else {
                        const auto& v = trace_back(cur->left, node);
                        res.insert(res.end(), v.cbegin(), v.cend());
                        node->right = nullptr;
                        cur = cur->right;
                    }
                }
            }
            return res;
        }

    private:
        vector<int> trace_back(const TreeNode *from, const TreeNode *to) {
            vector<int> res;
            auto *cur = from;
            while (cur != to) {
                res.emplace_back(cur->val);
                cur = cur->right;
            }
            res.emplace_back(to->val);
            reverse(res.begin(), res.end());
            return res;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.postorderTraversal(nums);

        // Print result to prevent optimization
        cout << "fun_hvYVZfOzhipNZC5Z: Executed postorderTraversal() from Binary Tree Postorder Traversal" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_hvYVZfOzhipNZC5Z: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
