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
    //greater<int>
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //we will not use bruteforce, thats NxM
        //we will use min-Heap NlogM
        //take the starting nodes of the LL and push it in min-Heap
        //take the top ele from min-Heap and push it in new LL
        //keepdoing until the minHeap gets empty
        //keep pushing in minhead also (topNode->next)
        //minHeap, requires a cutome gereater<int>
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        //push the 1st nodes in the minHeap
        for(ListNode* &it: lists){
            if(it != NULL){
                pq.push(it);
            }
        }
        //keep processing until the minHeap is not empty
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(!pq.empty()){
            //get the top and pop it an push it
            ListNode* topNode = pq.top();
            pq.pop();
            //check if this is the 1st node ever,
            if(head == NULL){
                head = topNode;
                tail = topNode;
            }
            else{
                //if not, update tail and move it
                tail->next = topNode;
                tail = tail->next;
            }
            //push in the next node in the minHeap
            if(topNode->next){
                pq.push(topNode->next);
            }
        }
        return head;
    }
};