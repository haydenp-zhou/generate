#include "fun_PRCVyTFfV3WUoB3O.hpp"

// Original algorithm: Pascal Triangle
int fun_PRCVyTFfV3WUoB3O() {
    try {
        #ifdef _MSC_VER
        #else
        #endif
        void show_pascal(int **arr, int n) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n + i; ++j) {
                    if (arr[i][j] == 0)
                        std::cout << std::setw(4) << " ";
                    else
                        std::cout << std::setw(4) << arr[i][j];
                }
                std::cout << std::endl;
            }
        }
        int **pascal_triangle(int **arr, int n) {
            for (int i = 0; i < n; ++i) {
                for (int j = n - i - 1; j < n + i; ++j) {
                    if (j == n - i - 1 || j == n + i - 1)
                        arr[i][j] = 1;  // The edge of the Pascal triangle goes in 1
                    else
                        arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j + 1];
                }
            }
            return arr;
        }
            pascal_triangle(arr, n);
            show_pascal(arr, n);
            for (int i = 0; i < n; ++i) {
                delete[] arr[i];
            }
            delete[] arr;
            return 0;
        }


        volatile int status = 1;
        cout << "fun_PRCVyTFfV3WUoB3O: Pascal Triangle executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_PRCVyTFfV3WUoB3O: Exception - " << e.what() << endl;
        return 0;
    }
}
