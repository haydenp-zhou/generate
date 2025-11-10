#include "fun_XI1z7dMBoQWUe5cX.hpp"

int fun_XI1z7dMBoQWUe5cX() {
    // LeetCode Problem: Minimum Number Of People To Teach

    // Solution class
    class Solution {


    public:
        bool hasLang(vector<int>& langlist, int lang){
            for(auto& l : langlist) {
                if (l == lang) return true;
            }
            return false;
        }

        bool canComm(int u, int v, int n, vector<vector<bool>>& langs) {
            for (int l=0; l<n; l++) {
                if (langs[u][l] && langs[v][l]) return true;
            }
            return false;
        }

        int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
            int persons = languages.size();
            //use to check a person know a langauge or not
            vector<vector<bool>> langs(persons, vector<bool>(n, false));
            for (int p=0; p<persons; p++) {
                for(int l=0; l<languages[p].size(); l++) {
                    langs[p][languages[p][l]-1] = true;
                }
            } 

            int result = persons;
            vector<vector<bool>> langToTeach(n, vector<bool>(persons, false));
            for (int l=0; l <n; l++) {
                int cnt = 0;
                vector<bool> teach(persons, false);
                for (auto& fs : friendships) {
                    int u = fs[0] - 1;
                    int v = fs[1] - 1;

                    if (canComm(u, v, n, langs)) continue;

                    if (langs[u][l]==false && teach[u]==false) {
                        teach[u] = true; cnt++;
                    }
                    if (langs[v][l]==false && teach[v]==false) {
                        teach[v] = true; cnt++;
                    }
                }
                result = min(result, cnt);
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
        volatile auto result = sol.hasLang(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_XI1z7dMBoQWUe5cX: Executed hasLang() from Minimum Number Of People To Teach" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_XI1z7dMBoQWUe5cX: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
