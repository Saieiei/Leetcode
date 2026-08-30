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
    ListNode* getKthNode(ListNode* head, int& l, int& k){
        int stepsToGetKthNode = l -k -1;
        for(int i=0; i<stepsToGetKthNode; i++){
            head = head->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        //for this, we will not be using the array method
        //that is reverse the whole array , then reverse k ele
        //then reverse the rest of them
        //instead, 1st we will mkae it circular at the same time find its length
        //then find teh new tail that is going to to be length -k -1
        //and then the next element should be ur tail
        //before u break the LL to get the tail get the newHead
        //which should be tail->next
        //bc, alone or nothign or nothing to rotate
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        //1st make it circular, in the process get the length
        //we r doing from 1 because we will stop before tail becomes NULL
        int l = 1; 
        ListNode* tail = head;
        while(tail->next != NULL){
            l++;
            tail = tail->next;
        }
        tail->next = head;
        //we dont have to do k times
        k = k%l;
        //bc, dont have to do anythign
        if(k == 0){
            //before u return break the cycle u just created
            tail->next = NULL;
            return head;
        }
        //kth Node should be the newTail
        ListNode* newTail = getKthNode(head, l, k);
        //get the newHead
        ListNode* newHead = newTail->next;
        //break teh circular loop
        newTail->next = NULL;
        return newHead;
    }
};
