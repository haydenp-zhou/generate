#include "fun_XcrocHV3VvQhPD7H.hpp"

int fun_XcrocHV3VvQhPD7H() {
    // LeetCode Problem: Triangle

    // Solution class
    class Solution {


    public:
        int minimumTotal(vector<vector<int> > &triangle) {
            vector< vector<int> > v;

            for (int i=0; i<triangle.size(); i++){

                if(i==0){
                    v.push_back(triangle[i]);
                    continue;
                }

                vector<int> tmp;


                for(int j=0; j<triangle[i].size(); j++){
                    int x, y, z;
                    x = y = z = 0x7fff;
                    if ( (j-1) >= 0){
                        x = v[i-1][j-1];
                    }
                    if (j<v[i-1].size()) {
                        y = v[i-1][j];
                    }
                    /* won't take the previous adjacent number */
                    //if ( (j+1)<v[i-1].size()) {
                    //    z = v[i-1][j+1];
                    //}
                    tmp.push_back( min(x,y,z) + triangle[i][j] );
                }

                v.push_back(tmp);

            }
            int min=0x7fff;
            if (v.size() > 0){
                vector<int> &vb = v[v.size()-1];
                for(int i=0; i<vb.size(); i++){
                    if (vb[i] < min ){
                        min = vb[i];
                    }
                }
            }

            return min;
        }
    private:
        inline int min(int x, int y, int z){
            int n = x<y?x:y;
            return (n<z?n:z);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minimumTotal(nums);

        // Print result to prevent optimization
        cout << "fun_XcrocHV3VvQhPD7H: Executed minimumTotal() from Triangle" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_XcrocHV3VvQhPD7H: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
