#include "fun_b9U7E46xkoDjP9Cw.hpp"

int fun_b9U7E46xkoDjP9Cw() {
    // LeetCode Problem: Number Of Valid Words For Each Puzzle

    // Solution class
    class Solution {

    public:
        vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
            static const int L = 7;
            TrieNode trie;
            for (const auto& word : words) {
                vector<int> count(26);
                for (const auto& c: word) {
                    count[c - 'a'] = 1;
                }
                const auto& total = accumulate(count.cbegin(), count.cend(), 0);
                if (total > L) {
                    continue;
                }
                trie.insert(count);
            }
            vector<int> result;
            for (auto puzzle: puzzles) {
                const auto first = puzzle[0];
                sort(puzzle.begin(), puzzle.end());
                result.emplace_back(search(&trie, puzzle, 0, first, false));
            }
            return result;
        }

    private:
        struct TrieNode;

        int search(TrieNode* node, const string& puzzle, int start, char first, bool met_first) {
            int result = 0;
            if (met_first) {
                result += node->end_count;
            }
            for (int i = start; i < puzzle.length(); ++i) {
                if (node->children[puzzle[i] - 'a'] == nullptr) {
                    continue;
                }
                result += search(node->children[puzzle[i] - 'a'], puzzle, i + 1,
                                 first, met_first || (puzzle[i] == first));
            }
            return result;
        }

        struct TrieNode {
            int end_count;
            vector<TrieNode *> children;

            TrieNode() : end_count{0}, children(26) {}

            void insert(const vector<int>& count) {
                auto* p = this;
                for (int i = 0; i < count.size(); ++i) {
                    if (!count[i]) {
                        continue;
                    }
                    if (!p->children[i]) {
                        p->children[i] = new TrieNode;
                    }
                    p = p->children[i];
                }
                ++p->end_count;
            }

            ~TrieNode() {
                for (auto& node : children) {
                    if (node) {
                        delete node;
                    }
                }
            }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.findNumOfValidWords(nums);

        // Print result to prevent optimization
        cout << "fun_b9U7E46xkoDjP9Cw: Executed findNumOfValidWords() from Number Of Valid Words For Each Puzzle" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_b9U7E46xkoDjP9Cw: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
