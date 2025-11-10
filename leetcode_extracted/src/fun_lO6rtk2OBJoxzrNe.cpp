#include "fun_lO6rtk2OBJoxzrNe.hpp"

int fun_lO6rtk2OBJoxzrNe() {
    // LeetCode Problem: Copy List With Random Pointer

    // Solution class
    class Solution {

    public:
        RandomListNode *copyRandomList(RandomListNode *head) {
            RandomListNode *p = NULL, *h=NULL, *t=NULL;
            if (head == NULL){
                return NULL;
            }

            //creat a new node for each node and insert its next
            p = head;
            while ( p != NULL){
                RandomListNode *node = new RandomListNode(p->label);
                node->next = p->next;
                p->next = node;
                p = node->next;
            }

            //copy random pointer for each new node
            p = head;
            while (p != NULL){
                if (p->random != NULL){
                    p->next->random = p->random->next;
                }
                p = p->next->next;
            }

            //break to two list
            p = head;
            h = t = head->next;
            while ( p != NULL ){
                p->next = p->next->next;
                if (t->next!=NULL){
                    t->next = t->next->next;
                }

                p = p->next;
                t = t->next;
            }

            return h;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.copyRandomList(testValue);

        // Print result to prevent optimization
        cout << "fun_lO6rtk2OBJoxzrNe: Executed copyRandomList() from Copy List With Random Pointer" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_lO6rtk2OBJoxzrNe: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
