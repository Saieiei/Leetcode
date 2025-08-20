/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //here we will use extra space <unordered_map>
        //we will iterate through the list and update the map as visited, until we reach true or temp->next = NULL return the node
        //else return false (NULL)

        if(!head || !head->next) return NULL;

        unordered_map<ListNode*, bool> mp;
        ListNode* temp = head;

        while(temp)
        {
            if(mp[temp] == true) return temp;
            else
            {
                mp[temp] =  true;
                temp = temp->next;
            }
        }
        return NULL;
    }
};