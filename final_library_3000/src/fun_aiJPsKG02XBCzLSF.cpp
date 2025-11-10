#include "fun_aiJPsKG02XBCzLSF.hpp"

int fun_aiJPsKG02XBCzLSF() {
    // LeetCode Problem: Reorder List

    // Solution class
    class Solution {

    public:
        void reorderList(ListNode *head) {
            ListNode *pMid = findMidPos(head);
            pMid = reverseList(pMid);
            head = Merge(head, pMid);
        }

    private:
        ListNode* findMidPos(ListNode *head){

            ListNode *p1, *p2, *p=NULL;
            p1 = p2 = head;

            while(p1!=NULL && p2!=NULL && p2->next!=NULL){
                p = p1;
                p1 = p1->next;
                p2 = p2->next->next;
            }

            if(p!=NULL){
                p->next = NULL;
            }

            return p1;
        }

        ListNode* reverseList(ListNode *head){
            ListNode* h = NULL;
            ListNode *p;
            while (head!=NULL){
                p = head;
                head = head->next;
                p->next = h;
                h = p;
            }
            return h;
        }

        ListNode* Merge(ListNode *h1, ListNode* h2) {
            ListNode *p1=h1, *p2=h2, *p1nxt, *p2nxt;
            while(p1!=NULL && p2!=NULL){
                p1nxt = p1->next;
                p2nxt = p2->next;

                p1->next = p2;
                p2->next = p1nxt;

                if (p1nxt==NULL){
                    p2->next = p2nxt;
                    break;
                }
                p1=p1nxt;
                p2=p2nxt;
            }
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.reorderList(testValue);

        // Print result to prevent optimization
        cout << "fun_aiJPsKG02XBCzLSF: Executed reorderList() from Reorder List" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_aiJPsKG02XBCzLSF: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
