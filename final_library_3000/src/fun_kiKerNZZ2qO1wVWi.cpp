#include "fun_kiKerNZZ2qO1wVWi.hpp"

int fun_kiKerNZZ2qO1wVWi() {
    // LeetCode Problem: Equal Tree Partition

    // Solution class
    class Solution {

    public:
        bool checkEqualTree(TreeNode* root) {
            unordered_map<int, int> lookup;
            auto total = getSumHelper(root, &lookup);
            if (total == 0) {
                return lookup[total] > 1;
            }
            return total % 2 == 0 && lookup.count(total / 2);
        }

    private:
        int getSumHelper(TreeNode* node,  unordered_map<int, int> *lookup) {
            if (!node) {
                return 0;
            }
            int total = node->val + 
                        getSumHelper(node->left, lookup) +
                        getSumHelper(node->right, lookup);
            ++(*lookup)[total];
            return total;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.checkEqualTree(testValue);

        // Print result to prevent optimization
        cout << "fun_kiKerNZZ2qO1wVWi: Executed checkEqualTree() from Equal Tree Partition" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_kiKerNZZ2qO1wVWi: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
