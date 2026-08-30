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
    ListNode* getKthNode(ListNode* curr, int k){
        while(curr && k>0){
            curr = curr->next;
            k--;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        //this 1 is a little hard
        //so we require all these pointers
        //curr, prev and forwd for reversing
        //groupPrev, oldGroupStart for linking old group and new group
        //kthNode, groupNext for the next group purposes
        //IMP STUFF
        //while(true)
        //while starting reversal, link prev to groupNext
        //dummy node will be before head
        //the Main concept is that, we know where the group starts
        //we move k nodes forward to get the kth Node
        //we also have know where the next group starts which is kthNode->next
        //reverse that curr group
        //then we link the group to the next group and consider the group as old
        //if we r not able to get the kthNode (becomes NULL)
        //then no need to do anything, just delete the dummy node and return NewHead
        //NewHead is the dummy->next, we never touch head
        //1st create dummyNode
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* groupPrev = dummyNode;
        //V IMP
        while(true){
            ListNode* kthNode = getKthNode(groupPrev, k);
            //1st check if the group is there or not
            if(kthNode == NULL){
                break;
            }
            //now we have to reverse this group and also link it to the next group
            ListNode* groupNext = kthNode->next;
            //reverse it
            //V IMP
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            while(curr != groupNext){
                ListNode* forwd = curr->next;
                curr->next = prev;
                prev = curr;
                curr = forwd;
            }
            //now we have to make this group old to move forward to the next group
            //VIMP
            ListNode* oldGroupStart = groupPrev->next;
            groupPrev->next = kthNode;
            groupPrev = oldGroupStart;
        }
        //since we coudnt form the group (kthNode = NULL), simply return 
        ListNode* newHead = dummyNode->next;
        delete dummyNode;
        return newHead;
    }
};