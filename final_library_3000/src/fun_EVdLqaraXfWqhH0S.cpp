#include "fun_EVdLqaraXfWqhH0S.hpp"

int fun_EVdLqaraXfWqhH0S() {
    // LeetCode Problem: Random Pick With Blacklist

    // Solution class
    class Solution {

    public:
        Solution(int N, vector<int> blacklist) :
            n_(N - blacklist.size()) {
            unordered_set<int> whitelist;
            for (int i = n_; i < N; ++i) {
                whitelist.emplace(i);
            }
            for (const auto& black : blacklist) {
                whitelist.erase(black);
            }
            auto white = whitelist.cbegin();
            for (const auto& black : blacklist) {
                if (black < n_) {
                    lookup_[black] = *(white++);
                }
            }
        }

        int pick() {
            int index = rand() % n_;
            return lookup_.count(index) ? lookup_[index] : index;
        }

    private:
        int n_;
        unordered_map<int, int> lookup_;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.Solution(nums);

        // Print result to prevent optimization
        cout << "fun_EVdLqaraXfWqhH0S: Executed Solution() from Random Pick With Blacklist" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_EVdLqaraXfWqhH0S: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
