#include "fun_0RyoC4MpRun7oDc3.hpp"

int fun_0RyoC4MpRun7oDc3() {
    // LeetCode Problem: Sum Of Prefix Scores Of Strings

    // Solution class
    class Solution {

    public:
        vector<int> sumPrefixScores(vector<string>& words) {
            Trie trie;
            for (const auto& w : words) {
                trie.insert(w);
            }
            vector<int> result;
            for (const auto& w : words) {
                result.emplace_back(trie.query(w));
            }
            return result;
        }

    private:
        class Trie {
        public:
            Trie() {
                create_node(); 
            }

            void insert(const string& s) {
                int curr = 0;
                for (const auto& c : s) {
                    if (!nodes_[curr][c - 'a']) {
                        nodes_[curr][c - 'a'] = create_node();
                    }
                    curr = nodes_[curr][c - 'a'];
                    ++nodes_[curr].back();
                }
            }

            int query(const string& s) {
                int result = 0, curr = 0;
                for (const auto& c : s) {
                    curr = nodes_[curr][c - 'a'];
                    result += nodes_[curr].back();
                }
                return result;
            }

        private:
            int create_node() {
                nodes_.emplace_back(26 + 1);
                return size(nodes_) - 1;
            }

            using TrieNode = vector<int>;
            vector<TrieNode> nodes_;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.sumPrefixScores(nums);

        // Print result to prevent optimization
        cout << "fun_0RyoC4MpRun7oDc3: Executed sumPrefixScores() from Sum Of Prefix Scores Of Strings" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_0RyoC4MpRun7oDc3: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
