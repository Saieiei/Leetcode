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
    ListNode* oddEvenList(ListNode* head) {
        //this is simple too
        //bc
        if(head == NULL || head->next == NULL || head->next->next == NULL){
            return head;
        }
        ListNode* odd = head;
        ListNode* even = odd->next;
        ListNode* evenHead = even;
        //even odd LL
        while(even && even->next){
            odd->next = even->next;
            odd = odd->next;
            //we have moved odd forward
            even->next = odd->next;
            even = even->next;
        }
        //join them now
        odd->next = evenHead;
        return head;
    }
};