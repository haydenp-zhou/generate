#include "fun_RW75tcJIneBcWRlr.hpp"

// Original algorithm: Tower Of Hanoi
int fun_RW75tcJIneBcWRlr() {
    try {
        struct tower {
            int values[10];
            int top;
        };
        void show(const struct tower *const F, const struct tower *const T,
                  const struct tower *const U) {
            std::cout << "\n\n\tF : ";
            for (int i = 0; i < F->top; i++) {
                std::cout << F->values[i] << "\t";
            }
            std::cout << "\n\tU : ";
            for (int i = 0; i < U->top; i++) {
                std::cout << U->values[i] << "\t";
            }
            std::cout << "\n\tT : ";
            for (int i = 0; i < T->top; i++) {
                std::cout << T->values[i] << "\t";
            }
        }
        void mov(tower *From, tower *To) {
            --From->top;
            To->values[To->top] = From->values[From->top];
            ++To->top;
        }
        void TH(int n, tower *From, tower *Using, tower *To) {
            if (n == 1) {
                mov(From, To);
                show(From, To, Using);
            } else {
                TH(n - 1, From, To, Using);
                mov(From, To);
                show(From, To, Using);
                TH(n - 1, Using, From, To);
            }
        }
            show(&F, &T, &U);
            TH(no, &F, &U, &T);
            return 0;
        }


        volatile int status = 1;
        cout << "fun_RW75tcJIneBcWRlr: Tower Of Hanoi executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_RW75tcJIneBcWRlr: Exception - " << e.what() << endl;
        return 0;
    }
}
