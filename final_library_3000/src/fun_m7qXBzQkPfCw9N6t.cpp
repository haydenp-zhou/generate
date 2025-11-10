#include "fun_m7qXBzQkPfCw9N6t.hpp"

int fun_m7qXBzQkPfCw9N6t() {
    // LeetCode Problem: Odd Even Jump

    // Solution class
    class Solution {

    public:
        int oddEvenJumps(vector<int>& A) {
            vector<int> idx(A.size());
            iota(idx.begin(), idx.end(), 0);

            sort(idx.begin(), idx.end(),
                 [&](int a, int b) {
                     return A[a] != A[b] ? A[a] < A[b] : a < b;
                 });
            const auto& next_higher = findNext(idx);
            sort(idx.begin(), idx.end(),
                 [&](int a, int b) {
                     return A[a] != A[b] ? A[a] > A[b] : a < b;
                 });
            const auto& next_lower = findNext(idx);

            vector<bool> odd(A.size()), even(A.size());
            odd.back() = even.back() = true;
            for (int i = A.size() - 2; i >= 0; --i) {
                if (next_higher[i] != -1) {
                    odd[i] = even[next_higher[i]];
                }
                if (next_lower[i] != -1) {
                    even[i] = odd[next_lower[i]];
                }
            }
            return count(odd.cbegin(), odd.cend(), true);
        }

    private:
        vector<int> findNext(const vector<int>& idx) {
            vector<int> result(idx.size(), -1);
            vector<int> stack;
            for (const auto& i : idx) {
                while (!stack.empty() && stack.back() < i) {
                    result[stack.back()] = i, stack.pop_back();
                }
                stack.emplace_back(i);
            }
            return result;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.oddEvenJumps(nums);

        // Print result to prevent optimization
        cout << "fun_m7qXBzQkPfCw9N6t: Executed oddEvenJumps() from Odd Even Jump" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_m7qXBzQkPfCw9N6t: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
