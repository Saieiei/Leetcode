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
    ListNode* deleteDuplicates(ListNode* head) {
        //this is simple
        //check if the the curr node and the next node r the same
        //if they r same then move the next pointer to next->next
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = head;
        //start checking now
        while(curr && curr->next){
            //check if the next node is duplicate
            if(curr->val == curr->next->val){
                //duplicate
                ListNode* nodeToDelete = curr->next;
                curr->next = curr->next->next;
                delete nodeToDelete;
                //dont move curr forward immediately
                //TC: 1, 1, 1, 2 -> 1, 2
            }
            else{
                //move curr forward, only when they r not the same 
                curr = curr->next;
            }
        }
        return head;
    }
};