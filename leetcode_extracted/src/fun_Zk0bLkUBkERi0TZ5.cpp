#include "fun_Zk0bLkUBkERi0TZ5.hpp"

int fun_Zk0bLkUBkERi0TZ5() {
    // LeetCode Problem: Beautiful Arrangement

    // Solution class
    class Solution {

    public:
        int countArrangement(int N) {
            vector<int> arrangement(N);
            iota(arrangement.begin(), arrangement.end(), 1);
            return countArrangementHelper(N, &arrangement);
        }

    private:
        int countArrangementHelper(int n, vector<int> *arrangement) {
            if (n <= 0) {
                return 1;
            }
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if ((*arrangement)[i] % n == 0 || n % (*arrangement)[i] == 0) {
                    swap((*arrangement)[i], (*arrangement)[n - 1]);
                    count += countArrangementHelper(n - 1, arrangement);
                    swap((*arrangement)[i], (*arrangement)[n - 1]);
                }
            }
            return count;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.countArrangement(nums);

        // Print result to prevent optimization
        cout << "fun_Zk0bLkUBkERi0TZ5: Executed countArrangement() from Beautiful Arrangement" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Zk0bLkUBkERi0TZ5: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
