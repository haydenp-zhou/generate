#include "fun_rCUkqNpi6Zr99ilH.hpp"

int fun_rCUkqNpi6Zr99ilH() {
    // LeetCode Problem: Minimize Malware Spread

    // Solution class
    class Solution {

    public:
        int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
            UnionFind union_find(graph.size());
            for (int i = 0; i < graph.size(); ++i) {
                for (int j = i + 1; j < graph.size(); ++j) {
                    if (graph[i][j] == 1) {
                        union_find.union_set(i, j);
                    }
                }
            }
            unordered_map<int, int> union_size;
            for (int i = 0; i < graph.size(); ++i) {
                ++union_size[union_find.find_set(i)];
            }
            unordered_map<int, int> malware_count;
            for (const auto& i : initial) {
                ++malware_count[union_find.find_set(i)];
            }
            return *min_element(initial.cbegin(), initial.cend(), 
                                [&](const int& a, const int& b) {
                                    return make_tuple(malware_count[union_find.find_set(a)] > 1 ? 1 : 0,
                                                     -union_size[union_find.find_set(a)],
                                                     a) < 
                                           make_tuple(malware_count[union_find.find_set(b)] > 1 ? 1 : 0,
                                                     -union_size[union_find.find_set(b)],
                                                     b);
                                });
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
        cout << "fun_rCUkqNpi6Zr99ilH: Executed minMalwareSpread() from Minimize Malware Spread" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_rCUkqNpi6Zr99ilH: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
