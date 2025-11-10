#include "fun_SJd1vjanqF5dnBDf.hpp"

int fun_SJd1vjanqF5dnBDf() {
    // LeetCode Problem: Binary Tree Level Order Traversal. I I

    // Solution class
    class Solution {

    public:
        vector<vector<int> > levelOrderBottom(TreeNode *root) {
            queue<TreeNode*> q;
            vector< vector<int> > vv;
            vector<int> v;
            if (root){
                v.push_back(root->val);
                vv.push_back(v);
            }
            q.push(root);
            int i=0;
            vector<TreeNode*> vt;
            while(q.size()>0){
                TreeNode *p = q.front();
                q.pop();
                vt.push_back(p);
                if ( p==NULL ) {
                    continue;
                }
                q.push(p->left);
                q.push(p->right);
            }


            int step = 2;
            int j;
            for (int i=1; i<vt.size(); i=j ){
                v.clear();

                int cnt=0;
                for (j=i; j<i+step && j<vt.size(); j++){
                    if (vt[j]) {
                        v.push_back(vt[j]->val);
                        cnt += 2;
                    }
                }
                step = cnt;
                if (v.size()>0) {
                    vv.push_back(v);
                }
            }
            //reverse the order
            reverse(vv.begin(), vv.end());
            return vv;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.levelOrderBottom(nums);

        // Print result to prevent optimization
        cout << "fun_SJd1vjanqF5dnBDf: Executed levelOrderBottom() from Binary Tree Level Order Traversal. I I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_SJd1vjanqF5dnBDf: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
