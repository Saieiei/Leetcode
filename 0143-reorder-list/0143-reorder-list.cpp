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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;

        //finding the middle element
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse the 2nd half (but take the next element)
        ListNode* second_half = reverse(slow->next);

        //break the LL into 2 separate LL
        slow->next = nullptr;
        
        //join both of them now
        ListNode* first_half = head;
        while (second_half) {
            ListNode *temp1 = first_half->next;
            ListNode *temp2 = second_half->next;
            first_half->next = second_half;
            second_half->next = temp1;
            first_half = temp1;
            second_half = temp2;
        }
    }
    
    //reverse the 2nd half
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev; // Return the new head of the reversed list
    }
};
