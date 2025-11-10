#include "fun_KoYbPVpeVheJsDf0.hpp"

int fun_KoYbPVpeVheJsDf0() {
    // LeetCode Problem: Minimum Genetic Mutation

    // Solution class
    class Solution {

    public:
        int minMutation(string start, string end, vector<string>& bank) {
            unordered_map<string, bool> lookup;
            for (const auto& b : bank) {
                lookup.emplace(b, false);
            }

            queue<pair<string, int>> q;
            q.emplace(start, 0);
            while (!q.empty()) {
                string cur;
                int level;
                tie(cur, level) = q.front(); q.pop();

                if (cur == end) {
                    return level;
                }

                for (int i = 0; i < cur.size(); ++i) {
                    auto cur_copy = cur;
                    for (const auto& c : {'A', 'T', 'C', 'G'}) {
                        if (cur_copy[i] == c) {
                            continue;
                        }
                        cur_copy[i] = c;
                        if (lookup.count(cur_copy) && lookup[cur_copy] == false) {
                            q.emplace(cur_copy, level + 1);
                            lookup[cur_copy] = true;
                        }
                    }
                }
            }

            return -1;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.minMutation(strs);

        // Print result to prevent optimization
        cout << "fun_KoYbPVpeVheJsDf0: Executed minMutation() from Minimum Genetic Mutation" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_KoYbPVpeVheJsDf0: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
