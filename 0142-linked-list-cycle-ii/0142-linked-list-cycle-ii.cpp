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
        //1st we will check if ther eis a loop or not
        //we can do this with a slow fast approach

        ListNode* slow = head;
        ListNode* fast = head;

        //now we will do a looping and apply the algo
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
            if(fast == slow) break; //there is a loop
        }

        //to check if tere is no loop
        if(fast == NULL) return NULL;

        //now lets find the position (this is the algo)
        slow = head;
        while(slow != fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        return slow; //or even fast, both same
    }
};