#include "fun_s00gSMXNyz6qabu2.hpp"

int fun_s00gSMXNyz6qabu2() {
    // LeetCode Problem: Count Almost Equal Pairs Ii

    // Solution class
    class Solution {

    public:
        int countPairs(vector<int>& nums) {
            static const int L = 7;
            vector<int> POW10(L);
            POW10[0] = 1;
            for (int i = 0; i + 1 < L; ++i) {
                POW10[i+1] = POW10[i] * 10;
            }
            unordered_map<int, int> cnt1;
            for (const auto& x : nums) {
                ++cnt1[x];
            }
            unordered_map<int, vector<int>> adj;
            vector<pair<int, int>> cnt;
            for (const auto& [k, v] : cnt1) {
                cnt.emplace_back(k, v);
            }
            for (int idx = 0; idx < size(cnt); ++idx) {
                adj[cnt[idx].first].emplace_back(idx);
                for (int i = 0; i < L; ++i) {
                    const int a = cnt[idx].first / POW10[i] % 10;
                    for (int j = i + 1; j < L; ++j) {
                        const int b = cnt[idx].first /POW10[j] % 10;
                        if (a == b) {
                            continue;
                        }
                        adj[cnt[idx].first - a * (POW10[i] - POW10[j]) + b * (POW10[i] - POW10[j])].emplace_back(idx);
                    }
                }
            }
            int result = 0;
            for (const auto& [_, v] : cnt1) {
                result += v * (v - 1) / 2;
            }
            unordered_map<int, unordered_set<int>> lookup;
            for (const auto& [u, _] : adj) {
                for (int i = 0; i < size(adj[u]); ++i) {
                    const int v1 = cnt[adj[u][i]].second;
                    for (int j = i + 1; j < size(adj[u]); ++j) {
                        const int v2 = cnt[adj[u][j]].second;
                        if (lookup[adj[u][i]].count(adj[u][j])) {
                            continue;
                        }
                        lookup[adj[u][i]].emplace(adj[u][j]);
                        result += v1 * v2;
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

    // Execute solution
    try {
        volatile auto result = sol.countPairs(nums);

        // Print result to prevent optimization
        cout << "fun_s00gSMXNyz6qabu2: Executed countPairs() from Count Almost Equal Pairs Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_s00gSMXNyz6qabu2: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
