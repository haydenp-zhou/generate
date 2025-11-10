#include "fun_8vWAwUMJC8IdCn9K.hpp"

int fun_8vWAwUMJC8IdCn9K() {
    // LeetCode Problem: Restore Ip Addresses

    // Solution class
    class Solution {

        public:
            vector<string> restoreIpAddresses(string s) {
                vector<string> ans;
                dfs(s, 0, 4, "", ans);
                return ans;
            }

        private:
            void dfs(const string &s, int start, int step, string ip, vector<string> &ans) {
                if(start == s.size() && step == 0) {
                    ip.pop_back();
                    ans.push_back(ip);
                    return;
                }

                if(s.size() - start < step || s.size() - start > step * 3) // pruing
                    return;

                int num = 0;
                for(int i = start; i < start + 3; ++i) {
                    num = num * 10 + s[i] - '0';
                    if(num > 255) break;
                    ip += s[i];
                    dfs(s, i + 1, step - 1, ip + '.', ans);
                    if(num == 0) break; // only one 0
                }
            }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.restoreIpAddresses(strs);

        // Print result to prevent optimization
        cout << "fun_8vWAwUMJC8IdCn9K: Executed restoreIpAddresses() from Restore Ip Addresses" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_8vWAwUMJC8IdCn9K: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
