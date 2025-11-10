#include "fun_f1SRhTcA2MlYpi10.hpp"

int fun_f1SRhTcA2MlYpi10() {
    // LeetCode Problem: Largest Color Value In A Directed Graph

    // Solution class
    class Solution {

    private:
        void print(vector<int>& v) {
            cout << "[";
            int i = 0;
            for(; i<v.size()-1; i++) {
                cout << v[i] << ",";
            }
            cout << v[i] << "]" << endl;
        }
    private:
        int nodes_cnt;
        vector<Node> nodes;
    public:
        int largestPathValue(string colors, vector<vector<int>>& edges) {

            nodes_cnt = colors.size() ;
            for(int i=0; i<nodes_cnt; i++) {
                Node n( colors[i]-'a');
                nodes.push_back(n);
            }
            for(auto& e : edges) {
                nodes[e[0]].AddChildNode(e[1]);
                nodes[e[1]].AddIncomming();
            }

             vector<bool> visited(nodes_cnt, false);

            // We can do toplogical sort
            // 
            //vector<int> topSort;
            //for(int id=0; id <nodes_cnt; id++){
            //    auto& n = nodes[id];
            //    topologicalSort(id, topSort, visited);
            //}
            //print(topSort);

            int m = -1;
            for (int i=0; i<nodes_cnt; i++) {
                //int id = topSort[i];
                int id = i;
                auto& n = nodes[id];

                //using to check cycle.
                std::fill(visited.begin(), visited.end(), false);

                bool succ = travel(id, visited);
                if (!succ) return -1;

                m = max(m, nodes[id].MaxColorValue());
            }
            return m;
        }

        void topologicalSort(int i, vector<int>& topSort, vector<bool>& visited) {
            if (visited[i]) return;
            visited[i] = true;
            for(auto& id : nodes[i].Children()) {
                if (!visited[id]) {
                    topologicalSort(id, topSort, visited);
                }
            }
            topSort.push_back(i);
        }

        //return true if it is successful
        //return false if there is an error  - has cycle
        bool travel(int i, vector<bool>& visited ) {
            //this node has been processed already
            if (nodes[i].isProcessed()) return true;

            //cycled 
            if (visited[i]) return false;
            visited[i] = true;

            // leaf node
            if (nodes[i].ChildrenCount() <= 0 ) {
                nodes[i].AddMyColor();
                nodes[i].Processed();
                return true;
            }

            for(auto& n : nodes[i].Children() ) {
                bool succ = travel(n, visited);
                if (!succ) return false;
                nodes[i].MergeChildColors( nodes[n] );
            }

            nodes[i].AddMyColor();
            nodes[i].Processed();

            //cout << "["<< i << "]: " ;
            //for(int k=0; k<26; k++) {
            //    cout << nodes[i].colors[k] << " ";
            //}
            //cout << endl;

            return true;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    string s = "abcdefghijklmnop";
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.largestPathValue(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_f1SRhTcA2MlYpi10: Executed largestPathValue() from Largest Color Value In A Directed Graph" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_f1SRhTcA2MlYpi10: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
