#include "fun_JXErkGbxYktCETYx.hpp"

int fun_JXErkGbxYktCETYx() {
    // LeetCode Problem: Friends Of Appropriate Ages

    // Solution class
    class Solution {

    public:
        int numFriendRequests(vector<int>& ages) {
            unordered_map<int, int> count;
            for (const auto &age : ages) {
                ++count[age];
            }
            int result = 0;
            for (const auto &a: count) {
                for (const auto &b: count) {
                    if (request(a.first, b.first)) {
                        result += a.second * (b.second - (a.first == b.first ? 1 : 0));
                    }
                }
            }
            return result;
        }

    private:
        bool request(int a, int b) {
            return 0.5 * a + 7 < b && b <= a;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.numFriendRequests(nums);

        // Print result to prevent optimization
        cout << "fun_JXErkGbxYktCETYx: Executed numFriendRequests() from Friends Of Appropriate Ages" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_JXErkGbxYktCETYx: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
