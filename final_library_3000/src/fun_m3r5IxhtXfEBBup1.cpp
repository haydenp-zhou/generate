#include "fun_m3r5IxhtXfEBBup1.hpp"

int fun_m3r5IxhtXfEBBup1() {
    // LeetCode Problem: Palindrome Linked List

    // Solution class
    class Solution {

    public:
        bool isPalindrome(ListNode* head) {
            // Reverse the first half list.
            ListNode *reverse = nullptr, *fast = head;
            while (fast && fast->next) {
                fast = fast->next->next;
                const auto head_next = head->next;
                head->next = reverse;
                reverse = head;
                head = head_next;
            }

            // If the number of the nodes is odd,
            // set the head of the tail list to the next of the median node.
            ListNode *tail = fast ? head->next : head;

            // Compare the reversed first half list with the second half list.
            // And restore the reversed first half list.
            bool is_palindrome = true;
            while (reverse) {
                is_palindrome = is_palindrome && reverse->val == tail->val;
                const auto reverse_next = reverse->next;
                reverse->next = head;
                head = reverse;
                reverse = reverse_next;
                tail = tail->next;
            }

            return is_palindrome;   
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.isPalindrome(testValue);

        // Print result to prevent optimization
        cout << "fun_m3r5IxhtXfEBBup1: Executed isPalindrome() from Palindrome Linked List" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_m3r5IxhtXfEBBup1: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
