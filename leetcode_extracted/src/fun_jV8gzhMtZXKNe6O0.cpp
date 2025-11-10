#include "fun_jV8gzhMtZXKNe6O0.hpp"

int fun_jV8gzhMtZXKNe6O0() {
    // LeetCode Problem: Word Search. I I

    // Solution class
    class Solution {

    public:
        void findWords(vector<vector<char>>& board, TrieNode* root, int row, int col, vector<string>& result){
            if (row < 0 || col < 0 || 
                    row >= board.size() || 
                    col >= board[row].size() ||
                    board[row][col] == '\0' ) {
                return;
            }

            char ch = board[row][col];
            root = (*root)[ch];

            if (root==NULL) return;

            if (root->isWord){
                result.push_back(root->word);
                root->isWord = false;
            }


            board[row][col] = '\0';

            findWords(board, root, row, col - 1, result);
            findWords(board, root, row, col + 1, result);
            findWords(board, root, row + 1, col, result);
            findWords(board, root, row - 1, col, result);

            board[row][col] = ch;

        }

    public:
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            TrieTree t;
            for (int i = 0; i<words.size(); i++){
                t.addWord(words[i]);
            }

            vector<string> result;
            for (int i = 0; i<board.size(); i++) {
                for (int j = 0; j < board[i].size(); j++) { 
                    findWords(board, t.getRoot(), i, j, result);
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
        volatile auto result = sol.findWords(strs);

        // Print result to prevent optimization
        cout << "fun_jV8gzhMtZXKNe6O0: Executed findWords() from Word Search. I I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_jV8gzhMtZXKNe6O0: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
