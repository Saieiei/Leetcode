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
    ListNode* deleteDuplicates(ListNode* head) {
        //we will use 2 pointers (curr and prev)
        //if both are the same then we will eliminate 1, we will eliminate current

        //base conditions
        if(head == NULL) return head; //empty list
        if(head->next == NULL) return head; //both of them diff

        ListNode* prev = head;
        ListNode* curr = prev->next;

        while(curr != NULL) //should not go out
        {
            //check if they r the same
            if(curr->val != prev->val)
            {
                curr = curr->next;
                prev = prev->next;
            }
            else //they r the same, we should isolate, delete and revibe curr
            {
                prev->next = curr->next;
                curr->next = NULL;
                delete curr;
                curr = prev->next;
            }
        }
        return head;
    }
};