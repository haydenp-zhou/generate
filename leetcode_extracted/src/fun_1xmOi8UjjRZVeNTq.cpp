#include "fun_1xmOi8UjjRZVeNTq.hpp"

int fun_1xmOi8UjjRZVeNTq() {
    // LeetCode Problem: Intersection Of Two Linked Lists

    // Solution class
    class Solution {

        public:
            ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

                //caculate the length of each List
                int lenA = getListLength(headA);
                int lenB = getListLength(headB);

                if (lenA<=0 || lenB<=0 ) return NULL;

                //let List A is the longest List;
                if (lenA < lenB){
                    swap(headA, headB);
                }

                //move head of List A, make both of Lists are same length 
                for (int i=0; i<abs(lenA-lenB); i++){
                    headA = headA->next;
                }

                //synced travel both of Lists and check their nodes are same or not 
                while (headA != headB){
                    headA = headA->next;
                    headB = headB->next;
                }

                return headA;
            }
        private:    
            inline int getListLength(ListNode *head){
                int len=0;
                while(head!=NULL){
                    head = head->next;
                    len++;
                }
                return len;
            }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.getIntersectionNode(testValue);

        // Print result to prevent optimization
        cout << "fun_1xmOi8UjjRZVeNTq: Executed getIntersectionNode() from Intersection Of Two Linked Lists" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_1xmOi8UjjRZVeNTq: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
