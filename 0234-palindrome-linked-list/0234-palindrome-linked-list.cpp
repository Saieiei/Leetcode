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
    bool isPalindrome(ListNode* head) {
        //easy
        //middle point (divide the vector in 2 halfs)
        //reverse the 2nd half
        //compare both of them

        //bc, single node or no node
        if(head == NULL || head->next == NULL){
            return true;  
        }
        //get the middle node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalfHead = reverse(slow->next);

        //now compare both the LLs
        while(secondHalfHead){
            if(secondHalfHead->val != head->val){
                return false;
            }
            else{
                secondHalfHead = secondHalfHead->next;
                head = head->next;
            }
        }
        //all passed
        return true;
    }
};