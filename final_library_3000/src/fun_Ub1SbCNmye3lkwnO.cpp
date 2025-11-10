#include "fun_Ub1SbCNmye3lkwnO.hpp"

int fun_Ub1SbCNmye3lkwnO() {
    // LeetCode Problem: Count Pairs Of Nodes

    // Solution class
    class Solution {

    public:
        vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
            vector<int> degree(n+1);
            unordered_map<int, unordered_map<int, int>> shared;
            for (auto& e : edges) {
                int x = e[0], y = e[1];
                degree[x]++;
                degree[y]++;
                shared[min(x,y)][max(x,y)]++;
            }

            vector<int> sorted = degree;
            sort(sorted.begin(), sorted.end());

            vector<int> result;
            for (auto& q : queries) {
                int cnt = 0;
                int left = 1, right = n;
                //Assuming all of the nodes are independent.
                while( left < right ) {
                    if (q < sorted[left] + sorted[right] ) {
                        cnt += (right - left);
                        right--;
                    }else {
                        left++;
                    }
                }
                //check all of pair they are connected.
                for (int i = 1; i <= n; i++){
                    for (auto [j, shared_edges] : shared[i]) {
                        int all_edges = degree[i] + degree[j];
                        // `q < all_edges`  ==> this pair had been counted before!
                        // `q >= all_edges - shared_edges` ==> this pair should be counted!
                        if ( q < all_edges && q >= all_edges - shared_edges ) {
                            cnt--;
                        }
                    }
                }
                result.push_back(cnt);
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.countPairs(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_Ub1SbCNmye3lkwnO: Executed countPairs() from Count Pairs Of Nodes" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Ub1SbCNmye3lkwnO: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
