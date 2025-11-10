#include "fun_paxDvQTz2JEBpElt.hpp"

int fun_paxDvQTz2JEBpElt() {
    // LeetCode Problem: Number Of Different Subsequences Gcds

    // Solution class
    class Solution {

    private:
        // Euclidean algorithm
        // https://en.wikipedia.org/wiki/Euclidean_algorithm
        int gcd(int a, int b) {
            while ( b != 0 ) {
                int t = b;
                b = a % b;
                a = t;
            }
            return a;
        }

    public:
        int countDifferentSubsequenceGCDs(vector<int>& nums) {
            int len = nums.size();
            vector<int> gcds(200001, 0);

            for(int i=0; i<len; i++) {
                int n = nums[i];
                int m = sqrt(n);
                for(int g=1; g<=m; g++){
                    if (n % g != 0) continue;
                    int x = g, y = n/g;
                    if (x != y ){
                        gcds[x] = gcd(n, gcds[x]);
                        gcds[y] = gcd(n, gcds[y]);
                    }else {
                        gcds[x] = gcd(n, gcds[x]);
                    }
                }
            }

            int cnt = 0;
            for(int i=1; i<gcds.size(); i++){
                if (gcds[i]==i) cnt++;
            }
            return cnt;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.countDifferentSubsequenceGCDs(nums);

        // Print result to prevent optimization
        cout << "fun_paxDvQTz2JEBpElt: Executed countDifferentSubsequenceGCDs() from Number Of Different Subsequences Gcds" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_paxDvQTz2JEBpElt: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
