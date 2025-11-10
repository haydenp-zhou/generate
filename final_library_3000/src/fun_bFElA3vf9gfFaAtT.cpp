#include "fun_bFElA3vf9gfFaAtT.hpp"

int fun_bFElA3vf9gfFaAtT() {
    // LeetCode Problem: Finding 3 Digit Even Numbers

    // Solution class
    class Solution {

    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            vector<int> cnt(10);
            for (const auto& d : digits) {
                ++cnt[d];
            }
            vector<int> result, curr;
            backtracking(&curr, &cnt, &result);
            return result;
        }

    private:
        void backtracking(vector<int> *curr, vector<int> *cnt, vector<int> *result) {
            static const int k = 3;
            if (size(*curr) == k) {
                result->emplace_back(accumulate(cbegin(*curr), cend(*curr), 0,
                                                [](const auto& total, const auto& x) {
                                                    return total * 10 + x;
                                                }));
                return;
            }
            for (int i = 0; i < size(*cnt); ++i) {
                if ((*cnt)[i] == 0 ||
                    (empty(*curr) && (i == 0)) ||
                    (size(*curr) == k - 1 && i % 2 != 0)) {
                    continue;
                }
                --(*cnt)[i];
                curr->emplace_back(i);
                backtracking(curr, cnt, result);
                curr->pop_back();
                ++(*cnt)[i];
            }
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.findEvenNumbers(nums);

        // Print result to prevent optimization
        cout << "fun_bFElA3vf9gfFaAtT: Executed findEvenNumbers() from Finding 3 Digit Even Numbers" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_bFElA3vf9gfFaAtT: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
