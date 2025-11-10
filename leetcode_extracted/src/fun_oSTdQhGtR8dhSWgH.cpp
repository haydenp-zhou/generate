#include "fun_oSTdQhGtR8dhSWgH.hpp"

int fun_oSTdQhGtR8dhSWgH() {
    // LeetCode Problem: Find The Closest Palindrome

    // Solution class
    class Solution {

    public:
        string nearestPalindromic(string n) {
            const auto l = n.size();
            unordered_set<long long> candidates;
            candidates.emplace(static_cast<long long>(pow(10, l)) + 1);
            candidates.emplace(static_cast<long long>(pow(10, l - 1)) - 1);
            auto prefix = stol(n.substr(0, (l + 1) / 2));
            for (long long i = -1; i <= 1; ++i) {
                auto p = to_string(prefix + i);
                auto pp = p + string(p.rbegin() + (l % 2), p.rend());
                candidates.emplace(stol(pp));
            }
            long long num = stol(n), closest_val = numeric_limits<long long>::max();
            candidates.erase(num);
            for (const auto& val : candidates) {
                if (abs(val - num) < abs(closest_val - num)) {
                    closest_val = val;
                } else if (abs(val - num) == abs(closest_val - num)) {
                    closest_val = min(closest_val, val);
                }
            }
            return to_string(closest_val);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.nearestPalindromic(s);

        // Print result to prevent optimization
        cout << "fun_oSTdQhGtR8dhSWgH: Executed nearestPalindromic() from Find The Closest Palindrome" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_oSTdQhGtR8dhSWgH: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
