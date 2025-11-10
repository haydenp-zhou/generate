#include "fun_R9MuqKyKehR32HQH.hpp"

int fun_R9MuqKyKehR32HQH() {
    // LeetCode Problem: Palindrome Linked List

    // Solution class
    class Solution {

    public:
        ListNode* findMiddle(ListNode* head) {
            ListNode *p1=head, *p2=head;
            while(p2 && p2->next){
                p1 = p1->next;
                p2 = p2->next->next;
            }
            return p1;
        }

        ListNode* reverseLink(ListNode* head) {
            ListNode* p=NULL;

            while (head) {
                ListNode* q = head->next;
                head->next = p;
                p = head;
                head = q;
            }
            return p;
        }

        bool isPalindrome(ListNode* head) {
            ListNode* pMid = findMiddle(head);
            ListNode* pRev = reverseLink(pMid); 
            for(;head!=pMid; head=head->next, pRev=pRev->next) {
                if (head->val != pRev->val) {
                    return false;
                }
            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.findMiddle(testValue);

        // Print result to prevent optimization
        cout << "fun_R9MuqKyKehR32HQH: Executed findMiddle() from Palindrome Linked List" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_R9MuqKyKehR32HQH: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
