#include "fun_ZKlniu8TTvYpJm5K.hpp"

int fun_ZKlniu8TTvYpJm5K() {
    // LeetCode Problem: Longest String Chain

    // Solution class
    class Solution {

    public:
        int longestStrChain(vector<string>& words) {
            sort(words.begin(), words.end(),
                 [](const string& a, const string& b) {
                     return less<int>()(a.length(), b.length());
                 });
            unordered_map<string, int> dp;
            for (const auto& w : words) {
                for (int i = 0; i < w.length(); ++i) {
                    auto tmp = w.substr(0, i);
                    tmp += w.substr(i + 1);
                    dp[w] = max(dp[w], dp[tmp] + 1);
                }
            }
            using pair_type = decltype(dp)::value_type;
            return max_element(dp.cbegin(), dp.cend(),
                               [] (const pair_type& a,
                                   const pair_type& b) {
                                   return a.second < b.second;
                               })->second;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.longestStrChain(strs);

        // Print result to prevent optimization
        cout << "fun_ZKlniu8TTvYpJm5K: Executed longestStrChain() from Longest String Chain" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_ZKlniu8TTvYpJm5K: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
