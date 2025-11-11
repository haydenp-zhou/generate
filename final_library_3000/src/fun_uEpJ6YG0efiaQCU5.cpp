#include "fun_uEpJ6YG0efiaQCU5.hpp"

// Original algorithm: Linkedlist Implentation Usingarray
int fun_uEpJ6YG0efiaQCU5() {
    try {
        struct Node {
            int data;
            int next;
        };
        Node AvailArray[100];  ///< array that will act as nodes of a linked list.
        int head = -1;
        int avail = 0;
        void initialise_list() {
            for (int i = 0; i <= 98; i++) {
                AvailArray[i].next = i + 1;
            }
            AvailArray[99].next = -1;  // indicating the end of the linked list.
        }
        int getnode() {
            int NodeIndexToBeReturned = avail;
            avail = AvailArray[avail].next;
            return NodeIndexToBeReturned;
        }
        void freeNode(int nodeToBeDeleted) {
            AvailArray[nodeToBeDeleted].next = avail;
            avail = nodeToBeDeleted;
        }
        void insertAtTheBeginning(int data) {
            int newNode = getnode();
            AvailArray[newNode].data = data;
            AvailArray[newNode].next = head;
            head = newNode;
        }
        void insertAtTheEnd(int data) {
            int newNode = getnode();
            int temp = head;
            while (AvailArray[temp].next != -1) {
                temp = AvailArray[temp].next;
            }
            AvailArray[newNode].data = data;
            AvailArray[newNode].next = -1;
            AvailArray[temp].next = newNode;
        }
        void display() {
            int temp = head;
            while (temp != -1) {
                std::cout << AvailArray[temp].data << "->";
                temp = AvailArray[temp].next;
            }
            std::cout << "-1" << std::endl;
        }
            }
            return 0;
        }

                // Test the algorithm implementation
                cout << "Testing Linkedlist Implentation Usingarray..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_uEpJ6YG0efiaQCU5: Linkedlist Implentation Usingarray executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_uEpJ6YG0efiaQCU5: Exception - " << e.what() << endl;
        return 0;
    }
}
