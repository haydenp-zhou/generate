#include "fun_h2qtDiwrMzbQ5qmW.hpp"

int fun_h2qtDiwrMzbQ5qmW() {
    // LeetCode Problem: Binary Watch

    // Solution class
    class Solution {

    private:
        void combination(int nLED, int nLight, int max, bool zero,
                         int start, int k, int solution, 
                         vector<vector<string>>& result) {
            if (solution > max){
                return;
            }
            if (k == 0) {
                char tmp[5] = "";
                if (zero) {
                    sprintf(tmp, "%02d", solution);
                }else{
                    sprintf(tmp, "%d", solution);
                }
                result[nLight].push_back(tmp);
                return;
            }
            for (int i=start; i<=nLED-k; i++) {
                solution += pow(2, i);
                combination(nLED, nLight, max, zero, i+1, k-1, solution, result);
                solution -= pow(2, i);
            }
        }

        void generate_combination(int nLED, int max, bool zero, vector<vector<string>>& result) {
            for (int i=0; i<nLED; i++) {
                combination(nLED, i, max, zero, 0, i, 0, result);
            }
        }

        void print(vector<vector<string>>&  vv) {
            for(auto v : vv) {
                cout << "[ ";
                for (auto i : v) {
                    cout << i << " ";
                }
                cout << "]" << endl;
            }
        }

    private:
        vector<vector<string>> hour;
        vector<vector<string>> mins;

    public:

        Solution():hour(4, vector<string>()), mins(6, vector<string>()){
            generate_combination(4, 11, false, hour);
            //print(hour);
            //[ 0 ]
            //[ 1 2 4 8 ]
            //[ 3 5 9 6 10 ]
            //[ 7 11 ]


            generate_combination(6, 59, true, mins);
            //print(mins);
            //[ 00 ]
            //[ 01 02 04 08 16 32 ]
            //[ 03 05 09 17 33 06 10 18 34 12 20 36 24 40 48 ]
            //[ 07 11 19 35 13 21 37 25 41 49 14 22 38 26 42 50 28 44 52 56 ]
            //[ 15 23 39 27 43 51 29 45 53 57 30 46 54 58 ]
            //[ 31 47 55 59 ]        
        }

        vector<string> readBinaryWatch(int num) {

            vector<string> result;
            for (int i = 0; i <= 3 && i <= num; i++) {
                if (num - i > 5) {
                    continue;
                }
                for (auto h : hour[i]) {
                    for (auto m : mins[num - i]) {
                        result.push_back( h + ":" + m );
                    }
                }

            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.Solution(strs);

        // Print result to prevent optimization
        cout << "fun_h2qtDiwrMzbQ5qmW: Executed Solution() from Binary Watch" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_h2qtDiwrMzbQ5qmW: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
