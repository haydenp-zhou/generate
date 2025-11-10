#include "fun_KiaaS4koJuHh1caR.hpp"

int fun_KiaaS4koJuHh1caR() {
    // LeetCode Problem: Power Of Three

    // Solution class
    class Solution {


    public:

        bool isPowerOfThree(int n) {
            return isPowerOfThree03(n); //140ms
            return isPowerOfThree02(n);//130ms
            return isPowerOfThree01(n); //140ms
            return isPowerOfThree_loop(n);  //136ms
            return isPowerOfThree_recursive(n); //168ms
        }

        bool isPowerOfThree03(int n) {
            double logRes = log10(n)/log10(3); 
            return (logRes - int(logRes) == 0);
        }
        bool isPowerOfThree02(int n) {
            return n>0 ? (1162261467%n==0) : false;
        }

        void init(unordered_map<int, bool>& power ){
            int p = 1;
            power[1]=true;
            while(1){
                p *= 3;
                power[p] = true;
                if (p > INT_MAX/3) break;

            }
        }
        bool isPowerOfThree01(int n) {
            static unordered_map<int, bool> power; 
            if (power.size()==0) init(power);
            return power.find(n) != power.end();
        }

        bool isPowerOfThree_loop(int n) {
            for(;n>0;n /= 3){
                if (n==1 || n==3) return true;
                if (n%3 != 0) return false;
            }
            return false;
        }

        bool isPowerOfThree_recursive(int n) {
            if ( n == 1 || n == 3) return true;
            if ( n==0 || n%3 != 0 ) return false;
            return isPowerOfThree_recursive(n/3);
        } 

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.isPowerOfThree(n);

        // Print result to prevent optimization
        cout << "fun_KiaaS4koJuHh1caR: Executed isPowerOfThree() from Power Of Three" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_KiaaS4koJuHh1caR: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
