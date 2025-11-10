#include "fun_Tj45hnx3W5sJzt13.hpp"

int fun_Tj45hnx3W5sJzt13() {
    // LeetCode Problem: Count Pairs With Xor In A Range

    // Solution class
    class Solution {

    private:
        // Count elements in Trie whose XOR with N less than K 
        int countSmallerPairs(TrieNode * root,  int N, int K) { 
            // Stores count of elements whose XOR with N less than K 
            int cntPairs = 0; 
            // Traverse binary representation of N and K in Trie 
            for (int i = LEVEL; i >= 0 && root; i--) {                 
                bool x = N & (1 << i); // Stores ith bit of N 
                bool y = K & (1 << i); // Stores ith bit of K 

                // If the ith bit of K is 0 
                if (y == 0 ) { 
                    // find the number which bit is same as N
                    // so that they can be xored to ZERO
                    root = root->child[x]; 
                    continue;
                } 
                // If the ith bit of K is 1 
                // If an element already present in Trie having ith bit (x)
                if(root->child[x]) {
                    // find the number which bit is same as N
                    // so that they can be xored to ZERO. so it would be smaller than K
                    cntPairs  += root->child[x]->cnt; 
                }
                //go to another way for next bit count
                root = root->child[1 - x]; 
            } 
            return cntPairs; 
        } 
    public:
        int countPairs(vector<int>& nums, int low, int high) {

            TrieNode* root = new TrieNode();

            int cnt = 0;
            for (auto& num : nums) {
                cnt += countSmallerPairs(root, num, high + 1) - countSmallerPairs(root, num, low);
                insertTrie(root, num);
            }


            return cnt;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.countPairs(nums);

        // Print result to prevent optimization
        cout << "fun_Tj45hnx3W5sJzt13: Executed countPairs() from Count Pairs With Xor In A Range" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Tj45hnx3W5sJzt13: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
