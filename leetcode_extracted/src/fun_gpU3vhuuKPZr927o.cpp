#include "fun_gpU3vhuuKPZr927o.hpp"

int fun_gpU3vhuuKPZr927o() {
    // LeetCode Problem: Hand Of Straights

    // Solution class
    class Solution {

    public:
        bool isNStraightHand(vector<int>& hand, int W) {
            if (hand.size() % W) {
                return false;
            }

            unordered_map<int, int> counts;
            for (const auto& i : hand) {
                ++counts[i];
            }

            priority_queue<int, vector<int>, greater<int>> min_heap(hand.begin(), hand.end());
            for (int i = 0; i < hand.size() / W; ++i) {
                while (counts[min_heap.top()] == 0) {
                    min_heap.pop();
                }
                int start = min_heap.top(); min_heap.pop();
                for (int j = 0; j < W; ++j) {
                    --counts[start];
                    if (counts[start] < 0) {
                        return false;
                    }
                    ++start;
                }
            }
            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.isNStraightHand(nums);

        // Print result to prevent optimization
        cout << "fun_gpU3vhuuKPZr927o: Executed isNStraightHand() from Hand Of Straights" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_gpU3vhuuKPZr927o: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
