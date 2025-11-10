#include "fun_xS6mSsEsBNZrPL0B.hpp"

int fun_xS6mSsEsBNZrPL0B() {
    // LeetCode Problem: Zigzag Level Order

    // Solution class
    class Solution {

        public:
            vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
                bool isLeftToRight = true;
                vector<vector<int> > ans;
                queue<TreeNode *> q;
                TreeNode * n;
                vector<int> v;
                int size = 0;
                int cnt = 0;

                if(!root)
                    return ans;

                q.push(root);
                size = 1;
                while(size) {
                    n = q.front();
                    v.push_back(n->val);

                    if(n->left) {
                        q.push(n->left);
                        cnt++;
                    }
                    if(n->right) {
                        q.push(n->right);
                        cnt++;
                    }

                    q.pop();
                    size--;
                    if(size == 0) {
                        if(!isLeftToRight)
                            reverse(v.begin(), v.end());
                        isLeftToRight = !isLeftToRight;
                        size = cnt;
                        cnt = 0;
                        ans.push_back(v);
                        v.clear();
                    }
                }
                return ans;
            }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.zigzagLevelOrder(nums);

        // Print result to prevent optimization
        cout << "fun_xS6mSsEsBNZrPL0B: Executed zigzagLevelOrder() from Zigzag Level Order" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_xS6mSsEsBNZrPL0B: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
