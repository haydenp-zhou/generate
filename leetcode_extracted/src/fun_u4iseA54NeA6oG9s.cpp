#include "fun_u4iseA54NeA6oG9s.hpp"

int fun_u4iseA54NeA6oG9s() {
    // LeetCode Problem: Process Tasks Using Servers

    // Solution class
    class Solution {

    private:
        template<class T>
        void print(T  q) {
            cout << "[";
            while(!q.empty()) {
                auto& p = q.top(); 
                cout << "[" << p.first << ","<< p.second << "]";
                q.pop();
            }
            cout << "]" << endl;
        }
    public:

        vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
            typedef pair<int,int> IntPair;
            typedef priority_queue<IntPair, vector<IntPair>, greater<IntPair>> PriorityQueue;

            // asc sorted by {weight, index}
            PriorityQueue idle;
            // asc sorted by {time, index}
            PriorityQueue busy;

            for(int i=0; i<servers.size(); i++){
                idle.push({servers[i], i});
            }

            //print(idle);

            int time = 0;
            vector<int> ans;
            for(int i=0; i<tasks.size(); i++) {
                time = max(i, time);

                //check the tasks finished
                while(true) { 
                    while(!busy.empty()){
                        auto& t = busy.top().first;
                        auto& id = busy.top().second;
                        if (t > time) break;
                        idle.push({servers[id], id});
                        busy.pop();
                    }
                    if (!idle.empty())  break;
                    //set the time to the fisrt finish running task 
                    time = busy.top().first;
                }

                //process the current task
                auto& id = idle.top().second;
                ans.push_back(id);
                busy.push({time + tasks[i], id});
                idle.pop();
            }

            return ans;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.assignTasks(nums);

        // Print result to prevent optimization
        cout << "fun_u4iseA54NeA6oG9s: Executed assignTasks() from Process Tasks Using Servers" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_u4iseA54NeA6oG9s: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
