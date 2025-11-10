#include "fun_We7P6KFlDnEeoPZo.hpp"

int fun_We7P6KFlDnEeoPZo() {
    // LeetCode Problem: Zuma Game

    // Solution class
    class Solution {

    public:
        int findMinStep(string board, string hand) {
            unordered_map<string, unordered_map<string, int>> lookup;
            int result = findMinStepHelper(board, hand, &lookup);
            return result > hand.size() ? -1 : result;
        }

    private:
        int findMinStepHelper(const string& board, const string& hand,
                              unordered_map<string, unordered_map<string, int>> *lookup) {
            if (board.empty()) {
                return 0;
            }
            if (hand.empty()) {
                return MAX_STEP;
            }
            if ((*lookup)[board][hand]) {
                return (*lookup)[board][hand];
            }

            int result = MAX_STEP;
            for (int i = 0; i < hand.size(); ++i) {
                for (int j = 0; j <= board.size(); ++j) {
                    const auto& next_board = shrink(board.substr(0, j) + hand.substr(i, 1) + board.substr(j));
                    const auto& next_hand = hand.substr(0, i) + hand.substr(i + 1);
                    result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 1);
                }
            }
            return (*lookup)[board][hand] = result;
        }

        string shrink(string s) {  // Time: O(n^2), Space: O(1)
            bool changed = true;
            while (changed) {
                changed = false;
                for (int start = 0, i = 0; start < size(s); ++start) {
                    while(i < size(s) && s[start] == s[i]) {
                        ++i;
                    }
                    if (i - start >= 3) {
                        s = s.substr(0, start) + s.substr(i); 
                        changed = true;
                        break;
                    } 
                }
            }
            return s;
        }

        static const int MAX_STEP = 6;

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.findMinStep(s);

        // Print result to prevent optimization
        cout << "fun_We7P6KFlDnEeoPZo: Executed findMinStep() from Zuma Game" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_We7P6KFlDnEeoPZo: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
