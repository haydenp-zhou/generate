#include "fun_qQqZG1VWwYy13HUP.hpp"

int fun_qQqZG1VWwYy13HUP() {
    // LeetCode Problem: Word Abbreviation

    // Solution class
    class Solution {

    public:
        vector<string> wordsAbbreviation(vector<string>& dict) {
            unordered_map<string, unordered_set<string>> abbr_to_word;
            unordered_map<string, string> word_to_abbr;

            for (const auto& word : dict) {
                const auto prefix = word.substr(0, 1);
                abbr_to_word[toAbbr(prefix, word)].emplace(word);
            }

            for (const auto& kvp : abbr_to_word) {
                if (kvp.second.size() > 1) {
                    for (const auto& word : kvp.second) {
                        for (int i = 2; i < word.length(); ++i) {
                            const auto prefix = word.substr(0, i);
                            if (isUnique(prefix, kvp.second)) {
                                word_to_abbr[word] = toAbbr(prefix, word);
                                break;
                            }
                        }
                    }
                } else {
                    word_to_abbr[*kvp.second.begin()] = kvp.first;
                }
            }

            vector<string> result;
            for (const auto& word : dict) {
                result.emplace_back(word_to_abbr[word]);
            }
            return result;
        }

    private:
        bool isUnique(const string& prefix, const unordered_set<string>& words) {
            return 1 == count_if(words.begin(), words.end(),
                                 [&prefix](const string& word) {
                                     return !word.compare(0, prefix.length(), prefix);
                                 });
        }

        string toAbbr(const string& prefix, const string& word) {
            string abbr = prefix;
            abbr += to_string(word.length() - 1 - prefix.length());
            abbr += word.back();
            return abbr.length() < word.length() ? abbr : word;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.wordsAbbreviation(strs);

        // Print result to prevent optimization
        cout << "fun_qQqZG1VWwYy13HUP: Executed wordsAbbreviation() from Word Abbreviation" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_qQqZG1VWwYy13HUP: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
