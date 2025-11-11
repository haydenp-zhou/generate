#include "fun_raMVRxMBnRoyfxeM.hpp"

// Original algorithm: Get Size Of Linked List
int fun_raMVRxMBnRoyfxeM() {
    try {
        class Node {
         public:
            int val;
            Node *next;
            Node(int v, Node *n) : val(v), next(n) {}  // Default constructor for Node
        };
        int getSize(Node *root) {
            if (root == NULL) {
                return 0;
            }
            return 1 + getSize(root->next);
        }
        /*
         * @brief This function dealocates memory related to the given list
         * It recursively deletes all of the nodes of the input list.
         * @param room the root/head of the input list
         * @warning Plese note that the memory for each node has to be alocated using new.
         */
        void deleteList(Node *const root) {
            if (root != NULL)
            {
                deleteList(root->next);
                delete root;
            }
        }
            Node *secondList = new Node(0, NULL);  // List of size 1
            Node *thirdList = NULL;                // List of size 0
            std::cout << getSize(myList) << std::endl
                      << getSize(secondList) << std::endl
                      << getSize(thirdList) << std::endl;
            deleteList(secondList);
            deleteList(myList);
            return 0;
        }

                // Test the algorithm implementation
                cout << "Testing Get Size Of Linked List..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_raMVRxMBnRoyfxeM: Get Size Of Linked List executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_raMVRxMBnRoyfxeM: Exception - " << e.what() << endl;
        return 0;
    }
}
