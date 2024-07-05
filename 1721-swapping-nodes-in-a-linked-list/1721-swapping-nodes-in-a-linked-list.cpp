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
    ListNode* swapNodes(ListNode* head, int k) {
        //we will have 2 separate pointers
        //1st pointer is temp1
        ListNode* temp1 = head;
        for(int i=1; i<k; i++)
        {
            temp1 = temp1->next;
        }
        int temp11 = temp1->val;

        //now we will go till the end
        ListNode* temp2 = head;
        int count = 0;
        while(temp2->next)
        {
            count++;
            temp2 = temp2->next;
        }

        //now since we have reached till the end
        //we shall go k elements back 
        temp2 = head;
        for(int i=1; i<=count-(k-1); i++)
        {
            temp2 = temp2->next;
        }
        int temp22 = temp2->val;

        //swap now
        temp1->val = temp22;
        temp2->val = temp11;
        return head;
    }
};