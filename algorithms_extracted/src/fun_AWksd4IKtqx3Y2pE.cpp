#include "fun_AWksd4IKtqx3Y2pE.hpp"

// Original algorithm: Queue Using Linked List
int fun_AWksd4IKtqx3Y2pE() {
    try {
        using namespace std;
        struct node {
            int val;
            node *next;
        };
        node *front, *rear;
        void Enque(int x) {
            if (rear == NULL) {
                node *n = new node;
                n->val = x;
                n->next = NULL;
                rear = n;
                front = n;
            }
            else {
                node *n = new node;
                n->val = x;
                n->next = NULL;
                rear->next = n;
                rear = n;
            }
        }
        void Deque() {
            if (rear == NULL && front == NULL) {
                cout << "\nUnderflow";
            } else {
                node *t = front;
                cout << "\n" << t->val << " deleted";
                front = front->next;
                delete t;
                if (front == NULL)
                    rear = NULL;
            }
        }
        void show() {
            node *t = front;
            while (t != NULL) {
                cout << t->val << "\t";
                t = t->next;
            }
        }
         else if (ch == 2) {
                    Deque();
                } else if (ch == 3) {
                    show();
                }
            } while (ch != 0);
            return 0;
        }


        volatile int status = 1;
        cout << "fun_AWksd4IKtqx3Y2pE: Queue Using Linked List executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_AWksd4IKtqx3Y2pE: Exception - " << e.what() << endl;
        return 0;
    }
}
