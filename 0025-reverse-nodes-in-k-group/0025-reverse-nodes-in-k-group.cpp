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
//week 9, MSFT

    //finding the length of the node
    int getLength(ListNode* head)
    {
        ListNode* temp = head;
        int length = 0;
        while(temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //let 1t check the base cases
        if(head == NULL) return head;
        if(head->next == NULL) return head;

        //now we will try to solve this using recurssion (revering)
        //so 1st we will try to solve 1 
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = NULL;
        int pos = 0;

        //now we will check if there is space for k at a time
        int length=getLength(head);
        if(length<k) return head;

        //we will reverse the k elements
        while(pos<k)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            pos++;
        }

        //recurssion, trust the recurssion process
        ListNode* recurssionAns = NULL;
        //now do the recurssion 
        if(nextNode != NULL)
        {
            recurssionAns = reverseKGroup(nextNode, k); //pass nextNode and not head
            //now we willlik the parts of the recurssion (vey imp, common  mistake)
            head->next = recurssionAns;
        }

        return prev; //sarting point of the LL
    }
};