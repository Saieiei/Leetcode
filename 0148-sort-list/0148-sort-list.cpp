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
    ListNode* merge(ListNode* list1ptr, ListNode* list2ptr) {
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
        while(list1ptr) //list2ptr expired, and it will continue until list1ptr expires
        {
            iterator->next = list1ptr;
            iterator = list1ptr;
            list1ptr = list1ptr->next;
        }
        while(list2ptr) //list1ptr expired, and it will continue until list2ptr expires
        {
            iterator->next = list2ptr;
            iterator = list2ptr;
            list2ptr = list2ptr->next;
        }
        return ans->next; //head of the sorted list
    }

    ListNode* findmid(ListNode*  head)
    {
        //we will find the mid using slow fast approach, where if the length is even the middle element will be at the back, not front
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        } 
        return slow; //slow is ur mid
    }

    ListNode* sortList(ListNode* head) {
        //we will sort the list using merge sort method, where we will keep dividing it untill we get a single element
        //in the end we will merge then in correct order 
        //all this will be done using recurssion

        //lets finish the bases cases 
        //if the lists  has no elements or only 1 element then we cannot sort them
        if(head == NULL || head->next == NULL) return head;

        //1st step in merge sort is to find the middle element and split it into 2 separate lists (left and right)
        ListNode* mid = findmid(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        //break the connection btw left and right lists
        mid->next = NULL;

        //2nd step is to keep on doing recurssion and keep on breaking them untill we get a single element
        left = sortList(left);
        right = sortList(right);
        
        //3rd step is to merge the lists
        ListNode* sortedLL = merge(left, right);
        return sortedLL;
    } 
};