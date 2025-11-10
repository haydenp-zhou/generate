#include "fun_wFOH0Qg376zFFwo6.hpp"

int fun_wFOH0Qg376zFFwo6() {
    // LeetCode Problem: Number Of Boomerangs

    // Solution class
    class Solution {

    public:
        int numberOfBoomerangs(vector<pair<int, int>>& points) {
            int result = 0;

            for (int i = 0; i < points.size(); ++i) {
                unordered_map<int, int> group;
                for (int j = 0; j < points.size(); ++j) {
                    if (j == i) {
                        continue;
                    }
                    const auto dx = points[i].first - points[j].first;
                    const auto dy = points[i].second - points[j].second;
                    ++group[dx * dx + dy * dy];
                }

                for (const auto& p : group) {
                    if (p.second > 1) {
                        result += p.second * (p.second - 1);
                    }
                }
            }

            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.numberOfBoomerangs();

        // Print result to prevent optimization
        cout << "fun_wFOH0Qg376zFFwo6: Executed numberOfBoomerangs() from Number Of Boomerangs" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_wFOH0Qg376zFFwo6: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
