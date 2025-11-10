#include "fun_rZzwPb2672WDPSTt.hpp"

int fun_rZzwPb2672WDPSTt() {
    // LeetCode Problem: Sentence Similarity Ii

    // Solution class
    class Solution {

    public:
        bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
            if (words1.size() != words2.size()) {
                return false;
            }
            unordered_map<string, int> lookup;
            UnionFind union_find(2 * pairs.size());
            for (const auto& pair : pairs) {
                if (!lookup.count(pair.first)) {
                    lookup.emplace(pair.first, lookup.size());
                }
                if (!lookup.count(pair.second)) {
                    lookup.emplace(pair.second, lookup.size());
                }
                union_find.union_set(lookup[pair.first], lookup[pair.second]);
            }
            for (int i = 0; i < words1.size(); ++i) {
                if (words1[i] != words2[i] && 
                    (!lookup.count(words1[i]) || !lookup.count(words2[i]) ||
                    union_find.find_set(lookup[words1[i]]) != 
                    union_find.find_set(lookup[words2[i]]))) {
                    return false;
                }
            }
            return true;
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
    vector<string> strs = {"hello", "world", "test", "code"};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.areSentencesSimilarTwo(nums);

        // Print result to prevent optimization
        cout << "fun_rZzwPb2672WDPSTt: Executed areSentencesSimilarTwo() from Sentence Similarity Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_rZzwPb2672WDPSTt: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
