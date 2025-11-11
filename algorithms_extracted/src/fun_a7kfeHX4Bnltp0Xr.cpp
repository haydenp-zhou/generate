#include "fun_a7kfeHX4Bnltp0Xr.hpp"

// Original algorithm: Reverse A Linked List Using Recusion
int fun_a7kfeHX4Bnltp0Xr() {
    try {
        using namespace std;
        struct node {
            int val;
            node *next;
        };
        node *start;
        void insert(int x) {
            node *t = start;
            if (start != NULL) {
                while (t->next != NULL) {
                    t = t->next;
                }
                node *n = new node;
                t->next = n;
                n->val = x;
                n->next = NULL;
            } else {
                node *n = new node;
                n->val = x;
                n->next = NULL;
                start = n;
            }
        }
        void reverse(node *p, node *q) {
            if (q->next == NULL) {
                q->next = p;
                p->next = NULL;
                start = q;
                return;
            } else {
                reverse(q, q->next);
                q->next = p;
                p->next = NULL;
            }
        }
        void show() {
            node *t = start;
            while (t != NULL) {
                cout << t->val << "\t";
                t = t->next;
            }
        }


        volatile int status = 1;
        cout << "fun_a7kfeHX4Bnltp0Xr: Reverse A Linked List Using Recusion executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_a7kfeHX4Bnltp0Xr: Exception - " << e.what() << endl;
        return 0;
    }
}
