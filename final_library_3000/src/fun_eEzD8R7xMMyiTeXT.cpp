#include "fun_eEzD8R7xMMyiTeXT.hpp"

int fun_eEzD8R7xMMyiTeXT() {
    // LeetCode Problem: Combination Sum2

    // Solution class
    class Solution {

        public:
            vector<vector<int> > combinationSum2(vector<int> &num, int target) {
                sort(num.begin(), num.end());
                vector<vector<int> > ans;
                vector<int> v;
                dfs(num, target, 0, v, ans);
                return ans;
            }

        private:
            void dfs(vector<int>& num, int gap, int begin, vector<int>& v,vector<vector<int> > &ans) {
                if (gap == 0) {
                    ans.push_back(v);
                    return;
                }

                for (size_t i = begin; i < num.size(); i++) {
                    if (gap < num[i]) return; // pruning
                    if( i > begin && num[i] == num[i - 1]) // skip duplicates
                        continue;
                    v.push_back(num[i]);
                    dfs(num, gap - num[i], i + 1, v, ans); // each element could be chosen only once
                    v.pop_back();
                }
            }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.combinationSum2(nums);

        // Print result to prevent optimization
        cout << "fun_eEzD8R7xMMyiTeXT: Executed combinationSum2() from Combination Sum2" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_eEzD8R7xMMyiTeXT: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
