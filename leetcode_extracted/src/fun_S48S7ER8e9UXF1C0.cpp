#include "fun_S48S7ER8e9UXF1C0.hpp"

int fun_S48S7ER8e9UXF1C0() {
    // LeetCode Problem: Check If Two Expression Trees Are Equivalent

    // Solution class
    class Solution {

    public:
        bool checkEquivalence(Node* root1, Node* root2) {
            unordered_map<char, int> count;   
            char prev = '+';
            morrisInorderTraversal(root1, bind(&Solution::addCounter, this,
                                               &count, &prev, 1, placeholders::_1));
            prev = '+';
            morrisInorderTraversal(root2, bind(&Solution::addCounter, this,
                                               &count, &prev, -1, placeholders::_1));
            return all_of(cbegin(count), cend(count),
                          [](const auto& kvp) {
                              return kvp.second == 0;
                          });
        }

    private:
        void morrisInorderTraversal(Node *root, const function<void(char)>& cb) {
            auto curr = root;
            while (curr) {
                if (!curr->left) {
                    cb(curr->val);
                    curr = curr->right;
                } else {
                    auto node = curr->left;
                    while (node->right && node->right != curr) {
                        node = node->right;
                    }
                    if (!node->right) {
                        node->right = curr;
                        curr = curr->left;
                    } else {
                        cb(curr->val);
                        node->right = nullptr;
                        curr = curr->right;
                    }
                }
            }
        }

        void addCounter(unordered_map<char, int> *count, char *prev, int d, char val) {
            if (isalpha(val)) {
                (*count)[val] += (*prev == '+') ? d : -d;
            }
            *prev = val;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.checkEquivalence(testValue);

        // Print result to prevent optimization
        cout << "fun_S48S7ER8e9UXF1C0: Executed checkEquivalence() from Check If Two Expression Trees Are Equivalent" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_S48S7ER8e9UXF1C0: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
