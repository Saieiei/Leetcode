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
    void recurssion (ListNode* head, int& carry)
    {
        //we will push the head pointer till the end
        if(!head) return;
        recurssion(head->next, carry); //THIS IS TO PUSH IT TILL THE END

        //now after going till the end we will solve 1 case
        int product = head->val * 2 + carry;
        head->val = product % 10;
        carry = product / 10;
    }
    ListNode* doubleIt(ListNode* head) {
        //we will do this recurssion 
        //we will do 1 case rest recurssion will take care

        //1st we will have to go till the end
        int carry = 0;
        recurssion(head, carry); //make sure to pass carry by refference as we need the value and it should be destryed during recurssion
        //now incase we gert a carry in the end
        if(carry)
        {
            //we will have to create a new node and point it at the beginging of the list
            ListNode* newCarryNode = new ListNode(carry);
            newCarryNode->next = head;
            head = newCarryNode;
        }
        return head;
    }
};