#include "fun_J5dQsMmp5kyx5vIP.hpp"

// Original algorithm: Selectionsortlinkedlist
int fun_J5dQsMmp5kyx5vIP() {
    try {
        using namespace std;
        class node {
         public:
            int data;
            node *link;
            node(int d) {
                data = d;
                link = NULL;
            }
        };
        void print(node *head) {
            node *current = head;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->link;
            }
            cout << endl;
        }
        node *createlist(int n) {
            node *head = NULL;
            node *t = NULL;
            for (int i = 0; i < n; i++) {
                node *temp = NULL;
                int num;
                cin >> num;
                temp = new node(num);
                if (head == NULL) {
                    head = temp;
                    t = temp;
                    continue;
                }
                if (t->link == NULL)
                    t->link = temp;
                t = temp;
            }
            return head;
        }
        void my_selection_sort_linked_list(node *&head) {
            node *min = head;  // throughout the algorithm 'min' is used to denote the
            node *current =
                min->link;  // 'current' refers to the current node we are scanning
            node *previous = min;  //'previous' refers to the node that is previous to
            node *temp =
                NULL;  // 'temp' in this algo is used to point to the last node of the
            while (
                min->link !=
                NULL)  // so that all the nodes are scanned or until there exists a node
            {
                while (current != NULL)  // suppose you choose the min node to be X,
                {
                    if (current->data < min->data)  // if the current node is smaller
                    {
                        if (temp == NULL)  // temp stays null for the first iteration,
                        {
                            if (previous ==
                                min)  // if the 'previous' is pointing to the 'min' node
                            {
                                head = current;  // update the head pointer with the
                                min->link = current->link;
                                current->link = previous;
                                min = current;
                                current = previous->link;
                            } else  // if the 'previous' is not pointing to the 'min'
                            {
                                head = current;  // update the head pointer with the
                                previous->link = current->link;
                                current->link = min;
                                min = current;
                                current = previous->link;
                            }
                        } else  // if 'temp' is not NULL, i.e., its not the 1st
                        {
                            temp->link = current;
                            previous->link = current->link;
                            current->link = min;
                            min = current;
                            current = previous->link;
                        }
                    } else  // if the current node is greater than min, just move the
                    {
                        previous = previous->link;
                        current = current->link;
                    }
                }
                temp = min;
                min = min->link;
                previous = min;
                current = min->link;
            }
        }


        volatile int status = 1;
        cout << "fun_J5dQsMmp5kyx5vIP: Selectionsortlinkedlist executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_J5dQsMmp5kyx5vIP: Exception - " << e.what() << endl;
        return 0;
    }
}
