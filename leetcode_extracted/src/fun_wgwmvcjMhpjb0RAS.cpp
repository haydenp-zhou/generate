#include "fun_wgwmvcjMhpjb0RAS.hpp"

int fun_wgwmvcjMhpjb0RAS() {
    // LeetCode Problem: Minimum Cost To Hire K Workers

    // Solution class
    class Solution {

    public:
        double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
            vector<pair<double, int>> workers;
            for (int i = 0; i < quality.size(); ++i) {
                workers.emplace_back(static_cast<double>(wage[i]) / quality[i], quality[i]);
            }
            sort(begin(workers), end(workers));
            auto result = numeric_limits<double>::max();
            auto sum = 0.0;
            priority_queue<int> max_heap;
            for (const auto& [ratio, q]: workers) {
                sum += q;
                max_heap.emplace(q);
                if (max_heap.size() > K) {  // keep k smallest q to make sum as small as possible
                    sum -= max_heap.top(), max_heap.pop();
                }
                if (max_heap.size() == K) {
                    result = min(result, sum * ratio);
                }
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.mincostToHireWorkers(nums);

        // Print result to prevent optimization
        cout << "fun_wgwmvcjMhpjb0RAS: Executed mincostToHireWorkers() from Minimum Cost To Hire K Workers" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_wgwmvcjMhpjb0RAS: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
