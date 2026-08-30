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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //this is simple
        //keep on processing even if u have any1 of the nodes or carry
        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0;
        while(l1 || l2 || carry){
            //get the values
            int val1 = 0;
            int val2 = 0;
            if(l1){
                val1 = l1->val;
            }
            if(l2){
                val2 = l2->val;
            }
            int sum = val1 + val2 + carry;
            int digit = sum%10;
            carry = sum/10;
            ListNode* digitNode = new ListNode(digit);
            //check if this is the 1st ever number
            if(head == NULL){
                head = digitNode;
                tail = digitNode;
            }
            else{
                //move tail
                tail->next = digitNode;
                tail = tail->next;
            }
            //move the heads of the LL forward
            if(l1){
                l1 = l1->next;
            }
            if(l2){
                l2 = l2->next;
            }
        }
        return head;
    }
};