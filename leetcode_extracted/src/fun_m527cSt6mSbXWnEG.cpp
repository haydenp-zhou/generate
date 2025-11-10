#include "fun_m527cSt6mSbXWnEG.hpp"

int fun_m527cSt6mSbXWnEG() {
    // LeetCode Problem: Maximum Number Of Tasks You Can Assign

    // Solution class
    class Solution {

    public:
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            sort(begin(tasks), end(tasks));
            sort(begin(workers), end(workers));
            int left = 1, right = min(size(tasks), size(workers));
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (!check(tasks, workers, pills, strength, mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return right;
        }

    private:
        bool check(const vector<int>& tasks, const vector<int>& workers,
                   int pills, int strength,
                   int x) {

            multiset<int> t(cbegin(tasks), cbegin(tasks) + x);
            for (int i = size(workers) - x; i < size(workers); ++i) {  // enumerate from the weakest worker to the strongest worker, greedily assign him to the hardest task which he can do
                auto it = t.upper_bound(workers[i]);
                if (it != begin(t)) {
                    t.erase(prev(it));
                    continue;
                }
                if (pills) {
                    it = t.upper_bound(workers[i] + strength);
                    if (it != begin(t)) {
                        t.erase(prev(it));
                        --pills;
                        continue;
                    }
                }
                return false;
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
        volatile auto result = sol.maxTaskAssign(nums);

        // Print result to prevent optimization
        cout << "fun_m527cSt6mSbXWnEG: Executed maxTaskAssign() from Maximum Number Of Tasks You Can Assign" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_m527cSt6mSbXWnEG: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
