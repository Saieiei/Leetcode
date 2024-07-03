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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1}; //default ans



        //so 1st we need 3 things to find CP (prev, curr, nxt) //if any1 of them doesnt exist then it is not possible 
        if (!head || !head->next || !head->next->next) return ans;

        ListNode* prev = head;
        ListNode* curr = prev->next;
        ListNode* nxt = prev->next->next;

        //now we have to keep the track of cp to find out the minDistance and maxDistance
        int firstCp = -1;
        int lastCp = -1;
        int minDist = INT_MAX;
        //lets start from position 1 (curr) because 1st node (0th) can never be a cp
        int i = 1;

        //now we will traverse through the list as check if the node that we get is cp or not
        //1st and last can never be a cp
        while(nxt)
        {
            //now we will check if the node is cp or not
            bool cp = ( (curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val) );
            //lets fix our 1st cp
            if(cp && firstCp == -1)
            {
                firstCp = i;
                lastCp = i;
            }
            else if(cp) //if its not the firstCp
            {
                
                //check if this is minimum or not 
                minDist = min(minDist, (i-lastCp));
                //update last cp
                lastCp = i;
                
            }
            i++;
            prev = prev->next;
            curr = curr->next;
            nxt = nxt->next;
        }
        //now if our 1st and last cp is same, forexample array of 3 elements
        if(firstCp == lastCp) return ans;
        else
        {
            ans[0] = minDist;
            ans[1] = lastCp - firstCp;
        }
        return ans;
    }
};