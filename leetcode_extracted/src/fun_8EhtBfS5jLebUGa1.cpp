#include "fun_8EhtBfS5jLebUGa1.hpp"

int fun_8EhtBfS5jLebUGa1() {
    // LeetCode Problem: Palindrome Pairs

    // Solution class
    class Solution {

    public:
        bool isPalindrome(string& str) {
            int left = 0, right = str.size() - 1;
            while( left < right) {
                if (str[left++] != str[right--]) return false;
            }
            return true;
        }
        vector<vector<int>> palindromePairs(vector<string>& words) {
            unordered_map<string, int> dict;
            for(int i=0; i<words.size(); i++){
                string w = words[i];
                reverse(w.begin(), w.end());
                dict[w] = i;
            }


            vector<vector<int>> result;

            //egde case: deal with empty string 
            if ( dict.find("") != dict.end() ) {
                for(int i=0; i<words.size(); i++) {
                    if ( isPalindrome(words[i]) && dict[""] != i ) {
                        result.push_back( { dict[""], i } );
                    }
                }
            }

            for(int i=0; i<words.size(); i++) {
                for (int j=0; j<words[i].size(); j++) {
                    //split the word to 2 parts
                    string left = words[i].substr(0, j);
                    string right = words[i].substr(j, words[i].size() - j);

                    // if the `left` is found, which means there is a words has reversed sequence with it.
                    // then we can check the `right` part is Palindrome or not. 
                    if ( dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i ) {
                        result.push_back( { i, dict[left] } );
                    }

                    if (dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i ) {
                        result.push_back( { dict[right], i } );
                    }
                }

            }

            return result;
        }


    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.isPalindrome(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_8EhtBfS5jLebUGa1: Executed isPalindrome() from Palindrome Pairs" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_8EhtBfS5jLebUGa1: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
