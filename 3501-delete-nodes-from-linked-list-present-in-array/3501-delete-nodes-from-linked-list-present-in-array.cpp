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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        //its easy only, nothign new

        //we will use set for direct loopup O(1)
        unordered_set<int> st(nums.begin(), nums.end());

        //ok now we will create a new node which will be pointing to the head
        //we r doing this, because in case the entier linked list is deleted, we will have somethign to return
        ListNode* start = new ListNode(0);
        start->next = head;
        ListNode* prev = start;
        ListNode* curr = head;

        while(curr != NULL)
        {
            if(st.find(curr->val) != st.end())//found the element
            {
                //we have to delete teh node
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                //just move forward
                prev = curr;
                curr = curr->next;
            }
        }
        return start->next;
    }
};