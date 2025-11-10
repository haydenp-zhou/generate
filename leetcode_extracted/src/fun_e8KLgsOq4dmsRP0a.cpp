#include "fun_e8KLgsOq4dmsRP0a.hpp"

int fun_e8KLgsOq4dmsRP0a() {
    // LeetCode Problem: Maximum Subarray Min Product

    // Solution class
    class Solution {

    public:
        int maxSumMinProduct(vector<int>& nums) {
            nums.push_back(0); //edge case

            //prefix sum
            vector<long> sums(nums.size(), 0);
            // sums[i] = sum (num[0], num[1], num[2], ... num[n-1])
            // sums[m] - sums[n] = sum (num[n], sum[n+1] .... nums[m-1]);  m > n
            for(int i=0; i<nums.size()-1; i++) {
                sums[i+1] = sums[i] + nums[i];
            }

            stack<int> s;
            long m = 0;
            for(int i=0; i<nums.size(); i++) {
                while( !s.empty() && nums[s.top()] > nums[i]) {
                    int min = nums[s.top()]; s.pop();
                    int start = s.empty() ? 0 : s.top() + 1;
                    int end = i;
                    m = max(m , min * (sums[end] - sums[start]));

                    // cout << "[";
                    // for(int k = start; k < end-1; k++) {
                    //    cout << nums[k] << ",";
                    // }
                    // cout << nums[end-1] << "], " << min << "*" << (sums[end] - sums[start]) 
                    //     << "=" << min * (sums[end] - sums[start]) << endl;

                }
                // if the num is increasing, then push into stack
                s.push(i);
            }
            //cout << endl;
            return m % 1000000007;

        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.maxSumMinProduct(nums);

        // Print result to prevent optimization
        cout << "fun_e8KLgsOq4dmsRP0a: Executed maxSumMinProduct() from Maximum Subarray Min Product" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_e8KLgsOq4dmsRP0a: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
