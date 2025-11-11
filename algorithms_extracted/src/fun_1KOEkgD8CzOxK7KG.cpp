#include "fun_1KOEkgD8CzOxK7KG.hpp"

// Original algorithm: Queue Using Linkedlist
int fun_1KOEkgD8CzOxK7KG() {
    try {
        /*
            Write a program to implement Queue using linkedlist.
        */
        struct linkedlist {
            int data;
            linkedlist *next;
        };
        class stack_linkedList {
         public:
            linkedlist *front;
            linkedlist *rear;
            stack_linkedList() { front = rear = NULL; }
            void enqueue(int);
            int dequeue();
            void display();
        };
        void stack_linkedList::enqueue(int ele) {
            linkedlist *temp = new linkedlist();
            temp->data = ele;
            temp->next = NULL;
            if (front == NULL)
                front = rear = temp;
            else {
                rear->next = temp;
                rear = temp;
            }
        }
        int stack_linkedList::dequeue() {
            linkedlist *temp;
            int ele;
            if (front == NULL)
                std::cout << "\nStack is empty";
            else {
                temp = front;
                ele = temp->data;
                if (front == rear)  // if length of queue is 1;
                    rear = rear->next;
                front = front->next;
                delete (temp);
            }
            return ele;
        }
        void stack_linkedList::display() {
            if (front == NULL)
                std::cout << "\nStack is empty";
            else {
                linkedlist *temp;
                temp = front;
                while (temp != NULL) {
                    std::cout << temp->data << " ";
                    temp = temp->next;
                }
            }
        }
         else if (op == 2)
                    data = ob.dequeue();
                else if (op == 3)
                    ob.display();
                else if (op == 4)
                    exit(0);
                else
                    std::cout << "\nWrong choice ";
            }
            return 0;
        }

                // Test the algorithm implementation
                cout << "Testing Queue Using Linkedlist..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_1KOEkgD8CzOxK7KG: Queue Using Linkedlist executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_1KOEkgD8CzOxK7KG: Exception - " << e.what() << endl;
        return 0;
    }
}
