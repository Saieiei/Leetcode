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
        //this work like magic
        //1st we have to find the cycle thereor not
        //use flyods algo
        //2nd if there then keep 1 pointer at the head 
        //and move both togther
        //where ever they r same, is the starting point of the cycle
        //return the node which becomes same
        ListNode* slow = head;
        ListNode* fast = head;
        //1st check if there is a cycle
        while(fast!=NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                //cycle found, now we have to find teh starting point of the cycle
                ListNode* curr = head;
                while(curr != slow){
                    slow = slow->next;
                    curr = curr->next;
                }
                //now they r the same, so return any1
                return slow;
            }
        }
        //no cycle means not possible
        return NULL;
    }
};