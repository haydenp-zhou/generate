#include "fun_w8E4aFeKpkpWjBp0.hpp"

int fun_w8E4aFeKpkpWjBp0() {
    // LeetCode Problem: Check If Word Can Be Placed In Crossword

    // Solution class
    class Solution {

    public:
        bool placeWordInCrossword(vector<vector<char>>& board, string word) {
            for (int d = 0; d < 2; ++d) {
                reverse(begin(word), end(word));
                for (int transposed = 0; transposed < 2; ++transposed) {
                    for (int i = 0; i < get_r(board, transposed); ++i) {
                        auto it = begin(word);
                        bool matched = true;
                        for (int j = 0; j < get_c(board, transposed); ++j) {
                            const char c = get_val(board, i, j, transposed);
                            if (c == '#') {
                                if (it == end(word) && matched) {
                                    return true;
                                }
                                it = begin(word);
                                matched = true;
                                continue;
                            }
                            if (!matched) {
                                continue;
                            }
                            matched = it != end(word) && (c == (*it++) || c == ' ');
                        }
                        if (it == end(word) && matched) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }

    private:
        int get_r(const vector<vector<char>>& mat, bool transposed) {
            return !transposed ? size(mat) : size(mat[0]);
        }

        int get_c(const vector<vector<char>>& mat, bool transposed) {
            return !transposed ? size(mat[0]) : size(mat);
        }

        int get_val(const vector<vector<char>>& mat, int i, int j, bool transposed) {
            return !transposed ? mat[i][j] : mat[j][i];
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.placeWordInCrossword(s);

        // Print result to prevent optimization
        cout << "fun_w8E4aFeKpkpWjBp0: Executed placeWordInCrossword() from Check If Word Can Be Placed In Crossword" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_w8E4aFeKpkpWjBp0: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
