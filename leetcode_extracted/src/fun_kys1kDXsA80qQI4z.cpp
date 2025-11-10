#include "fun_kys1kDXsA80qQI4z.hpp"

int fun_kys1kDXsA80qQI4z() {
    // LeetCode Problem: Reverse Linked List

    // Solution class
    class Solution {

    public:
        ListNode* reverseList_iteratively(ListNode* head) {
            ListNode *h=NULL, *p=NULL;
            while (head){
                p = head->next;
                head->next = h;
                h = head;
                head = p;
            }
            return h;
        }
        ListNode* reverseList_recursively(ListNode* head) {
            if (head==NULL || head->next==NULL) return head;
            ListNode *h = reverseList_recursively(head->next);
            head->next->next = head;
            head->next = NULL;
            return h;

        }
        ListNode* reverseList(ListNode* head) {
            return reverseList_iteratively(head);
            return reverseList_recursively(head);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.reverseList_iteratively(testValue);

        // Print result to prevent optimization
        cout << "fun_kys1kDXsA80qQI4z: Executed reverseList_iteratively() from Reverse Linked List" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_kys1kDXsA80qQI4z: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
