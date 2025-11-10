#include "fun_lvAfWKsMq7nqZk84.hpp"

int fun_lvAfWKsMq7nqZk84() {
    // LeetCode Problem: Maximum Score Words Formed By Letters

    // Solution class
    class Solution {

    public:
        int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
            unordered_map<char, int> letter_count;
            vector<unordered_map<char, int>> word_counts(words.size());
            vector<int> word_scores(words.size());
            for (const auto& c : letters) {
                ++letter_count[c];
            }
            for (int i = 0; i < words.size(); ++i) {
                for (const auto& c : words[i]) {
                    ++word_counts[i][c];
                    word_scores[i] += score[c - 'a'];
                }
            }
            int result = 0;
            backtracking(words, word_scores, word_counts, 0, 0, &letter_count, &result);
            return result;
        }

    private:
        void backtracking(const vector<string>& words,
                          const vector<int>& word_scores,
                          const vector<unordered_map<char, int>>& word_counts,
                          int curr,
                          int curr_score,
                          unordered_map<char, int> *letter_count,
                          int *result) {
            *result = max(*result, curr_score);
            for (int i = curr; i < words.size(); ++i) {
                if (any_of(word_counts[i].cbegin(), word_counts[i].cend(),
                           [&letter_count](const auto& x) {
                               return (*letter_count)[x.first] < x.second;
                           })) {
                    continue;
                }
                for (const auto& [k, v] : word_counts[i]) {
                    (*letter_count)[k] -= v;
                }
                backtracking(words, word_scores, word_counts,
                             i + 1, curr_score + word_scores[i], letter_count, result);
                for (const auto& [k, v] : word_counts[i]) {
                    (*letter_count)[k] += v;
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
        volatile auto result = sol.maxScoreWords(nums);

        // Print result to prevent optimization
        cout << "fun_lvAfWKsMq7nqZk84: Executed maxScoreWords() from Maximum Score Words Formed By Letters" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_lvAfWKsMq7nqZk84: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
