#include "fun_RuK2b7fDx5j3U2T7.hpp"

int fun_RuK2b7fDx5j3U2T7() {
    // LeetCode Problem: Divide Chocolate

    // Solution class
    class Solution {

    public:
        int maximizeSweetness(vector<int>& sweetness, int K) {
            int left = *min_element(sweetness.cbegin(), sweetness.cend());
            int right = accumulate(sweetness.cbegin(), sweetness.cend(), 0) / (K + 1);
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (!check(sweetness, K, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        }

    private:
        bool check(const vector<int>& sweetness, int K, int x) {
            int curr = 0, cuts = 0;
            for (const auto& s : sweetness) {
                curr += s;
                if (curr >= x) {
                    ++cuts;
                    curr = 0;
                }
            }
            return cuts >= K + 1;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.maximizeSweetness(nums);

        // Print result to prevent optimization
        cout << "fun_RuK2b7fDx5j3U2T7: Executed maximizeSweetness() from Divide Chocolate" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_RuK2b7fDx5j3U2T7: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
