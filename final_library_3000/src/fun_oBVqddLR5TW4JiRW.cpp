#include "fun_oBVqddLR5TW4JiRW.hpp"

// Original algorithm: Decimal To Binary
int fun_oBVqddLR5TW4JiRW() {
    try {
        void method1(int number) {
            int remainder, binary = 0, var = 1;
            do {
                remainder = number % 2;
                number = number / 2;
                binary = binary + (remainder * var);
                var = var * 10;
            } while (number > 0);
            std::cout << "Method 1 : " << binary << std::endl;
        }
        void method2(int number) {
            int num_bits = 0;
            char bit_string[50];
            do {
                bool bit = number & 0x01;  // get last bit
                if (bit)
                    bit_string[num_bits++] = '1';
                else
                    bit_string[num_bits++] = '0';
                number >>= 1;  // right shift bit 1 bit
            } while (number > 0);
            std::cout << "Method 2 : ";
            while (num_bits >= 0)
                std::cout << bit_string[num_bits--];  // print from MSB to LSB
            std::cout << std::endl;
        }


        volatile int status = 1;
        cout << "fun_oBVqddLR5TW4JiRW: Decimal To Binary executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_oBVqddLR5TW4JiRW: Exception - " << e.what() << endl;
        return 0;
    }
}
