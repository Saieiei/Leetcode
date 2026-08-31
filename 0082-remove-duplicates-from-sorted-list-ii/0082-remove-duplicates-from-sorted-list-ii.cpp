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
        //the unique part is that we have to remove teh duplicates and self
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* curr = head;
        while(curr){
            //we have to check if this is a duplicate
            // duplicate found
            if(curr->next && curr->val == curr->next->val) {
                int duplicate = curr->val;
                // delete ALL nodes having this value
                while(curr && curr->val == duplicate) {
                    ListNode* toDelete = curr;
                    curr = curr->next;
                    delete toDelete;
                }
                // bridge over the deleted section
                prev->next = curr;
            }
            else {
                // curr is unique
                prev = curr;
                curr = curr->next;
            }
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead; 
    }
};