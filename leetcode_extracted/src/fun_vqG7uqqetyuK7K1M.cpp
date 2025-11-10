#include "fun_vqG7uqqetyuK7K1M.hpp"

int fun_vqG7uqqetyuK7K1M() {
    // LeetCode Problem: Minimize Malware Spread Ii

    // Solution class
    class Solution {

    public:
        int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
            unordered_set<int> initial_set(initial.cbegin(), initial.cend());
            vector<int> clean;
            for (int i = 0; i < graph.size(); ++i) {
                if (!initial_set.count(i)) {
                    clean.emplace_back(i);
                }
            }
            UnionFind union_find(graph.size());
            for (int i = 0; i < clean.size(); ++i) {
                for (int j = i + 1; j < clean.size(); ++j) {
                    if (graph[clean[i]][clean[j]] == 1) {
                        union_find.union_set(clean[i], clean[j]);
                    }
                }
            }
            unordered_map<int, int> union_size;
            for (int i = 0; i < graph.size(); ++i) {
                ++union_size[union_find.find_set(i)];
            }

            unordered_map<int, unordered_set<int>> shared_union;
            for (const auto& i: initial) {
                for (const auto& j : clean) {
                    if (graph[i][j] == 1) {
                        auto x = union_find.find_set(j);
                        shared_union[x].emplace(i);
                    }
                }
            }

            int result = numeric_limits<int>::max();
            int total = numeric_limits<int>::min();   
            for (const auto& i : initial) {
                unordered_set<int> lookup;
                int curr = 0;
                for (const auto& j : clean) {
                    if (graph[i][j] == 1) {
                        auto x = union_find.find_set(j);
                        if (shared_union[x].size() == 1 &&
                            !lookup.count(x)) {
                            curr += union_size[x];
                            lookup.emplace(x);
                        }
                    }
                }
                if (curr > total ||
                    (curr == total && i < result)) {
                    total = curr;
                    result = i;
                }
            }
            return result;
        }

    private:
        class UnionFind {
            public:
                UnionFind(const int n) : set_(n) {
                    iota(set_.begin(), set_.end(), 0);
                }

                int find_set(const int x) {
                   if (set_[x] != x) {
                       set_[x] = find_set(set_[x]);  // Path compression.
                   }
                   return set_[x];
                }

                bool union_set(const int x, const int y) {
                    int x_root = find_set(x), y_root = find_set(y);
                    if (x_root == y_root) {
                        return false;
                    }
                    set_[min(x_root, y_root)] = max(x_root, y_root);
                    return true;
                }

            private:
                vector<int> set_;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.minMalwareSpread(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_vqG7uqqetyuK7K1M: Executed minMalwareSpread() from Minimize Malware Spread Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_vqG7uqqetyuK7K1M: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
