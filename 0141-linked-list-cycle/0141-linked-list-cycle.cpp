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
        //floyd algo, same as finding the mid ele
        //slow and fast pointer
        //slow goes 1 step and fast goes 2 steps
        //if its not a cycle it will break the loop at
        //fast = null and fast->next = null
        //just break, when both r equal
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return slow;
            }
        }
        //not possible
        return false;
    }
};