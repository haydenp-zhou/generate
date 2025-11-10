#include "fun_i8Fmdue2mRkrlnbb.hpp"

int fun_i8Fmdue2mRkrlnbb() {
    // LeetCode Problem: Compare Version Numbers

    // Solution class
    class Solution {

        public:
            vector<int> &split(const string &s, char delim, vector<int> &elems) {
                stringstream ss(s);
                string item;
                while (getline(ss, item, delim)) {
                    elems.push_back(atoi(item.c_str()));
                }
                return elems;
            }


            vector<int> split(const string &s, char delim) {
                vector<int> elems;
                split(s, delim, elems);
                return elems;
            }

            void rightTrimZero(vector<int> &v){
                while (v.back() == 0){
                    v.pop_back();
                }
            }

            int compareVersion(string version1, string version2) {

                //split the version by delimer '.'
                vector<int> ver1 = split(version1, '.');
                vector<int> ver2 = split(version2, '.');

                //remove the right Zeros
                rightTrimZero(ver1);
                rightTrimZero(ver2);

                //compare two versions 
                for (int i=0; i<ver1.size() && i < ver2.size(); i++) {
                    if (ver1[i] < ver2[i]){
                        return -1;
                    }else if(ver1[i] > ver2[i]){
                        return 1;
                    }
                }

                //if the above for-loop is not returned, which means they are equal so far
                //then check the length.
                if (ver1.size() > ver2.size()) {
                    return 1;
                }else if (ver1.size() < ver2.size()) {
                    return -1;
                }

                return 0;

            }


    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    string s = "abcdefghijklmnop";

    // Execute solution
    try {
        volatile auto result = sol.split(nums);

        // Print result to prevent optimization
        cout << "fun_i8Fmdue2mRkrlnbb: Executed split() from Compare Version Numbers" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_i8Fmdue2mRkrlnbb: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
