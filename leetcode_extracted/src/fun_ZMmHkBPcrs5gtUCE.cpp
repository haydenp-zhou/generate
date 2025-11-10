#include "fun_ZMmHkBPcrs5gtUCE.hpp"

int fun_ZMmHkBPcrs5gtUCE() {
    // LeetCode Problem: Group Anagrams

    // Solution class
    class Solution {

    public:
        vector< vector<string> > groupAnagrams(vector<string> &strs) {
            vector< vector<string> > result;
            map<string, int> m;
            for(int i=0; i<strs.size(); i++){
                string word = strs[i];
                sort(word.begin(), word.end());
                if (m.find(word)==m.end()){
                    vector<string> v;
                    v.push_back(strs[i]);
                    result.push_back(v);
                    m[word] = result.size()-1;

                }else{
                    result[m[word]].push_back(strs[i]);
                }
            }

            for(int i=0; i<result.size(); i++){
                sort(result[i].begin(), result[i].end());
            }
            return result;
        }

        //using multiset 
        vector< vector<string> > groupAnagrams01(vector<string> &strs) {
            vector< vector<string> > result;
            map<string, multiset<string>> m;
            for(int i=0; i<strs.size(); i++){
                string word = strs[i];
                sort(word.begin(), word.end());
                m[word].insert(strs[i]);
            }

            for(auto item : m){
                vector<string> v(item.second.begin(), item.second.end());
                result.push_back(v);
            }
            return result;
        }


        //NOTICE: the below solution has been depracated as the problem has been updated!
        vector<string> anagrams(vector<string> &strs) {
            vector<string> result;
            map<string, int> m;
            for(int i=0; i<strs.size(); i++){
                string word = strs[i];
                //sort it can easy to check they are anagrams or not
                sort(word.begin(), word.end());  
                if (m.find(word)==m.end()){
                    m[word] = i;
                }else{
                    if (m[word]>=0){
                        result.push_back(strs[m[word]]);
                        m[word]=-1;
                    }
                    result.push_back(strs[i]);
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
        volatile auto result = sol.groupAnagrams(strs);

        // Print result to prevent optimization
        cout << "fun_ZMmHkBPcrs5gtUCE: Executed groupAnagrams() from Group Anagrams" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_ZMmHkBPcrs5gtUCE: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
