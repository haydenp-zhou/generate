#include "fun_P01uK8rOBCfOLR4C.hpp"

int fun_P01uK8rOBCfOLR4C() {
    // LeetCode Problem: Smallest String With Swaps

    // Solution class
    class Solution {

    public:
        string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) { 
            UnionFind union_find(s.length());
            for (const auto& pair : pairs) {
                union_find.union_set(pair[0], pair[1]);
            }
            unordered_map<int, vector<char>> components;
            for (int i = 0; i < s.length(); ++i) {
                components[union_find.find_set(i)].emplace_back(s[i]);
            }
            for (auto& [i, list] : components) {
                sort(list.begin(), list.end(), greater<char>());
            }
            for (int i = 0; i < s.length(); ++i) {
                const auto& j = union_find.find_set(i);
                s[i] = components[j].back();
                components[j].pop_back();
            }
            return s;
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
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.smallestStringWithSwaps(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_P01uK8rOBCfOLR4C: Executed smallestStringWithSwaps() from Smallest String With Swaps" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_P01uK8rOBCfOLR4C: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
