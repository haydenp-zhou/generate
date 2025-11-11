#include "fun_efHKpCjOgYuiB2va.hpp"

// Original algorithm: Stack Using Linked List
int fun_efHKpCjOgYuiB2va() {
    try {
        struct node {
            int val;
            node *next;
        };
        node *top_var;
        void push(int x) {
            node *n = new node;
            n->val = x;
            n->next = top_var;
            top_var = n;
        }
        void pop() {
            if (top_var == nullptr) {
                std::cout << "\nUnderflow";
            } else {
                node *t = top_var;
                std::cout << "\n" << t->val << " deleted";
                top_var = top_var->next;
                delete t;
            }
        }
        void show() {
            node *t = top_var;
            while (t != nullptr) {
                std::cout << t->val << "\n";
                t = t->next;
            }
        }
            } while (ch != 0);
            return 0;
        }


        volatile int status = 1;
        cout << "fun_efHKpCjOgYuiB2va: Stack Using Linked List executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_efHKpCjOgYuiB2va: Exception - " << e.what() << endl;
        return 0;
    }
}
