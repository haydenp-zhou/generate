#include "fun_JPAvRibv68PZHf1I.hpp"

// Original algorithm: Hash Search
int fun_JPAvRibv68PZHf1I() {
    try {
        #define MAX 6      ///< Determines how much data
        #define HASHMAX 5  ///< Determines the length of the hash table
        int data[MAX] = {1, 10, 15, 5, 8, 7};  //!< test data
        typedef struct list {
            int key;            //!< key value for node
            struct list* next;  //!< pointer to next link in the chain
        } node,                 
            *link;              ///< pointer to nodes
        node hashtab[HASHMAX];  ///< array of nodes
        int h(int key) { return key % HASHMAX; }
        void create_list(int key) {  // Construct hash table
            link p, n;
            int index;
            n = (link)malloc(sizeof(node));
            n->key = key;
            n->next = NULL;
            index = h(key);
            p = hashtab[index].next;
            if (p != NULL) {
                n->next = p;
                hashtab[index].next = n;
            } else {
                hashtab[index].next = n;
            }
        }
        int hash_search(int key, int* counter) {  // Hash lookup function
            link pointer;
            int index;
            *counter = 0;
            index = h(key);
            pointer = hashtab[index].next;
            std::cout << "data[" << index << "]:";
            while (pointer != NULL) {
                counter[0]++;
                std::cout << "data[" << pointer->key << "]:";
                if (pointer->key == key)
                    return 1;
                else
                    pointer = pointer->next;
            }
            return 0;
        }
            for (i = 0; i < HASHMAX; i++) {  // Output hash table
                std::cout << "hashtab [" << i << "]\n";
                p = hashtab[i].next;
                while (p != NULL) {
                    std::cout << "please int key:";
                    if (p->key > 0)
                        std::cout << "[" << p->key << "]";
                    p = p->next;
                }
                std::cout << std::endl;
            }
            while (key != -1) {
                key = 10;
                if (hash_search(key, &counter))
                    std::cout << "search time = " << counter << std::endl;
                else
                    std::cout << "no found!\n";
                key = -1;  // Exit test
                /* The test sample is returned as:
                 * data[0]:data[5]:data[15]:data[10]:search time = 3 The search is
                 * successful. There are 10 in this set of data */
            }
            return 0;
        }

                // Test the algorithm implementation
                cout << "Testing Hash Search..." << endl;
                vector<int> test_arr = {1, 2, 3, 4, 5};

        volatile int status = 1;
        cout << "fun_JPAvRibv68PZHf1I: Hash Search executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_JPAvRibv68PZHf1I: Exception - " << e.what() << endl;
        return 0;
    }
}
