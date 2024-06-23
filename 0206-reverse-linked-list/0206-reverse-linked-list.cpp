/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        //case where we need to stop
        while (curr != NULL) 
        {
            //we  will mark a node that is always ahead of current, as when we assign current->next = prev we will lose the rest of the LL
            ListNode* nextTemp = curr->next;

            //point it in the reverse direction
            curr->next = prev;
            
            //move ur prev and current pointers 1 step ahead
            prev = curr;
            curr = nextTemp;
        }
        return prev; //which is now our starting point of the LL and the LL will go in the reverse order
    }
};