#include "fun_XTLGlerDD7at6dDu.hpp"

int fun_XTLGlerDD7at6dDu() {
    // LeetCode Problem: Compare Strings By Frequency Of The Smallest Character

    // Solution class
    class Solution {

    public:
        vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
            cout << queries.size() << " : " << words.size() << endl;
            vector<int> freq;
            for (auto w : words) {
                freq.push_back(f(w));
            }
            sort(freq.begin(), freq.end());

            vector<int> result;
            for (auto q : queries) {
                result.push_back(binary_search(freq, f(q)));
            }
            return result;
        }

        int f(string& s) {
            char ch = 'z' + 1; //stroe the smallest char
            int cnt = 0;  //stroe the frequency of the smallest char
            for (auto c : s) {
                if (c < ch) { //find the smaller char, reset the count
                    cnt  = 1;
                    ch = c;
                } if (c == ch) {
                    cnt++;
                }
            }
            return cnt;
        }

        int binary_search(vector<int> &v, int target) {
            int low=0, high=v.size()-1, mid;

            while (low < high) {
                mid = low + (high - low) / 2;
                if ( v[mid] > target) {
                    high = mid -1;
                } else if (v[mid] <= target) {
                    low = mid + 1;
                }
            }

            low = v[low] > target  ? low : low + 1;

            return v.size() - low;
        }


    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<string> strs = {"hello", "world", "test", "code"};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.numSmallerByFrequency(nums);

        // Print result to prevent optimization
        cout << "fun_XTLGlerDD7at6dDu: Executed numSmallerByFrequency() from Compare Strings By Frequency Of The Smallest Character" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_XTLGlerDD7at6dDu: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
