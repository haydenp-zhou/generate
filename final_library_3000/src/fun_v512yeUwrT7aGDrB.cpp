#include "fun_v512yeUwrT7aGDrB.hpp"

int fun_v512yeUwrT7aGDrB() {
    // LeetCode Problem: Additive Number

    // Solution class
    class Solution {

    public:
        bool isAdditiveNumber(string num) {
            int len = num.size();

            for(int i=1; i<len/2+1; i++) {
                string n1 = num.substr(0, i);
                if ( n1.size()>1 && n1[0] == '0') break;
                for(int j=i+1; j<len; j++) {
                    string n2 = num.substr(i, j-i);
                    if ( n2.size()>1 && n2[0] == '0') break;
                    string n3 = num.substr(j);
                    if (isAdditiveNumberHelper(n1, n2, n3)) return true;
                }
            }
            return false;
        }

    private:
        bool isAdditiveNumberHelper(string& n1, string& n2, string& n3){
            string add = StringAdd(n1, n2);

            if (add.size() > n3.size()) return false;

            if (add == n3 ) return true;

            //split the n3 to 2 parts, and keep going.
            string cut = n3.substr(0, add.size());
            if (add == cut) {
                string rest = n3.substr(add.size());
                return isAdditiveNumberHelper(n2, add, rest);
            }
            return false;
        }


        string StringAdd(string n1, string n2) {

            if (n1.size() < n2.size()) {
                string tmp = n1;
                n1 = n2;
                n2 = tmp;
            }

            int carry=0;
            string result;
            for (int i=n1.size()-1, j=n2.size()-1; i>=0; i--, j--) {

                int n = n1[i] - '0' + carry;
                if ( j >= 0) {
                    n += n2[j] - '0';
                } 
                char ch = n % 10 + '0';
                carry = n/10;
                result = ch + result;
            }
            if (carry>0) result = (char)(carry+'0') + result;
            return result;

        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.isAdditiveNumber(s);

        // Print result to prevent optimization
        cout << "fun_v512yeUwrT7aGDrB: Executed isAdditiveNumber() from Additive Number" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_v512yeUwrT7aGDrB: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
