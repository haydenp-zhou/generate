#include "fun_TtCmusBA20pVeu3L.hpp"

int fun_TtCmusBA20pVeu3L() {
    // LeetCode Problem: Number Of Pairs Of Strings With Concatenation Equal To Target

    // Solution class
    class Solution {

    public:
        int numOfPairs(vector<string>& nums, string target) {
            unordered_map<int, int> lookup;
            int result = 0;
            for (const auto& num : nums) {
                if (size(num) > size(target)) {
                    continue;
                }
                const int cnt1 = lookup[-(size(target) - size(num))], cnt2 = lookup[size(target) - size(num)];
                if (!target.compare(0, size(num), num)) {  // in c++ 20, we can directly use starts_with, see https://en.cppreference.com/w/cpp/string/basic_string/starts_with
                    result += cnt1;
                    ++lookup[size(num)];
                }
                if (!target.compare(size(target) - size(num), size(num), num)) {  // in c++ 20, we can directly use ends_with, see https://en.cppreference.com/w/cpp/string/basic_string/ends_with
                    result += cnt2;
                    ++lookup[-size(num)];
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
        volatile auto result = sol.numOfPairs(strs);

        // Print result to prevent optimization
        cout << "fun_TtCmusBA20pVeu3L: Executed numOfPairs() from Number Of Pairs Of Strings With Concatenation Equal To Target" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_TtCmusBA20pVeu3L: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
