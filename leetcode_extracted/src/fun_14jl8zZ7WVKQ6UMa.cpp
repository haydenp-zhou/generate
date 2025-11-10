#include "fun_14jl8zZ7WVKQ6UMa.hpp"

int fun_14jl8zZ7WVKQ6UMa() {
    // LeetCode Problem: Linked List Cycle. I I

    // Solution class
    class Solution {


    private:
        ListNode *p1, *p2;
    public:
        bool hasCycle(ListNode *head) {

            if (head==NULL) return false;
            p1=head;
            p2=head;

            while (p1!=NULL && p2!=NULL){

                p1=p1->next;

                if (p2->next == NULL) return false;

                p2=p2->next->next;

                if (p1==p2) return true;
            }

            return false;

        }  

        /* 
         * So, the idea is:
         *   1) Using the cycle-chcking algorithm.
         *   2) Once p1 and p1 meet, then reset p1 to head, and move p1 & p2 synchronously
         *      until p1 and p2 meet again, that place is the cycle's start-point 
         */
        ListNode *detectCycle(ListNode *head) {

            if (hasCycle(head)==false){
                return NULL;
            }

            p1 = head;

            while (p1!=p2) {
                p1 = p1->next;
                p2 = p2->next;
            }

            return p1;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.hasCycle(testValue);

        // Print result to prevent optimization
        cout << "fun_14jl8zZ7WVKQ6UMa: Executed hasCycle() from Linked List Cycle. I I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_14jl8zZ7WVKQ6UMa: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
