#include "fun_Lq4C3wRoPWCunX7F.hpp"

int fun_Lq4C3wRoPWCunX7F() {
    // LeetCode Problem: Kth Smallest Element In A Bst

    // Solution class
    class Solution {

    public:
        // in-order travel - recursive way
        int kthSmallestHelper_recursive(TreeNode* root, int& k) {
            if (root==NULL) return 0; //this behavior is undefined!

            //in-order travel
            int result = kthSmallestHelper_recursive(root->left, k);
            if (k==0) return result;

            k--;
            if (k==0) return root->val;


            return kthSmallestHelper_recursive(root->right, k);
        }
        // in-order travel - non-recursive way
        int kthSmallestHelper_nonRecursive(TreeNode* root, int k){
            stack<TreeNode*> s;

            while(!s.empty() || root){

                while (root) { 
                    s.push(root);
                    root = root->left;
                }

                k--;
                root = s.top()->right;

                if (k==0) return s.top()->val;

                s.pop();
            }
            return -1;
        }

        int kthSmallest(TreeNode* root, int k) {
            //return kthSmallestHelper_nonRecursive(root, k);
            return kthSmallestHelper_recursive(root, k);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.kthSmallestHelper_recursive(n);

        // Print result to prevent optimization
        cout << "fun_Lq4C3wRoPWCunX7F: Executed kthSmallestHelper_recursive() from Kth Smallest Element In A Bst" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Lq4C3wRoPWCunX7F: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
