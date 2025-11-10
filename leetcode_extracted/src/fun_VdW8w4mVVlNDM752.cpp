#include "fun_VdW8w4mVVlNDM752.hpp"

int fun_VdW8w4mVVlNDM752() {
    // LeetCode Problem: Course  Schedule  I I

    // Solution class
    class Solution {

    public:
        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
            int n=numCourses;
            int m=prerequisites.size();
            vector<int>ans;
            vector<int>v(n,0);
            vector<vector<int>>g(n);


            for(int i=0;i<m;i++){
                g[prerequisites[i][1]].push_back(prerequisites[i][0]);
                v[prerequisites[i][0]]++;
            }
            queue<int>q;
            for(int i=0;i<n;i++){
                if(v[i]==0){
                    q.push(i);
                }
            }
            int c=0;
            while(!q.empty()){
                int j=q.front();
                q.pop();
                ans.push_back(j);
                cout<<j<<" ";
                c++;
                for(int i=0;i<g[j].size();i++){
                    v[g[j][i]]--;
                    //cout<<v[g[j][i]]<<" ";
                    if(v[g[j][i]]==0){

                        q.push(g[j][i]);
                    }
                }
            }
            if(ans.size()!=n){
                return {
    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.findOrder(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_VdW8w4mVVlNDM752: Executed findOrder() from Course  Schedule  I I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_VdW8w4mVVlNDM752: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
