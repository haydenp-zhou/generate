#include "fun_6cFBXU9MXuWo47Ux.hpp"

int fun_6cFBXU9MXuWo47Ux() {
    // LeetCode Problem: Count Of Smaller Numbers After Self

    // Solution class
    class Solution {

    public:
        vector <int> sorted, sol, fenwick;
        int n;
        int search(int t)
        {
            int step = 0;
            for(; (1 << step) <= n; step++);
            int i = 0;
            for(int k = step; k >= 0; k--)
                if(i + (1 << k) < n && sorted[i + (1 << k)] <= t)
                    i += (1 << k);
            return i;
        }
        int compute(int t)
        {
            int s = 0;
            for(int i = t; i > 0; i -= zeros(i))
                s += fenwick[i];
            return s;
        }
        void add(int t)
        {
            for(int i = t; i <= n; i += zeros(i))
                fenwick[i]++;
        }
        vector<int> countSmaller(vector<int>& nums) {
            if(nums.size())
            {
                sorted = nums;
                n = nums.size();
                sort(sorted.begin(), sorted.end());
                vector <int> f(sorted.size());
                fenwick = f;
                for(int i = nums.size() - 1; i >= 0; i--)
                {
                    int pos = search(nums[i]) + 1;
                    sol.push_back(compute(pos - 1));
                    add(pos);
                }
                reverse(sol.begin(), sol.end());
            }
            return sol;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.search(nums);

        // Print result to prevent optimization
        cout << "fun_6cFBXU9MXuWo47Ux: Executed search() from Count Of Smaller Numbers After Self" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_6cFBXU9MXuWo47Ux: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
