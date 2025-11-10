#include "fun_iR5lj9upwOylHcR3.hpp"

int fun_iR5lj9upwOylHcR3() {
    // LeetCode Problem: Check For Contradictions In Equations

    // Solution class
    class Solution {

    public:
        bool checkContradictions(vector<vector<string>>& equations, vector<double>& values) {
            static const double EPS = 1e-5;
            UnionFind uf;
            for (int i = 0; i < size(equations); ++i) {
                if (!uf.union_set(equations[i][0], equations[i][1], values[i]) &&
                    abs(uf.query_set(equations[i][0], equations[i][1]) - values[i]) > EPS) {
                    return true;
                }
            }
            return false;
        }

    private:
        class UnionFind {
        public:
            UnionFind() {
            }

            pair<string, double> find_set(const string& x) {
                if (!set_.count(x)) {
                    set_[x] = pair(x, 1.0);
                }
                const auto& [xp, xr] = set_[x];
                if (x != xp) {
                    const auto& [pp, pr] = find_set(xp);  // Path compression.
                    set_[x] = pair(pp, xr * pr);
                }
                return set_[x];
            }

            bool union_set(const string& x, const string& y, double r) {
                const auto& [xp, xr] = find_set(x);
                const auto& [yp, yr] = find_set(y);
                if (xp == yp) {
                    return false;
                }
                if (rank_[xp] < rank_[yp]) {  // Union by rank.
                    set_[xp] = pair(yp, r * yr / xr);
                } else if (rank_[xp] > rank_[yp]) {
                    set_[yp] = pair(xp, 1.0 / r * xr / yr);
                } else {
                    set_[yp] = pair(xp, 1.0 / r * xr / yr);
                    ++rank_[xp];
                }
                return true;
            }

            double query_set(const string& x, const string& y) {
                if (!set_.count(x) || !set_.count(y)) {
                    return -1.0;
                }
                const auto& [xp, xr] = find_set(x);
                const auto& [yp, yr] = find_set(y);
                return (xp == yp) ? xr / yr : -1.0;
            }

        private:
            unordered_map<string, pair<string, double>> set_;
            unordered_map<string, int> rank_;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.checkContradictions(strs);

        // Print result to prevent optimization
        cout << "fun_iR5lj9upwOylHcR3: Executed checkContradictions() from Check For Contradictions In Equations" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_iR5lj9upwOylHcR3: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
