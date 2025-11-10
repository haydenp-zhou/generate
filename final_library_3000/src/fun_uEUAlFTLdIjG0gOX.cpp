#include "fun_uEUAlFTLdIjG0gOX.hpp"

int fun_uEUAlFTLdIjG0gOX() {
    // LeetCode Problem: Evaluate Reverse Polish Notation

    // Solution class
    class Solution {

    public:
        int evalRPN(vector<string> &tokens) {
            int i =0;
            bool err = false;
            vector<int> exp;
            for (int i=0; i<tokens.size() && !err; i++ ){
                if (isNum(tokens[i])) {
                    exp.push_back(value);
                } else if( isOp(tokens[i])==true ) {
                    if (exp.size() < 2) {
                        return 0; //ERROR
                    }
                    int lhs, rhs;
                    rhs = exp.back();
                    exp.pop_back();
                    lhs = exp.back();
                    exp.pop_back();

                    int evlValue;
                    if (tokens[i]=="+"){
                        evlValue = lhs + rhs;    
                    }else if (tokens[i]=="-"){
                        evlValue = lhs - rhs;
                    }else if (tokens[i]=="*"){
                        evlValue = lhs * rhs;
                    }else if (tokens[i]=="/"){
                        evlValue = lhs / rhs;
                    }

                    exp.push_back(evlValue);

                }else {
                    return 0; //ERROR 
                }
            }

            if (exp.size()==1){
                return exp.back();
            }
            return 0;        

        }

    private:
        long value;

        bool isOp(string &op) {
            return (op=="+" || op=="-" || op=="*" || op=="/");
        }

        bool isNum(string &num) {
            char *end;
            value = strtol(num.c_str(), &end, 10); 
            if (end == num.c_str() || *end != '\0' || errno == ERANGE){
                return false;
            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.evalRPN(nums);

        // Print result to prevent optimization
        cout << "fun_uEUAlFTLdIjG0gOX: Executed evalRPN() from Evaluate Reverse Polish Notation" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_uEUAlFTLdIjG0gOX: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
