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
//week 10
    ListNode* mergeNodes(ListNode* head) {
        //if no head, then no
        if(head == NULL) return 0;

        //we will do this with fast and slow
        //fast will do cumulative sum between 2 0's
        //slow will update the value of the sum in the correct position 

        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* newLastNode = NULL;

        int sum = 0;
        while(fast)
        {
            if(fast->val != NULL)
            {
                sum = sum+fast->val;
            }
            else
            {
                //fast value is 0
                slow->val = sum;
                newLastNode = slow;
                slow = slow->next;
                sum=0;
            }
            fast = fast->next;
        }
        ListNode* temp = newLastNode->next;

        // Just formed new list.
        newLastNode->next = 0;

        //Deleting old List.
        while(temp){
            ListNode* nxt = temp->next;
            delete temp;
            temp = nxt;
        }
        return head;
    }
};