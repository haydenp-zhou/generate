#include "fun_Xu3Q4hkvwICiti6x.hpp"

int fun_Xu3Q4hkvwICiti6x() {
    // LeetCode Problem: Single Threaded Cpu

    // Solution class
    class Solution {

    private:
        template<typename T>
        void print(T q) { 
            while(!q.empty()) {
                auto t = q.top();
                cout << t[2]<< "[" << t[0] <<","<< t[1] << "] ";
                q.pop();
            }
            std::cout << '\n';
        }
    public:
        vector<int> getOrder(vector<vector<int>>& tasks) {
            // push the index into each task.
            // [enQueueTime, ProcessingTime, index]
            for(int i=0; i<tasks.size(); i++){
                tasks[i].push_back(i); 
            }

            //Sort the tasks by enQueueTtime
            sort(tasks.begin(), tasks.end(), [&](vector<int>& lhs, vector<int>& rhs) {
                return lhs[0] < rhs[0];
            });

            //Sort function for tasks priority queue.
            auto comp = [&](vector<int>& lhs, vector<int>& rhs){
                // if the processing time is same ,get the smaller index
                if (lhs[1] == rhs[1]) return lhs[2] > rhs[2]; 
                // choosing the shorter processing time.
                return lhs[1] > rhs[1];

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.getOrder(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_Xu3Q4hkvwICiti6x: Executed getOrder() from Single Threaded Cpu" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Xu3Q4hkvwICiti6x: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
