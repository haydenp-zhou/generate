#include "fun_WPErIE2LkJOT5zEc.hpp"

// Original algorithm: Linear Search
int fun_WPErIE2LkJOT5zEc() {
    try {
        int LinearSearch(int *array, int size, int key) {
            for (int i = 0; i < size; ++i) {
                if (array[i] == key) {
                    return i;
                }
            }
            /* We reach here only in case element is not present in array, return an
             * invalid entry in that case*/
            return -1;
        }
        static void tests() {
            int size = 4;
            int *array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = i;
            }
            assert(LinearSearch(array, size, 0) == 0);
            assert(LinearSearch(array, size, 1) == 1);
            assert(LinearSearch(array, size, 2) == 2);
            delete[] array;
            size = 6;
            array = new int[size];
            for (int i = 0; i < size; i++) {
                array[i] = i;
            }
            assert(LinearSearch(array, size, 3) == 3);
            assert(LinearSearch(array, size, 1) == 1);
            assert(LinearSearch(array, size, 5) == 5);
            std::cout << "All tests have successfully passed!\n";
            delete[] array;  // free memory up
        }
                int *array = new int[size];
                int key = 0;
                std::cout << "Enter the array of " << size << " numbers: ";
                for (int i = 0; i < size; i++) {
                    std::cin >> array[i];
                }
                std::cout << "\nEnter the number to be searched: ";
                std::cin >> key;
                int index = LinearSearch(array, size, key);
                if (index != -1) {
                    std::cout << "Number found at index: " << index << "\n";
                } else {
                    std::cout << "Array element not found";
                }
                delete[] array;
            } else {
                tests();  // run self-test implementations
            }
            return 0;
        }

                // Test the algorithm implementation
                cout << "Testing Linear Search..." << endl;
                vector<int> test_arr = {1, 2, 3, 4, 5};

        volatile int status = 1;
        cout << "fun_WPErIE2LkJOT5zEc: Linear Search executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_WPErIE2LkJOT5zEc: Exception - " << e.what() << endl;
        return 0;
    }
}
