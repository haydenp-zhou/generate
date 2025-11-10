#include "fun_uc7OGthg9VhF6vUo.hpp"

int fun_uc7OGthg9VhF6vUo() {
    // LeetCode Problem: Next Greater Element Iii

    // Solution class
    class Solution {

    public:
        int nextGreaterElement(int n) {
            auto digits = to_string(n);
            nextPermutation(begin(digits), end(digits));  // self-implemented next_permutattion()
            auto result = stoll(digits);
            return (result > numeric_limits<int>::max() || result <= n) ? -1 : result;
        }

    private:
        template<typename BidiIt>
        bool nextPermutation(BidiIt begin, BidiIt end) {
            const auto rbegin = reverse_iterator<BidiIt>(end);
            const auto rend = reverse_iterator<BidiIt>(begin);

            // Find the first element (pivot) which is less than its successor.
            auto pivot = next(rbegin);
            while (pivot != rend && *pivot >= *prev(pivot)) {
                ++pivot;
            }

            bool is_greater = true;
            if (pivot != rend) {
                // Find the number which is greater than pivot, and swap it with pivot
                auto change = find_if(rbegin, pivot, bind1st(less<int>(), *pivot));
                swap(*change, *pivot);
            } else {
                is_greater = false;
            }

            // Make the sequence after pivot non-descending
            reverse(rbegin, pivot);

            return is_greater;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.nextGreaterElement(n);

        // Print result to prevent optimization
        cout << "fun_uc7OGthg9VhF6vUo: Executed nextGreaterElement() from Next Greater Element Iii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_uc7OGthg9VhF6vUo: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
