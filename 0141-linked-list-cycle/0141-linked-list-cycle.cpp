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
    bool hasCycle(ListNode *head) {
        
        //tortoise/rabit
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL && slow != NULL)
            {
                fast = fast->next;
                slow = slow->next;

                //condition
                if(slow == fast) return 1;
            }
        }
        return false;
    }
};