#include "fun_YJm6RuTOn2ypk1ub.hpp"

int fun_YJm6RuTOn2ypk1ub() {
    // LeetCode Problem: Kth Largest Element In An Array

    // Solution class
    class Solution {

    public:
        //STL using qsort to solve this problem
        int findKthLargest_buildin(vector<int>& nums, int k) {
            int n=nums.size();
            std::nth_element(nums.begin(),nums.end()-k,nums.end());
            return nums[n-k];
        }

        //qsort partition
        int partition(vector<int>& nums, int left, int right) {
            int pivot = nums[left];
            int l = left + 1, r = right;
            while (l <= r) {
                if (nums[l] < pivot && nums[r] > pivot){
                    swap(nums[l++], nums[r--]);
                }
                if (nums[l] >= pivot) l++;
                if (nums[r] <= pivot) r--;
            }
            swap(nums[left], nums[r]);
            return r;
        }

        int findKthLargest_qsort(vector<int>& nums, int k) {
            int left = 0, right = nums.size() - 1;
            while (true) {
                int pos = partition(nums, left, right);
                if (pos == k - 1){ 
                    return nums[pos];
                }
                if (pos > k - 1) {
                    right = pos - 1;
                }else{
                    left = pos + 1;  
                }  
            }
        }


        int findKthLargest(vector<int>& nums, int k) {
            return findKthLargest_qsort(nums, k);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.findKthLargest_buildin(nums);

        // Print result to prevent optimization
        cout << "fun_YJm6RuTOn2ypk1ub: Executed findKthLargest_buildin() from Kth Largest Element In An Array" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_YJm6RuTOn2ypk1ub: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
