#include "fun_a8GOXNyzdRjba2zw.hpp"

int fun_a8GOXNyzdRjba2zw() {
    // LeetCode Problem: Path Sum

    // Solution class
    class Solution {

    public:
        Solution(){
            srand(time(NULL));
        }
        bool hasPathSum(TreeNode *root, int sum) {
            return hasPathSum3(root, sum, 0);
            return hasPathSum2(root, sum);
            return hasPathSum1(root, sum);    
        }

        bool hasPathSum3(TreeNode* root, int sum, int s) {
            if ( root == NULL) return false;
            s += root->val;
            if ( !root->left && !root->right)  return s == sum;
            return (hasPathSum3(root->left, sum, s) || hasPathSum3(root->right, sum, s));
        }

        bool hasPathSum1(TreeNode *root, int sum) {
            if (root==NULL) return false;
            vector<TreeNode*> v;
            v.push_back(root);
            while(v.size()>0){
                TreeNode* node = v.back();
                v.pop_back();
                if (node->left==NULL && node->right==NULL){
                    if (node->val == sum){
                        return true;
                    }
                }
                if (node->left){
                    node->left->val += node->val;
                    v.push_back(node->left);
                }
                if (node->right){
                    node->right->val += node->val;
                    v.push_back(node->right);
                }
            }
            return false;

        }

        bool hasPathSum2(TreeNode *root, int sum) {

            if (root==NULL) return false;

            if (root->left==NULL && root->right==NULL ){
                return (root->val==sum);
            }

            if (root->left){
                root->left->val += root->val;
                if (hasPathSum2(root->left, sum)){
                    return true;
                }
            }

            if (root->right){
                root->right->val += root->val;
                if (hasPathSum2(root->right, sum)){
                    return true;
                }
            }

            return false;
        }


    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.Solution(testValue);

        // Print result to prevent optimization
        cout << "fun_a8GOXNyzdRjba2zw: Executed Solution() from Path Sum" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_a8GOXNyzdRjba2zw: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
