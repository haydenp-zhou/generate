#include "fun_Ys3MXfYbA4ENeNjd.hpp"

int fun_Ys3MXfYbA4ENeNjd() {
    // LeetCode Problem: Print Immutable Linked List In Reverse

    // Solution class
    class Solution {

    public:
        void printLinkedListInReverse(ImmutableListNode* head) {
            int count = 0;
            auto curr = head;
            while (curr) {
                curr = curr->getNext();
                ++count;
            }
            int bucket_count = ceil(sqrt(count));

            vector<ImmutableListNode *> buckets;
            count = 0;
            curr = head;
            while (curr) {
                if (count % bucket_count == 0) {
                    buckets.emplace_back(curr);
                }
                curr = curr->getNext();
                ++count;
            }

            for (int i = buckets.size() - 1; i >= 0; --i) {
                printNodes(buckets[i], bucket_count);
            }
        }

    private:
        void printNodes(ImmutableListNode *head, int count) {
            vector<ImmutableListNode *> nodes;
            while (head && nodes.size() != count) {
                nodes.emplace_back(head);
                head = head->getNext();
            }
            for (int i = nodes.size() - 1; i >= 0; --i) {
                nodes[i]->printValue();
            }
        }

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.printLinkedListInReverse(testValue);

        // Print result to prevent optimization
        cout << "fun_Ys3MXfYbA4ENeNjd: Executed printLinkedListInReverse() from Print Immutable Linked List In Reverse" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_Ys3MXfYbA4ENeNjd: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
