#include "fun_Jb5oQZn6qeVkQhiL.hpp"

int fun_Jb5oQZn6qeVkQhiL() {
    // LeetCode Problem: Nested List Weight Sum Ii

    // Solution class
    class Solution {

    public:
        int depthSumInverse(vector<NestedInteger>& nestedList) {
            vector<int> result;
            for (const auto& list : nestedList) {
                depthSumInverseHelper(list, 0, &result);
            }

            int sum = 0;
            for (int i = result.size() - 1; i >= 0; --i) {
                sum += result[i] * (result.size() - i);
            }
            return sum;
        }

    private:
        void depthSumInverseHelper(const NestedInteger &list, int depth, vector<int> *result) {
            if (result->size() < depth + 1) {
                result->emplace_back(0);
            }
            if (list.isInteger()) {
                (*result)[depth] += list.getInteger();
            } else {
                for (const auto& l : list.getList()) {
                    depthSumInverseHelper(l, depth + 1, result);
                }
            }
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};

    // Execute solution
    try {
        volatile auto result = sol.depthSumInverse(nums);

        // Print result to prevent optimization
        cout << "fun_Jb5oQZn6qeVkQhiL: Executed depthSumInverse() from Nested List Weight Sum Ii" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Jb5oQZn6qeVkQhiL: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
