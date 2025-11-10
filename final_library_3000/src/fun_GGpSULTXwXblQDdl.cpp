#include "fun_GGpSULTXwXblQDdl.hpp"

int fun_GGpSULTXwXblQDdl() {
    // LeetCode Problem: Find The Winner Of An Array Game

    // Solution class
    class Solution {

    public:
        int getWinner(vector<int>& arr, int k) { 

            int left=0, right=1;

            int max = arr[left] > arr[right] ? arr[left] : arr[right];
            int winner; 
            int win_times = 0;

            while( right < arr.size())  {

                //if left < right,  the move the `left` to the `right`
                if ( arr[left] < arr[right] ) {
                    left = right;
                }
                // move the `right` to next element
                right++;
                //record current round winner.
                int w = arr[left];            

                if (w == winner) {
                    //if winner is same, count++
                    win_times++; 
                }else{
                    // if winner is new number, reset the count.
                    winner = w;
                    win_times = 1;
                }

                // if the time of win equal K, return winner. 
                if (win_times >= k) return winner;

                // find the max element of this array, if k > arr.size() then return this
                if (max < arr[right]) max = arr[right];
            }

            return max;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.getWinner(nums);

        // Print result to prevent optimization
        cout << "fun_GGpSULTXwXblQDdl: Executed getWinner() from Find The Winner Of An Array Game" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_GGpSULTXwXblQDdl: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
