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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //we will have to start with dummy and tail
        //dummy will stay as the head and tail will figure the path between these 2 lists
        //in the end move dummy->next is the head and return head
        //the tail will find its way until any1 of the list reaches NULL
        //if 1 of them reached the end we have to check if the other 1 has also reached the end
        //so in the end the tail has successfully consumed both the lists
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                tail->next = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(list1 != NULL){
            tail->next = list1;
        }
        if(list2 != NULL){
            tail->next = list2;
        }
        ListNode* head = dummy;
        head = dummy->next;
        delete dummy;
        return head;
    }
};