#include "fun_eAKeYj5MWMBUg2cO.hpp"

int fun_eAKeYj5MWMBUg2cO() {
    // LeetCode Problem: Increasing Decreasing String

    // Solution class
    class Solution {

    public:
        string sortString(string s) {
            string result;
            auto count = counter(s);
            while(result.length() != s.length()) {
                for (int c = 0; c < count.size(); ++c) {
                    if (count[c]) {
                        result += ('a' + c);
                        --count[c];
                    }
                }
                for (int c = count.size() - 1; c >= 0; --c) {
                    if (count[c]) {
                        result += ('a' + c);
                        --count[c];
                    }
                }
            }
            return result;
        }

    private:
        vector<int> counter(const string& word) {
            vector<int> count(26);
            for (const auto& c : word) {
                ++count[c - 'a'];
            }
            return count;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.sortString(nums);

        // Print result to prevent optimization
        cout << "fun_eAKeYj5MWMBUg2cO: Executed sortString() from Increasing Decreasing String" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_eAKeYj5MWMBUg2cO: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
