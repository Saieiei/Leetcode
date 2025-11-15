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

class compare{
public:
    bool operator()(ListNode* a , ListNode* b){
        return a->val > b->val;
    }
};

//for this we will follow how we did this https://www.geeksforgeeks.org/problems/merge-k-sorted-arrays/1
//since we are dealing with LL we have to have a head and a tail (ans)
// we should take in any null pointers into the ans
//its kinda easy than array
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode* head = NULL; ListNode* tail = NULL;

        //1st nodes of each vector lists
        for(int i=0; i<lists.size(); i++){
            ListNode* temp = lists[i];
            //check if its empty, if not then only push
            if(temp != NULL)pq.push(temp);
        }

        //just like level order traversAL TECHNIQUE
        while(!pq.empty()){
            //take and pop the top elemnt
            ListNode* front = pq.top(); pq.pop();

            if(front){
                //then either this element can the begining of the ans or next next
                if(head == NULL && tail == NULL){ //this is the 1st element
                    head = front; tail = front;
                }
                else{ //next next
                    tail->next = front; tail = front;
                }
            }

            if(front->next) pq.push(front->next);
        }
        return head;
    }
};    