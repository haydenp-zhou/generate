#include "fun_M66A2Xp06ddjaIiT.hpp"

// Original algorithm: String Fibonacci
int fun_M66A2Xp06ddjaIiT() {
    try {
        #ifdef _MSC_VER
        #else
        #endif
        std::string add(std::string a, std::string b) {
            std::string temp = "";
            int carry = 0;
            while (a.length() < b.length()) {
                a = "0" + a;
            }
            while (b.length() < a.length()) {
                b = "0" + b;
            }
            for (int i = a.length() - 1; i >= 0; i--) {
                char val = static_cast<char>(((a[i] - 48) + (b[i] - 48)) + 48 + carry);
                if (val > 57) {
                    carry = 1;
                    val -= 10;
                } else {
                    carry = 0;
                }
                temp = val + temp;
            }
            if (carry == 1) {
                temp = "1" + temp;
            }
            while (temp[0] == '0' && temp.length() > 1) {
                temp = temp.substr(1);
            }
            return temp;
        }
        void fib_Accurate(uint64_t n) {
            std::string tmp = "";
            std::string fibMinus1 = "1";
            std::string fibMinus2 = "0";
            for (uint64_t i = 0; i < n; i++) {
                tmp = add(fibMinus1, fibMinus2);
                fibMinus2 = fibMinus1;
                fibMinus1 = tmp;
            }
            std::cout << fibMinus2;
        }


        volatile int status = 1;
        cout << "fun_M66A2Xp06ddjaIiT: String Fibonacci executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_M66A2Xp06ddjaIiT: Exception - " << e.what() << endl;
        return 0;
    }
}
