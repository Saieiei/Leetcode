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
//week 10
    ListNode* oddEvenList(ListNode* head) {
        //we can solve this by using additional space but, we will not do that
        //we will solve this in constant linear time and space

        //we will use 2 pointers, even and odd
        //but before that we have to check with the base case
        if(head == NULL || head->next == NULL) return head; //cant do anything
        ListNode* odd = head;
        ListNode* even = head->next;

        //we will store the pointer of the 1st even head as we will have to link the last of the odd lists with this pointer(starting even node)
        ListNode* firstEvenNode = head->next;

        //now we will link odd lists and even list (making 2 separe lists)
        while(even && even->next)
        {
            //1st we will link then 
            odd->next = even->next;
            even->next = even->next->next;
            //now we will move them 
            odd = odd->next;
            even = even->next;
        }

        //after we have linked all we will connect the last of the odd node to the 1st of the even node
        odd->next = firstEvenNode;
        return head; 
        
    }
};