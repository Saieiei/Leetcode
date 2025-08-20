/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //basically we have to use fast-slow method
        //wait for them to join
        //then we have to put 1 of them back at the head and ask it to move by 1 by until they meet
        //that meeting point is the node where the cycle begins

        ListNode* fast = head;
        ListNode* slow = head;

        //slow-fast method (to check for loop)
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) break;
        }

        //no loop?
        if(fast == NULL || fast->next == NULL) return NULL;

        //then we have to put 1 of them back at the head and ask it to move by 1 by until they meet
        fast = head; //or slow
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow ->next;
        }
        return fast; //or slow
    }
};