#include "fun_qM42tWExh14DEWdA.hpp"

int fun_qM42tWExh14DEWdA() {
    // LeetCode Problem: Maximum Twin Sum Of A Linked List

    // Solution class
    class Solution {

    public:
        int pairSum(ListNode* head) {
            ListNode dummy(0, head);
            auto slow = dummy.next, fast = dummy.next;
            while (fast->next && fast->next->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            int result = 0;
            auto head2 = reverseList(slow);
            while (head) {
                result = max(result, head->val + head2->val);
                head = head->next;
                head2 = head2->next;
            }
            return result;
        }

    private:
        ListNode* reverseList(ListNode* head) {
            ListNode dummy;
            while (head) {
                auto tmp = head->next;
                head->next = dummy.next;
                dummy.next = head;
                head = tmp;
            }
            return dummy.next;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.pairSum(testValue);

        // Print result to prevent optimization
        cout << "fun_qM42tWExh14DEWdA: Executed pairSum() from Maximum Twin Sum Of A Linked List" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_qM42tWExh14DEWdA: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
