#include "fun_mbyXySpcRw6ZfcM7.hpp"

int fun_mbyXySpcRw6ZfcM7() {
    // LeetCode Problem: Maximum Units On A Truck

    // Solution class
    class Solution {

    private:
        void print(vector<vector<int>>& boxes) {
            cout << "{ ";
            for(int i=0; i<boxes.size()-1; i++){
                cout << "[" << boxes[i][0] << ","<< boxes[i][1] << "], ";
            }
            int i=boxes.size()-1;
            cout << "[" << boxes[i][0] << ", "<< boxes[i][1] << "] } "<< endl;
        }
    public:
        int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
            sort(boxTypes.begin(), boxTypes.end(), 
                 [&](vector<int>& lhs, vector<int>& rhs){return lhs[1] > rhs[1]; });
            //print(boxTypes);
            int units = 0;
            for(auto& box : boxTypes) {
                if (truckSize >= box[0]) {
                    units += box[0] * box[1];
                }else{
                    units += truckSize * box[1];
                }
                truckSize -= box[0];
                if (truckSize <= 0 ) break;
            }
            return units;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

    // Execute solution
    try {
        volatile auto result = sol.maximumUnits(nums, matrix);

        // Print result to prevent optimization
        cout << "fun_mbyXySpcRw6ZfcM7: Executed maximumUnits() from Maximum Units On A Truck" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_mbyXySpcRw6ZfcM7: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
