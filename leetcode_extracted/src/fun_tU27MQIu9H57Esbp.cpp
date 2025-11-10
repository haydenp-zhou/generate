#include "fun_tU27MQIu9H57Esbp.hpp"

int fun_tU27MQIu9H57Esbp() {
    // LeetCode Problem: Remove Letter To Equalize Frequency

    // Solution class
    class Solution {

    public:
        bool equalFrequency(string word) {
            vector<int> cnt(26);
            for (const auto& c : word) {
                ++cnt[c - 'a'];
            }
            unordered_map<int, int> cnt2;
            for (const auto& c : cnt) {
                if (c) {
                    ++cnt2[c];
                }
            }
            if (size(cnt2) > 2) {
                return false;
            }
            if (size(cnt2) == 1) {
                return cbegin(cnt2)->first == 1 || cbegin(cnt2)->second == 1;
            }
            int a = cbegin(cnt2)->first;
            int b = next(cbegin(cnt2))->first;
            if (a > b) {
                swap(a, b);
            }
            return (a == 1 && cnt2[a] == 1) || (a + 1 == b && cnt2[b] == 1);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.equalFrequency(nums);

        // Print result to prevent optimization
        cout << "fun_tU27MQIu9H57Esbp: Executed equalFrequency() from Remove Letter To Equalize Frequency" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_tU27MQIu9H57Esbp: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
