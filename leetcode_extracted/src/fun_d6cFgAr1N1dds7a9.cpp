#include "fun_d6cFgAr1N1dds7a9.hpp"

int fun_d6cFgAr1N1dds7a9() {
    // LeetCode Problem: Add Two Numbers

    // Solution class
    class Solution {


    public:
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            int x=0, y=0, carry=0, sum=0;
            ListNode *h=NULL, **t=&h;

            while (l1!=NULL || l2!=NULL){
                x = getValueAndMoveNext(l1);
                y = getValueAndMoveNext(l2);

                sum = carry + x + y;

                ListNode *node = new ListNode(sum%10);
                *t = node;
                t = (&node->next);

                carry = sum/10;
            }

            if (carry > 0) {
                ListNode *node = new ListNode(carry%10);
                *t = node;
            }

            return h;
        }
    private:
        int getValueAndMoveNext(ListNode* &l){
            int x = 0;
            if (l != NULL){
                x = l->val;
                l = l->next;
            }
            return x;
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.addTwoNumbers(testValue);

        // Print result to prevent optimization
        cout << "fun_d6cFgAr1N1dds7a9: Executed addTwoNumbers() from Add Two Numbers" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_d6cFgAr1N1dds7a9: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
