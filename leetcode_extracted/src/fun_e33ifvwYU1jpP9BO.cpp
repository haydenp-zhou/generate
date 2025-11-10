#include "fun_e33ifvwYU1jpP9BO.hpp"

int fun_e33ifvwYU1jpP9BO() {
    // LeetCode Problem: Maximum Number Of Occurrences Of A Substring

    // Solution class
    class Solution {

    public:
        int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
            static const uint64_t M = 1000000007;
            static const uint64_t p = 113; 
            uint64_t power = pow(p, minSize - 1, M), rolling_hash = 0;

            int left = 0;
            unordered_map<int, int> lookup;
            unordered_map<char, int> count;
            for (int right = 0; right < s.length(); ++right) {
                ++count[s[right]];
                if (right - left + 1 > minSize) {
                    --count[s[left]];
                    rolling_hash = (rolling_hash + M - (s[left] * power) % M) % M;
                    if (!count[s[left]]) {
                        count.erase(s[left]);
                    }
                    ++left;
                }
                rolling_hash = ((rolling_hash * p) % M + s[right]) % M;
                if (right - left + 1 == minSize && count.size() <= maxLetters) {
                    ++lookup[rolling_hash];
                }
            }
            return lookup.empty()
                   ? 0 
                   : max_element(lookup.cbegin(), lookup.cend(), 
                                 [](const auto& a, const auto& b) {
                                     return a.second < b.second;
                                 })->second;
        }

    private:
        uint64_t pow(uint64_t a,uint64_t b, uint64_t m) {
            a %= m;
            uint64_t result = 1;
            while (b) {
                if (b & 1) {
                    result = (result * a) % m;
                }
                a = (a * a) % m;
                b >>= 1;
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.maxFreq(s);

        // Print result to prevent optimization
        cout << "fun_e33ifvwYU1jpP9BO: Executed maxFreq() from Maximum Number Of Occurrences Of A Substring" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_e33ifvwYU1jpP9BO: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
