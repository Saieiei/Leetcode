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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        //simple
        //find the mid element
        //reverse the 2nd half
        //merge both of them

        ListNode* slow = head;
        ListNode* fast = head;
        //find the mid element
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalfHead = slow->next;
        //disconnect the 2 halfs
        slow->next = NULL;
        //reverse it
        ListNode* head2 = reverse(secondHalfHead);
        //merge both now
        ListNode* head1 = head;
        while(head2){
            ListNode* forward2 = head2->next;
            ListNode* forward1 = head1->next;
            head1->next = head2;
            head2->next = forward1;
            head1 = forward1;
            head2 = forward2;
        }
    }
};