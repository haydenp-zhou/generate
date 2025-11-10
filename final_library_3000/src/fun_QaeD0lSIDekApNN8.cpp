#include "fun_QaeD0lSIDekApNN8.hpp"

int fun_QaeD0lSIDekApNN8() {
    // LeetCode Problem: Path Sum Iii

    // Solution class
    class Solution {

    public:
        int pathSum(TreeNode* root, int sum) {        
            unordered_map<int, int> lookup;
            lookup[0] = 1;
            return pathSumHelper(root, 0, sum, &lookup);
        }

    private:
        int pathSumHelper(TreeNode* root, int curr, int sum, unordered_map<int, int> *lookup) {
            if (!root) {
                return 0;
            }
            curr += root->val;
            int result = lookup->count(curr - sum) ? (*lookup)[curr - sum] : 0;
            ++(*lookup)[curr];
            result += pathSumHelper(root->left, curr, sum, lookup) + pathSumHelper(root->right, curr, sum, lookup);
            --(*lookup)[curr];
            if ((*lookup)[curr] == 0) {
                lookup->erase(curr);
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.pathSum(testValue);

        // Print result to prevent optimization
        cout << "fun_QaeD0lSIDekApNN8: Executed pathSum() from Path Sum Iii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_QaeD0lSIDekApNN8: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
