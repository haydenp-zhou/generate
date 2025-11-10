#include "fun_7UL7RfZckzt0PgoC.hpp"

int fun_7UL7RfZckzt0PgoC() {
    // LeetCode Problem: Exclusive Time Of Functions

    // Solution class
    class Solution {

    public:
        vector<int> exclusiveTime(int n, vector<string>& logs) {
            vector<int> result(n);
            stack<int> stk;
            int prev = 0;
            for (const auto& log : logs) {
                vector<string> tokens = split(log, ':');
                if (tokens[1] == "start") {
                    if (!stk.empty()) {
                        result[stk.top()] += stoi(tokens[2]) - prev;
                    }
                    stk.emplace(stoi(tokens[0]));
                    prev = stoi(tokens[2]);
                } else {
                    result[stk.top()] += stoi(tokens[2]) - prev + 1;
                    stk.pop();
                    prev = stoi(tokens[2]) + 1;
                }
            }
            return result;
        }

    private:
        vector<string> split(const string& s, const char delim) {
            vector<string> tokens;
            stringstream ss(s);
            string token;
            while (getline(ss, token, delim)) {
                tokens.emplace_back(token);
            }
            return tokens;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<string> strs = {"hello", "world", "test", "code"};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.exclusiveTime(nums);

        // Print result to prevent optimization
        cout << "fun_7UL7RfZckzt0PgoC: Executed exclusiveTime() from Exclusive Time Of Functions" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_7UL7RfZckzt0PgoC: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
