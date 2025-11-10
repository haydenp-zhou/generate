#include "fun_penOSpNLeGjlJuAe.hpp"

int fun_penOSpNLeGjlJuAe() {
    // LeetCode Problem: Shortest Completing Word

    // Solution class
    class Solution {

    public:
        string shortestCompletingWord(string licensePlate, vector<string>& words) {
            string result;
            const auto& counter = counts(licensePlate);
            for (const auto& word : words) {
                if ((result.empty() || word.length() < result.length()) &&
                   contains(counter, word)) {
                    result = word;
                }
            }
            return result;
        }

    private:
        bool contains(const vector<int>& counter1, const string& w2) const {
            const auto& counter2 = counts(w2);
            for (int i = 0; i < counter2.size(); ++i) {
                if (counter1[i] > counter2[i]) {
                    return false;
                }
            }
            return true;
        }

        vector<int> counts(const string& s) const {
            vector<int> count(26);
            for (const auto& c : s) {
                if (isalpha(c)) {
                    ++count[tolower(c) - 'a'];
                }
            }
            return count;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.shortestCompletingWord(nums);

        // Print result to prevent optimization
        cout << "fun_penOSpNLeGjlJuAe: Executed shortestCompletingWord() from Shortest Completing Word" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_penOSpNLeGjlJuAe: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
