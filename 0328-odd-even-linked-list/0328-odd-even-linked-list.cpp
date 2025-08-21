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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;

        //its simple only, while iterating ther LL we will rearrange its next pointers
        ListNode* odd = head;
        ListNode* even = head->next;

        //we will need to save the even head because, when we r done iterating, the odd->next =evenHead
        ListNode* evenHead = even;

        //we will have to stop when there is no more even nodes
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            
            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;
        return head;
    }
};