#include "fun_HSn7F0gWfaUEwH7h.hpp"

int fun_HSn7F0gWfaUEwH7h() {
    // LeetCode Problem: Search Suggestions System

    // Solution class
    class Solution {

    public:
        vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
            TrieNode trie;
            for (int i = 0; i < products.size(); ++i) {
                trie.insert(products, i);
            }
            auto curr = &trie;
            vector<vector<string>> result(searchWord.length());
            for (int i = 0; i < searchWord.length(); ++i) {  // Time: O(l)
                if (!curr->leaves.count(searchWord[i])) {
                    break;
                }
                curr = curr->leaves[searchWord[i]];
                for (const auto& j : curr->infos) {
                    result[i].emplace_back(products[j]);
                }
            }
            return result;
        }

    class TrieNode {
        public:
            static const int TOP_COUNT = 3;

            ~TrieNode() {
                for (auto& kv : leaves) {
                    if (kv.second) {
                        delete kv.second;
                    }
                }
            }

            // Time:  O(l)
            void insert(const vector<string>& words, int i) {
                auto* curr = this;
                for (const auto& c : words[i]) {
                    if (!curr->leaves.count(c)) {
                        curr->leaves[c] = new TrieNode;
                    }
                    curr = curr->leaves[c];
                    curr->add_info(words, i);
                }
            }

            // Time:  O(l)
            void add_info(const vector<string>& words, int i) {
                infos.emplace_back(i);
                sort(infos.begin(), infos.end(),
                     [&words](const auto& a, const auto& b) {
                         return words[a] < words[b];
                     });
                if (infos.size() > TOP_COUNT) {
                    infos.pop_back();
                }
            }

            vector<int> infos;
            unordered_map<char, TrieNode *> leaves;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.suggestedProducts(nums);

        // Print result to prevent optimization
        cout << "fun_HSn7F0gWfaUEwH7h: Executed suggestedProducts() from Search Suggestions System" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_HSn7F0gWfaUEwH7h: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
