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
    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* tempHead = new ListNode(0);
        ListNode* tail = tempHead;
        while(head1 && head2){
            if(head1->val <= head2->val){
                tail->next = head1;
                head1 = head1->next;
            }
            else{
                tail->next = head2;
                head2 = head2->next;
            }
            tail = tail->next;
        }
        //push in the remaining
        if(head1){
            tail->next = head1;
            tail = tail->next;
        }
        else{
            tail->next = head2;
            tail = tail->next;
        }
        ListNode* newHead = tempHead->next;
        delete tempHead;
        return newHead;
    }
    ListNode* sortList(ListNode* head) {
        //we will sort this using merge sort 
        //NlogN, logN
        //sortList(), sortList(), merge()
        //bc, single or no node
        if(head == NULL || head->next == NULL){
            return head;
        }
        //1st find the middle element
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalfHead = slow->next;
        ListNode* firstHalfHead = head;
        //VIMP
        //break the connection
        slow->next = NULL;
        //recursion
        firstHalfHead = sortList(firstHalfHead);
        secondHalfHead = sortList(secondHalfHead);
        //merge
        ListNode* newHead = merge(firstHalfHead, secondHalfHead);
        return newHead;
    }
};