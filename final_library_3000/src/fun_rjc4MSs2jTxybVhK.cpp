#include "fun_rjc4MSs2jTxybVhK.hpp"

int fun_rjc4MSs2jTxybVhK() {
    // LeetCode Problem: Rearrange String K Distance Apart

    // Solution class
    class Solution {

    public:
        string rearrangeString(string s, int k) {
            if (!k) {
                return s;
            }
            unordered_map<char, int> cnts;
            for (const auto& c : s) {
                ++cnts[c];
            }
            const int bucket_cnt = max_element(cbegin(cnts), cend(cnts), [](const auto& a, const auto& b) {
                return a.second < b.second;
            })->second;
            if (!((bucket_cnt - 1) * k + count_if(cbegin(cnts), cend(cnts), [&](const auto& x) { return x.second == bucket_cnt; }) <= size(s))) {
                return "";
            }
            vector<char> partial_sorted_cnts;
            for (const auto& [c, v] : cnts) {
                if (v == bucket_cnt) {
                    partial_sorted_cnts.emplace_back(c);
                }
            }
            for (const auto& [c, v] : cnts) {
                if (v != bucket_cnt) {
                    partial_sorted_cnts.emplace_back(c);
                }
            }
            string result(size(s), 0);
            int i = (size(s) - 1) % k;
            for (const auto& c : partial_sorted_cnts) {
                for (int _ = 0; _ < cnts[c]; ++_) {
                    result[i] = c;
                    i += k;
                    if (i >= size(result)) {
                        i = (i - 1) % k;
                    }
                }
            }
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
        volatile auto result = sol.rearrangeString(s);

        // Print result to prevent optimization
        cout << "fun_rjc4MSs2jTxybVhK: Executed rearrangeString() from Rearrange String K Distance Apart" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_rjc4MSs2jTxybVhK: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
