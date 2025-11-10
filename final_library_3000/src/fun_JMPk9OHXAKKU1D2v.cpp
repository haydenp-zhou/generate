#include "fun_JMPk9OHXAKKU1D2v.hpp"

int fun_JMPk9OHXAKKU1D2v() {
    // LeetCode Problem: Rotate List

    // Solution class
    class Solution {

    public:
        ListNode *rotateRight(ListNode *head, int k) {
            if (!head || k<=0){
                return head;
            }

            //find the length of List
            int len=1;
            ListNode *p=head;
            while( p->next != NULL ){
                p = p->next;
                len++;
            }
            //connect the tail to head
            p->next = head;
            //find the left place (take care the case - k > len)
            k = len - k % len;

            //find the place
            for(int i=0; i<k; i++){
                p = p->next;
            }

            //break the list
            head = p->next;
            p->next = NULL;

            return head;

        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.rotateRight(n);

        // Print result to prevent optimization
        cout << "fun_JMPk9OHXAKKU1D2v: Executed rotateRight() from Rotate List" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_JMPk9OHXAKKU1D2v: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
