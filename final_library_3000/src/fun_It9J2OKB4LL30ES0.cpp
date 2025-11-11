#include "fun_It9J2OKB4LL30ES0.hpp"

// Original algorithm: Radix Sort
int fun_It9J2OKB4LL30ES0() {
    try {
        void radixsort(int a[], int n) {
            int count[10];
            int* output = new int[n];
            memset(output, 0, n * sizeof(*output));
            memset(count, 0, sizeof(count));
            int max = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] > max) {
                    max = a[i];
                }
            }
            int maxdigits = 0;
            while (max) {
                maxdigits++;
                max /= 10;
            }
            for (int j = 0; j < maxdigits; j++) {
                for (int i = 0; i < n; i++) {
                    int t = std::pow(10, j);
                    count[(a[i] % (10 * t)) / t]++;
                }
                int k = 0;
                for (int p = 0; p < 10; p++) {
                    for (int i = 0; i < n; i++) {
                        int t = std::pow(10, j);
                        if ((a[i] % (10 * t)) / t == p) {
                            output[k] = a[i];
                            k++;
                        }
                    }
                }
                memset(count, 0, sizeof(count));
                for (int i = 0; i < n; ++i) {
                    a[i] = output[i];
                }
            }
            delete[] output;
        }
        void print(int a[], int n) {
            for (int i = 0; i < n; ++i) {
                std::cout << a[i] << " ";
            }
            std::cout << std::endl;
        }
        ;
            int n = sizeof(a) / sizeof(a[0]);
            radixsort(a, n);
            print(a, n);
            return 0;
        }


        volatile int status = 1;
        cout << "fun_It9J2OKB4LL30ES0: Radix Sort executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_It9J2OKB4LL30ES0: Exception - " << e.what() << endl;
        return 0;
    }
}
