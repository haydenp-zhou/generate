#include "fun_hKWStgI8cGAm7YtW.hpp"

int fun_hKWStgI8cGAm7YtW() {
    // LeetCode Problem: Word Subsets

    // Solution class
    class Solution {

    public:
        vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
            vector<int> count(26);
            for (const auto& b : B) {
                const auto& tmp = counter(b);
                for (int i = 0; i < 26; ++i) {
                    count[i] = max(count[i], tmp[i]);
                }
            }
            vector<string> result;
            for (const auto& a : A) {
                const auto& tmp = counter(a);
                int i = 0;
                for (; i < 26; ++i) {
                    if (tmp[i] < count[i]) {
                        break;
                    }
                }
                if (i == 26) {
                    result.emplace_back(a);
                }
            }
            return result;
        }

    private:
        vector<int> counter(const string& word) {
            vector<int> count(26);
            for (const auto& c : word) {
                ++count[c - 'a'];
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
        volatile auto result = sol.wordSubsets(nums);

        // Print result to prevent optimization
        cout << "fun_hKWStgI8cGAm7YtW: Executed wordSubsets() from Word Subsets" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_hKWStgI8cGAm7YtW: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
