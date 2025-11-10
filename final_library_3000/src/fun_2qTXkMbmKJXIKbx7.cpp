#include "fun_2qTXkMbmKJXIKbx7.hpp"

int fun_2qTXkMbmKJXIKbx7() {
    // LeetCode Problem: Most Common Word

    // Solution class
    class Solution {

    private:
        bool isLetter(char c) {
            return c >= 'a' && c <= 'z';
        }
    public:
        string mostCommonWord(string paragraph, vector<string>& banned) {
            unordered_map<string, int> banned_map, words_map;
            for (auto w:banned) {
                banned_map[w]++;
            }

            //conert the string to lower case.
            transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);

            //transfer the symbols to space.
            for (int i=0; i<paragraph.size(); i++) {
                if ( !isLetter(paragraph[i]) ){
                    paragraph[i] = ' ';
                }
            }
            string word;
            for(auto c:paragraph) {
                if (isLetter(c)) { 
                    word += c;
                }else{
                    if ( word.size()>0 ) {
                        words_map[word]++;
                    }
                    word="";
                }
            }
            if ( word.size()>0 ) words_map[word]++;

            string result;
            int max_cnt=0;
            // go through the words_map
            for (auto const& w : words_map) {

                if ( banned_map.find(w.first) != banned_map.end() ) {
                    continue;
                }
                if (max_cnt < w.second) {
                    result = w.first;
                    max_cnt = w.second;
                }
            }

            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.mostCommonWord(strs);

        // Print result to prevent optimization
        cout << "fun_2qTXkMbmKJXIKbx7: Executed mostCommonWord() from Most Common Word" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_2qTXkMbmKJXIKbx7: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
