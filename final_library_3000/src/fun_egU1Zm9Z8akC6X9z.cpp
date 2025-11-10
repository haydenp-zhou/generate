#include "fun_egU1Zm9Z8akC6X9z.hpp"

int fun_egU1Zm9Z8akC6X9z() {
    // LeetCode Problem: Count Good Meals

    // Solution class
    class Solution {

    public:
        int countPairs(vector<int>& deliciousness) {
            const int MAX_EXP = 22;
            int pow2[MAX_EXP];
            for (int i=0; i<MAX_EXP; i++){
                pow2[i] = 1 << i;
                //cout << pow2[i] << ", ";
            }

            unordered_map<int, int> stat;
            int big = 0;
            for(auto& d: deliciousness){
                stat[d]++;

            }

            long m = 0;
            for(auto& d: deliciousness){
                for(int i=MAX_EXP-1; i>=0 && pow2[i] >= d; i--){
                    int x = pow2[i] - d;
                    if ( stat.find(x) != stat.end() ){
                        m += (x==d) ? stat[x]-1 : stat[x];
                    }
                }
            }

            // remove the duplication - m/2, 
            // because both [1,3] and [3,1] are counted.
            return (m/2) % 1000000007;
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
        cout << "fun_egU1Zm9Z8akC6X9z: Executed countPairs() from Count Good Meals" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_egU1Zm9Z8akC6X9z: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
