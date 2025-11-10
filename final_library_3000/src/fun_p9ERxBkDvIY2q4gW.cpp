#include "fun_p9ERxBkDvIY2q4gW.hpp"

int fun_p9ERxBkDvIY2q4gW() {
    // LeetCode Problem: Two Letter Card Game

    // Solution class
    class Solution {

    public:
        int score(vector<string>& cards, char x) {
            vector<int> cnt1(10), cnt2(10);
            int cnt3 = 0;
            for (const auto& s : cards) {
                if (s.find(x) == string::npos) {
                    continue;
                }
                if (s[0] == x && s[1] == x) {
                    ++cnt3;
                } else if (s[0] == x) {
                    ++cnt1[s[1] - 'a'];
                } else if (s[1] == x) {
                    ++cnt2[s[0] - 'a'];
                }
            }
            const int total1 = accumulate(cbegin(cnt1), cend(cnt1), 0);
            const int total2 = accumulate(cbegin(cnt2), cend(cnt2), 0);
            const int mx1 = ranges::max(cnt1);
            const int mx2 = ranges::max(cnt2);
            const int pair1 = min(total1 - mx1, total1 / 2);
            const int pair2 = min(total2 - mx2, total2 / 2);
            const int pair3 = min((total1 - 2 * pair1) + (total2 - 2 * pair2), cnt3);
            return (pair1 + pair2) + pair3 + min(pair1 + pair2, (cnt3 - pair3) / 2);
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    vector<string> strs = {"hello", "world", "test", "code"};

    // Execute solution
    try {
        volatile auto result = sol.score(nums);

        // Print result to prevent optimization
        cout << "fun_p9ERxBkDvIY2q4gW: Executed score() from Two Letter Card Game" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_p9ERxBkDvIY2q4gW: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
