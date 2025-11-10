#include "fun_fUw6EMOHghBSxGf7.hpp"

int fun_fUw6EMOHghBSxGf7() {
    // LeetCode Problem: Unique  Number Of  Occurrences

    // Solution class
    class Solution {

    public:
        bool uniqueOccurrences(vector<int>& arr) {
            map<int,int>myMap;
            for(int i=0;i<arr.size();i++){
                myMap[arr[i]]++;
            }
            int temp=0;
            vector<int>v;
            for (auto i : myMap) {
                v.push_back(i.second);
            }
            sort(v.begin(),v.end());
            for(int i=0;i<v.size();i++){
                if(v[i]==temp)
                    return false;
                else
                    temp=v[i];
            }
            return true;

        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.uniqueOccurrences(nums);

        // Print result to prevent optimization
        cout << "fun_fUw6EMOHghBSxGf7: Executed uniqueOccurrences() from Unique  Number Of  Occurrences" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_fUw6EMOHghBSxGf7: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
