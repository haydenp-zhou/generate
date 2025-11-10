#include "fun_9oxVOTbZHXuMWwn0.hpp"

int fun_9oxVOTbZHXuMWwn0() {
    // LeetCode Problem: Word Ladder

    // Solution class
    class Solution {

    public:
        int ladderLength(string start, string end, unordered_set<string> &dict) {

            // Using a map for two purposes: 
            //   1) store the distince so far.
            //   2) remove the duplication 
            map<string, int> dis;
            dis[start] = 1;

            queue<string> q;
            q.push(start);

            while(!q.empty()){

                string word = q.front(); 
                q.pop();

                if (word == end) {
                    break;
                }

                for (int i=0; i<word.size(); i++){
                    string temp = word;
                    for(char c='a'; c<='z'; c++){
                        temp[i] = c;
                        if (dict.count(temp)>0 && dis.count(temp)==0){
                            dis[temp] = dis[word] + 1;
                            q.push(temp);
                        }
                    }
                }
            }
            return (dis.count(end)==0) ? 0 : dis[end];

        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.ladderLength(s);

        // Print result to prevent optimization
        cout << "fun_9oxVOTbZHXuMWwn0: Executed ladderLength() from Word Ladder" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_9oxVOTbZHXuMWwn0: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
