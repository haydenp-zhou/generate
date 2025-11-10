#include "fun_39koIaBicG4MmoD5.hpp"

int fun_39koIaBicG4MmoD5() {
    // LeetCode Problem: Validate Binary Tree Nodes

    // Solution class
    class Solution {

    public:
        bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
            unordered_set<int> roots;
            for (int i = 0; i < n; ++i) {
                roots.emplace(i);
            }
            for (const auto& i : leftChild) {
                roots.erase(i);
            }
            for (const auto& i : rightChild) {
                roots.erase(i);
            }
            if (size(roots) != 1) {
                return false;
            }
            const auto& root = *cbegin(roots);
            vector<int> stk({root});
            unordered_set<int> lookup({root});
            while (!empty(stk)) {
                const auto node = stk.back(); stk.pop_back();
                for (const auto& i : {leftChild[node], rightChild[node]}) {
                    if (i < 0) {
                        continue;
                    }
                    if (lookup.count(i)) {
                        return false;
                    }
                    lookup.emplace(i);
                    stk.emplace_back(i);
                }
            }
            return size(lookup) == n;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    vector<int> nums = {7, 1, 5, 3, 6, 4, 2, 8, 9, 10};
    int n = 15;

    // Execute solution
    try {
        volatile auto result = sol.validateBinaryTreeNodes(nums);

        // Print result to prevent optimization
        cout << "fun_39koIaBicG4MmoD5: Executed validateBinaryTreeNodes() from Validate Binary Tree Nodes" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_39koIaBicG4MmoD5: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
