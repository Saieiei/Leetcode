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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //this is simple only, 2 pointer approach, O(N+M) O(1)
        //we should match the node and not the value
        //we will keep on trying to match the LLs
        //if they come to a NULL then we will make it go as a head to the other LL
        ListNode* a = headA;
        ListNode* b = headB;
        while(a != b){
            //before moving it ahead, check if its NULL
            if(a == NULL){
                a = headB;
            }
            else{
                a = a->next;
            }
            //the same goes for b as well
            if(b == NULL){
                b = headA;
            }
            else{
                b = b->next;
            }
        }
        //return any1, since they r now at the same node
        return a;
    }
};