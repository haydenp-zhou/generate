#include "fun_c58BKi8GzJ2ytBXs.hpp"

// Original algorithm: Circular Queue Using Array
int fun_c58BKi8GzJ2ytBXs() {
    try {
        using std::cin;
        using std::cout;
        int queue[10];
        int front = 0;
        int rear = 0;
        int count = 0;
        void Enque(int x) {
            if (count == 10) {
                cout << "\nOverflow";
            } else {
                queue[rear] = x;
                rear = (rear + 1) % 10;
                count++;
            }
        }
        void Deque() {
            if (front == rear) {
                cout << "\nUnderflow";
            }
            else {
                cout << "\n" << queue[front] << " deleted";
                front = (front + 1) % 10;
                count--;
            }
        }
        void show() {
            for (int i = 0; i < count; i++) {
                cout << queue[(i + front) % 10] << "\t";
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
        cout << "fun_c58BKi8GzJ2ytBXs: Circular Queue Using Array executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_c58BKi8GzJ2ytBXs: Exception - " << e.what() << endl;
        return 0;
    }
}
