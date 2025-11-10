#include "fun_rCzfEFtdp63btNj0.hpp"

int fun_rCzfEFtdp63btNj0() {
    // LeetCode Problem: Satisfiability Of Equality Equations

    // Solution class
    class Solution {

    private:
        map<char, char>  eq_map; // the table store the equivalent relationship
        void init() {
            for (char ch='a'; ch<='z'; ch++) {
                eq_map[ch] = ch;
            }
        }
    public:
        Solution() {
            init();
        }

        // find the tail node, 
        // if a == b == c == d, find(a) would return d;
        //                      find(b) would return d;
        char find(char ch) {
            while(ch != eq_map[ch]) {
                ch = eq_map[ch];
            }
            return ch;
        }

        //join x equivalent chain with y equivalent chain
        void join(char x, char y) {
            char tx = find(x);
            char ty = find(y);
            if (tx != ty) { 
                eq_map[tx] = ty;
            }
        }

        bool equationsPossible(vector<string>& equations) {
            for (auto e : equations ) {
                if (e[1] == '=' && e[0] != e[3]) { // equal
                    join(e[0], e[3]);
                }
            }
            for (auto e : equations) {
                if (e[1] == '!' && (e[0] == e[3] || find(e[0]) == find(e[3]) ) ) { 
                    return false;
                }
            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.Solution(strs);

        // Print result to prevent optimization
        cout << "fun_rCzfEFtdp63btNj0: Executed Solution() from Satisfiability Of Equality Equations" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_rCzfEFtdp63btNj0: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
