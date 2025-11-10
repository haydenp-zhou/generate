#include "fun_VdEoRf9PTdOjm9um.hpp"

int fun_VdEoRf9PTdOjm9um() {
    // LeetCode Problem: Grid Illumination

    // Solution class
    class Solution {

    public:
        vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
            unordered_set<int64_t> lookup;
            unordered_map<int, int> row, col, diag, anti;
            for (const auto& lamp : lamps) {
                int r, c;
                tie(r, c) = make_pair(lamp[0], lamp[1]);
                if (!lookup.emplace(static_cast<int64_t>(r) * N + c).second) {
                    continue;
                }
                ++row[r];
                ++col[c];
                ++diag[r - c];
                ++anti[r + c];
            }

            vector<int> result;
            for (const auto& query : queries) {
                int r, c;
                tie(r, c) = make_pair(query[0], query[1]);
                if (!(row[r] || col[c] || diag[r - c] || anti[r + c])) {
                    result.emplace_back(0);
                    continue;
                }
                result.emplace_back(1);
                for (int nr = max(r - 1, 0); nr <= min(r + 1, N - 1); ++nr) {
                    for (int nc = max(c - 1, 0); nc <= min(c + 1, N - 1); ++nc) {
                        if (!lookup.erase(static_cast<int64_t>(nr) * N + nc)) {
                            continue;
                        }
                        --row[nr];
                        --col[nc];
                        --diag[nr - nc];
                        --anti[nr + nc];
                    }
                }
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
        volatile auto result = sol.gridIllumination(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_VdEoRf9PTdOjm9um: Executed gridIllumination() from Grid Illumination" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_VdEoRf9PTdOjm9um: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
