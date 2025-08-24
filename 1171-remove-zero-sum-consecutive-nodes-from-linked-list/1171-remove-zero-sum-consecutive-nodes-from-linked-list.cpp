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
//week 10, have to watch to understand, (cumulative deletion)
    void sanitizeMap(ListNode*  head, unordered_map<int, ListNode*>& mp, int csum)
    {
        //deleting
        int temp = csum;
        while(true)
        {
            temp = temp + head->val;
            if(temp == csum) break;
            mp.erase(temp);
            head = head->next;
        }
    }
    ListNode* removeZeroSumSublists(ListNode* head) {
        //we will do this using unorderd_map
        //1t we will take care of bae cae
        if(!head || (!head->next && head->val == 0) ) return 0;
        //now we will create a unordered_map
        unordered_map<int, ListNode*> mp;
        ListNode* it = head;
        //we will keep on adding thhe sum, if we get the sum == 0, then we will have to clear the mp and put the head to the next of the it, (becaue of it node we r getting sum as 0) this will automatically remove all the elements before it/lost
        int csum = 0;
        while(it)
        {
            csum = csum + it->val;
            if(csum == 0)
            {
                mp.clear();
                head = it->next;
            }
            else if(mp.find(csum) != mp.end())  //to check if th ecumulative is there or not in the mp
            {
                sanitizeMap(mp[csum]->next, mp, csum);
                mp[csum]->next = it->next;
            }
            else{//else case- Add entries of prefix sum of each node into map 
            mp[csum]=it;
            }
            it=it->next;
        }
        return head;
    }
        
};