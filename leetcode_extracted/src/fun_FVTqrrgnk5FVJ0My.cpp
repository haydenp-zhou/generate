#include "fun_FVTqrrgnk5FVJ0My.hpp"

int fun_FVTqrrgnk5FVJ0My() {
    // LeetCode Problem: Sorting The Sentence

    // Solution class
    class Solution {

    public:
        string sortSentence(string s) {
            vector<string> words = split(s, ' ');
            for (int i = 0; i < size(words); ++i) {
                while (words[i].back() - '1' != i) {
                    swap(words[i], words[words[i].back() - '1']);
                }
            }
            string result;
            for (const auto& word : words) {
                result += word;
                result.back() = ' ';
            }
            result.pop_back();
            return result;
        }

    private:
        vector<string> split(const string& s, const char delim) {
            vector<string> result;
            auto end = string::npos;
            do {
                const auto& start = end + 1;
                end = s.find(delim, start);
                result.emplace_back(s.substr(start, end - start));
            } while (end != string::npos); 
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.sortSentence(strs);

        // Print result to prevent optimization
        cout << "fun_FVTqrrgnk5FVJ0My: Executed sortSentence() from Sorting The Sentence" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_FVTqrrgnk5FVJ0My: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
