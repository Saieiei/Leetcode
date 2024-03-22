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

 //O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //1st we will try to eliminate the starting conditions
         //if there is only 1 node in the LL
        if(head->next==nullptr) return true;
         //if there are only 2 nodde in the LL
        if(head->next->next==nullptr)
        {
            if(head->val==head->next->val) return true;
        }

        //2nd we will find the middle element
        ListNode* slow=head; ListNode* fast=head;
        while (fast && fast->next) 
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        //3rd we will reverse the 2nd half of the LL
        ListNode* prev=nullptr; ListNode* temp;
        while(slow)
        {
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }

        //4th we will check if its palindrome or not
        while(prev)
        {
            if(prev->val != head->val) return false;
            prev=prev->next;
            head=head->next;
        }

        return true;


        
        
    }
};