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
    ListNode* mergeTwoLists(ListNode* list1ptr, ListNode* list2ptr) {
        //lets go with the base cases 1st
        if(!list1ptr) return list2ptr;
        if(!list2ptr) return list1ptr;

        //go we will start with a dummy node called ans
        ListNode* ans = new ListNode(-1);
        //we will start with the iterator whih is pointing to ans
        ListNode* iterator = ans;

        //now we will point each 1 of them in ascending order
        while(list1ptr && list2ptr)
        {
            if(list1ptr->val  <= list2ptr->val)
            {
                iterator->next = list1ptr;
                iterator = list1ptr;
                list1ptr = list1ptr->next;
            }
            else //list1ptr->val  >= list2ptr->val
            {
                iterator->next = list2ptr;
                iterator = list2ptr;
                list2ptr = list2ptr->next;
            }
        }

        //if 1 of the lists expires
        if(list1ptr) //list2ptr expired, and it will continue until list1ptr expires
        {
            iterator->next = list1ptr;
            iterator = list1ptr;
            list1ptr = list1ptr->next;
        }
        if(list2ptr) //list1ptr expired, and it will continue until list2ptr expires
        {
            iterator->next = list2ptr;
            iterator = list2ptr;
            list2ptr = list2ptr->next;
        }
        return ans->next;
    }
};