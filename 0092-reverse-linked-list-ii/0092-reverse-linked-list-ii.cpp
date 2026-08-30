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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //this is easy
        //we stay 1 node before the reversed group (beforeGroupNode)
        //we can get the after node of the reversed group (prev)
        //so now we can link the before and after of the reversed group
        //u can reverse the group with the help of prev curr and forward
        //keep moving forward  R-L+1 times (reversing the nodes)

        //we will use dummy just be safe with the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        //get the node 1 before the starting of the reverse group
        ListNode* beforeGroupNode = dummy;
        //move and stop just before left
        for(int i=0; i<left-1; i++){
            beforeGroupNode = beforeGroupNode->next;
        }
        //now reverse
        ListNode* prev = NULL;
        ListNode* curr = beforeGroupNode->next;
        for(int i=0; i<right-left+1; i++){
            ListNode* forwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forwd;
        }
        //now like them correctly
        ListNode* oldGroupStart = beforeGroupNode->next;
        beforeGroupNode->next = prev;
        oldGroupStart->next = curr;
        //return now
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};