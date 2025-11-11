#include "fun_tbnDv9de357c3thk.hpp"

// Original algorithm: Circular Queue Using Linked List
int fun_tbnDv9de357c3thk() {
    try {
        struct node {
            int data;
            struct node* next;
        };
        class Queue {
            node* front = nullptr;
            node* rear = nullptr;
            Queue(const Queue&) = delete;
            Queue& operator=(const Queue&) = delete;
         public:
            Queue() = default;
            ~Queue() {
                while (front) {
                    dequeue();
                }
            }
         private:
            void createNode(int val) {
                auto* nn = new node;
                nn->data = val;
                nn->next = nullptr;
                front = nn;
                rear = nn;
            }
         public:
            void enqueue(int val) {
                if (front == nullptr || rear == nullptr) {
                    createNode(val);
                } else {
                    node* nn = new node;
                    nn->data = val;
                    rear->next = nn;
                    nn->next = front;
                    rear = nn;
                }
            }
            void dequeue() {
                if (front == nullptr) {
                    return;
                }
                const node* const n = front;
                if (front == rear) {
                    front = nullptr;
                    rear = nullptr;
                } else {
                    front = front->next;
                    rear->next = front;
                }
                delete n;
            }
            void traverse() {
                if (front == nullptr) {
                    return;
                }
                const node* ptr = front;
                do {
                    std::cout << ptr->data << ' ';
                    ptr = ptr->next;
                } while (ptr != front);
                std::cout << '\n';
            }
        };


        volatile int status = 1;
        cout << "fun_tbnDv9de357c3thk: Circular Queue Using Linked List executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_tbnDv9de357c3thk: Exception - " << e.what() << endl;
        return 0;
    }
}
