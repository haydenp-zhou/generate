#include "fun_n52P56kwNtac3cE9.hpp"

int fun_n52P56kwNtac3cE9() {
    // LeetCode Problem: Linked  List  Cycle  I I

    // Solution class
    class Solution {

    	public:
    		ListNode* detectCycle(ListNode *head)
    		{
    			//If head is null or head->next is null dont do anything just return.
    			if (!head) return NULL;
    			if (head->next == NULL) return NULL;
    			//Take two pointers slow and fast both initially pointing to head .  
    			ListNode *fast = head;
    			ListNode *slow = head;
    			while (fast and fast->next)
    			{
    				// Move fast pointer two step and slow pointer one step forward.
    				fast = fast->next->next;
    				slow = slow->next;
    				//At some time if fast and slow are equal it means there is a cycle .
    				if (fast == slow) break;
    			}

    			if (fast == NULL or fast->next == NULL) return NULL;
    			//Now we point one pointer to head and increment both  the pointers one step untill slow and fast pointer do not become equal.
    			slow = head;
    			while (slow != fast)
    			{
    				slow = slow->next;
    				fast = fast->next;
    			}

    			return slow;
    		}

    };

    // Create test instance
    Solution sol;

    // Generate test data
    int testValue = 42;

    // Execute solution
    try {
        volatile auto result = sol.detectCycle(testValue);

        // Print result to prevent optimization
        cout << "fun_n52P56kwNtac3cE9: Executed detectCycle() from Linked  List  Cycle  I I" << endl;

        volatile int status = 1;
        return const_cast<const int&>(status);

    } catch (const exception& e) {
        cout << "fun_n52P56kwNtac3cE9: Exception during execution: " << e.what() << endl;
        return 0;
    }
}
