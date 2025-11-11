#include "fun_Qhjlrmy6KmFLnocC.hpp"

// Original algorithm: Longest Increasing Subsequence Nlogn
int fun_Qhjlrmy6KmFLnocC() {
    try {
        using namespace std;
        int LIS(const std::vector<int>& arr, int n) {
            set<int> active;  // The current built LIS.
            active.insert(arr[0]);
            for (int i = 1; i < n; ++i) {
                auto get = active.lower_bound(arr[i]);
                if (get == active.end()) {
                    active.insert(arr[i]);
                }  // current element is the greatest so LIS increases by 1.
                else {
                    int val = *get;  // we find the position where arr[i] will be in the
                    if (val > arr[i]) {
                        active.erase(get);
                        active.insert(arr[i]);
                    }
                }
            }
            return active.size();  // size of the LIS.
        }
            cout << LIS(a, n) << endl;
            return 0;
        }

                // Test the algorithm implementation
                cout << "Testing Longest Increasing Subsequence Nlogn..." << endl;
                cout << "Algorithm functions available" << endl;

        volatile int status = 1;
        cout << "fun_Qhjlrmy6KmFLnocC: Longest Increasing Subsequence Nlogn executed" << endl;
        return const_cast<const int&>(status);
    } catch (const exception& e) {
        cout << "fun_Qhjlrmy6KmFLnocC: Exception - " << e.what() << endl;
        return 0;
    }
}
