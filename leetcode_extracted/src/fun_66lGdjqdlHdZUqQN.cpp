#include "fun_66lGdjqdlHdZUqQN.hpp"

int fun_66lGdjqdlHdZUqQN() {
    // LeetCode Problem: Length Of The Longest Valid Substring

    // Solution class
    class Solution {

    public:
        int longestValidSubstring(string word, vector<string>& forbidden) {
            Trie trie;
            for (const auto& w : forbidden) {
                trie.insert(w);
            }
            int result = 0;
            for (int left = size(word) - 1, right = size(word) - 1; left >= 0; --left) {
                for (int i = left, curr = 0; i <= right; ++i) {
                    curr = trie.child(curr, word[i]);
                    if (!curr) {  // O(l) times
                        break;
                    }
                    if (trie.is_string(curr)) {
                        right = i - 1;
                        break;
                    }
                }
                result = max(result, right - left + 1);
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
                }
                ++nodes_[curr].back();
            }

            int child(int curr, char c) const {
                return nodes_[curr][c - 'a'];
            }

            bool is_string(int curr) const {
                return nodes_[curr].back();
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
        volatile auto result = sol.longestValidSubstring(nums);

        // Print result to prevent optimization
        cout << "fun_66lGdjqdlHdZUqQN: Executed longestValidSubstring() from Length Of The Longest Valid Substring" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_66lGdjqdlHdZUqQN: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
