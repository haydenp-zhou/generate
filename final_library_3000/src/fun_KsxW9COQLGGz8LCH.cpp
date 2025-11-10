#include "fun_KsxW9COQLGGz8LCH.hpp"

int fun_KsxW9COQLGGz8LCH() {
    // LeetCode Problem: Convert Sorted List To Binary Search Tree

    // Solution class
    class Solution {

    public:
        TreeNode* sortedListToBST(ListNode* head) {
            auto curr = head;
            int n = 0;
            while (curr) {
                curr = curr->next;
                ++n;
            }
            return BuildBSTFromSortedDoublyListHelper(&head, 0, n);
        }

        TreeNode * BuildBSTFromSortedDoublyListHelper(ListNode **head, int s, int e) {
            if (s == e) {
                return nullptr;
            }

            int m = s + ((e - s) / 2);
            auto left = BuildBSTFromSortedDoublyListHelper(head, s, m);
            auto curr = new TreeNode((*head)->val);

            *head = (*head)->next;
            curr->left = left;
            curr->right = BuildBSTFromSortedDoublyListHelper(head, m + 1, e);
            return curr;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.sortedListToBST(n);

        // Print result to prevent optimization
        cout << "fun_KsxW9COQLGGz8LCH: Executed sortedListToBST() from Convert Sorted List To Binary Search Tree" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_KsxW9COQLGGz8LCH: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
