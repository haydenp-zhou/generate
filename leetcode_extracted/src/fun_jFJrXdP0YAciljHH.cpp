#include "fun_jFJrXdP0YAciljHH.hpp"

int fun_jFJrXdP0YAciljHH() {
    // LeetCode Problem: Two Sum Bsts

    // Solution class
    class Solution {

    public:
        bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
            Iterator<TreeNode*> left(root1, true), right(root2, false);
            while (*left && *right) {
                if ((*left)->val + (*right)->val < target) {
                    ++left;
                } else if ((*left)->val + (*right)->val > target) {
                    ++right;
                } else {
                    return true;
                }
            }
            return false;
        }

    private:
        template<typename T>
        class Iterator {
        public:
            Iterator(T root, bool asc)
             : stack_{{root, false}}
             , asc_{asc}
             , curr_{} {
                 ++(*this);
            }

            Iterator& operator++() {
                while (!stack_.empty()) {
                    T root; bool is_visited;
                    tie(root, is_visited) = stack_.back(); stack_.pop_back();
                    if (!root) {
                        continue;
                    }
                    if (is_visited) {
                        curr_ = root;
                        return *this;
                    }
                    if (asc_) {
                        stack_.emplace_back(root->right, false);
                        stack_.emplace_back(root, true);
                        stack_.emplace_back(root->left, false);
                    } else {
                        stack_.emplace_back(root->left, false);
                        stack_.emplace_back(root, true);
                        stack_.emplace_back(root->right, false);
                    }
                }
                curr_ = T{
    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.twoSumBSTs(n);

        // Print result to prevent optimization
        cout << "fun_jFJrXdP0YAciljHH: Executed twoSumBSTs() from Two Sum Bsts" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_jFJrXdP0YAciljHH: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
