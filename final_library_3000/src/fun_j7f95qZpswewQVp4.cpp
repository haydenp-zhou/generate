#include "fun_j7f95qZpswewQVp4.hpp"

int fun_j7f95qZpswewQVp4() {
    // LeetCode Problem: Maximum Distance Between A Pair Of Values

    // Solution class
    class Solution {

    public:
        int maxDistance(vector<int>& nums1, vector<int>& nums2) {
            return maxDistance2(nums1, nums2);
            return maxDistance1(nums1, nums2);
        }


        int binary_search(vector<int>& nums, int start, int target) {
            int end = nums.size() - 1;
            while (start <= end) {
                int mid = start + (end - start) /2;
                if(nums[mid] < target) end = mid - 1;
                else start = mid+1;
            }
            return end;
        }

        int maxDistance1(vector<int>& nums1, vector<int>& nums2) {
            int mDist=0;
            int right = nums2.size() - 1;
            for(int i=0; i<nums1.size(); i++) {
                int j = binary_search(nums2, i, nums1[i]);
                mDist = max(mDist, j-i);
            }
            return mDist;
        }

        int maxDistance2(vector<int>& nums1, vector<int>& nums2) {
            int i=0, j=0, dist = 0;
            while (i < nums1.size() && j < nums2.size() ){
                if ( nums1[i] > nums2[j] ) i++;
                else dist = max(dist, j++ - i);
            }
            return dist;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.maxDistance(nums);

        // Print result to prevent optimization
        cout << "fun_j7f95qZpswewQVp4: Executed maxDistance() from Maximum Distance Between A Pair Of Values" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_j7f95qZpswewQVp4: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
