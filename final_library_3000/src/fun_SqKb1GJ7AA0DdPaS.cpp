#include "fun_SqKb1GJ7AA0DdPaS.hpp"

int fun_SqKb1GJ7AA0DdPaS() {
    // LeetCode Problem: Split Linked List In Parts

    // Solution class
    class Solution {

    public:
        vector<ListNode*> splitListToParts(ListNode* root, int k) {
            auto n = 0;
            auto curr = root;
            while (curr) {
                curr = curr->next;
                n += 1;
            }
            auto width = n / k;
            auto remainder = n % k;

            vector<ListNode *> result;
            curr = root;
            for (int i = 0; i < k; ++i) {
                auto head = curr;
                for (int j = 0; curr &&
                     j < width - 1 + static_cast<int>(i < remainder); ++j) {
                    curr = curr->next;
                }
                if (curr) {
                    auto tail = curr;
                    curr = curr->next;
                    tail->next = nullptr;
                }
                result.emplace_back(head);
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
        volatile auto result = sol.splitListToParts();

        // Print result to prevent optimization
        cout << "fun_SqKb1GJ7AA0DdPaS: Executed splitListToParts() from Split Linked List In Parts" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_SqKb1GJ7AA0DdPaS: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
