#include "fun_0LeK94Y78nCFptTu.hpp"

// Original algorithm: Queue Using Array2
int fun_0LeK94Y78nCFptTu() {
    try {
        int queue[10];
        int front = 0;
        int rear = 0;
        void Enque(int x) {
            if (rear == 10) {
                std::cout << "\nOverflow";
            } else {
                queue[rear++] = x;
            }
        }
        void Deque() {
            if (front == rear) {
                std::cout << "\nUnderflow";
            }
            else {
                std::cout << "\n" << queue[front++] << " deleted";
                for (int i = front; i < rear; i++) {
                    queue[i - front] = queue[i];
                }
                rear = rear - front;
                front = 0;
            }
        }
        void show() {
            for (int i = front; i < rear; i++) {
                std::cout << queue[i] << "\t";
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
        cout << "fun_0LeK94Y78nCFptTu: Queue Using Array2 executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_0LeK94Y78nCFptTu: Exception - " << e.what() << endl;
        return 0;
    }
}
