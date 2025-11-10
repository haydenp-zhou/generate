#include "fun_oHkDCEF9iyXrw3Jh.hpp"

int fun_oHkDCEF9iyXrw3Jh() {
    // LeetCode Problem: Number Of Ways To Split String

    // Solution class
    class Solution {

    public:
        int numWays(string s) {

            int n = s.size();

            vector<int> pre(n),suf(n),last(n);
            int count=0;

            for(int i=0;i<n;i++){
                if(s[i]=='1'){
                    count++;
                }
                pre[i]=count;
            }

            // check if it can't be divided into three parts
            if(count%3!=0)
                return 0;

            int k  = count/3;
            count=0;
            int t=0;

            for(int i=n-1;i>=0;i--){
                if(s[i]=='1')
                    count++;
                suf[i]=count;
            }

            count=0;

            for(int i=n-1;i>=0;i--){

                if(suf[i]==k)
                    count++;
                last[i]=count;
            }

            ll res=0;

            for(int i=0;i<n-1;i++){

                if(pre[i]==k){

                    if(k!=0)
                        res= (res+last[i+1])%mod;
                    else
                        res=(res+last[i+1]-1)%mod;
                }
            }

            return res;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.numWays(nums);

        // Print result to prevent optimization
        cout << "fun_oHkDCEF9iyXrw3Jh: Executed numWays() from Number Of Ways To Split String" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_oHkDCEF9iyXrw3Jh: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
