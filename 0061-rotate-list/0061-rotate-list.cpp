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
    ListNode* rotateRight(ListNode* head, int k) {

        if (!head || k == 0) return head;
        
        //there are 2 methods to this
        //1 is using the iterative approach
        //another is using the circular approach

        //1st we have to figure out actual rotations
        // to do so we need to figure out the length of it
        ListNode* curr = head;
        int length =1;
        while(curr->next != nullptr)
        {
            length++;
            curr = curr->next;
        }

        //so now we have our curr at the last node and also the length of the ll
        //now to figure out actual rotations 
        k = k % length;
        int stepsToGoAhead = length - k;

        //make the ll circular
        curr->next = head;

        //now lets move forward to the last point of roatation and cut the chain
        ListNode* tail = head;
        for(int i=1; i<stepsToGoAhead; i++)
        {
            tail = tail->next;
        }
        //before we destroy the connection we will have to get the correct head
        ListNode* newHead = tail->next;
        //now destroy the link
        tail->next = nullptr;

        return newHead;
    }
};