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
    ListNode* swapPairs(ListNode* head) {
        //this is more like a formula
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while(prev->next != NULL && prev->next->next != NULL){

            ListNode* curr = prev->next;
            ListNode* forward = curr->next;

            // Swap the pair.
            curr->next = forward->next;
            forward->next = curr;
            prev->next = forward;

            // Move prev to the end of this swapped pair.
            prev = curr;
        }
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};