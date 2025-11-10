#include "fun_HXYsyG2ZPfdihEr3.hpp"

int fun_HXYsyG2ZPfdihEr3() {
    // LeetCode Problem: Statistics From A Large Sample

    // Solution class
    class Solution {

    public:
        vector<double> sampleStats(vector<int>& count) {
            const double mi = distance(count.cbegin(), find_if(count.cbegin(), count.cend(), 
                                       [](int x) { return x != 0; }));

            const double ma = count.size() - 1 - 
                              distance(count.crbegin(), find_if(count.crbegin(), count.crend(), 
                                       [](int x) { return x != 0; }));

            const auto& n = accumulate(count.cbegin(), count.cend(), 0);
            double total = 0.0;
            for (int i = 0; i < count.size(); ++i) {
                total += double(i) * count[i];
            }
            const double mean = total / n;

            const double mode = distance(count.cbegin(), max_element(count.cbegin(), count.cend()));

            for (int i = 1; i < count.size(); ++i) {
                count[i] += count[i - 1];
            }
            const auto& median1 = distance(count.cbegin(), lower_bound(count.cbegin(), count.cend(), (n + 1) / 2));
            const auto& median2 = distance(count.cbegin(), lower_bound(count.cbegin(), count.cend(), (n + 2) / 2));
            const double median = (median1 + median2) / 2.0;

            return {mi, ma, mean, median, mode
    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.sampleStats(nums);

        // Print result to prevent optimization
        cout << "fun_HXYsyG2ZPfdihEr3: Executed sampleStats() from Statistics From A Large Sample" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_HXYsyG2ZPfdihEr3: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
