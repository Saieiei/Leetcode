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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        //no hacks, just simple thinking only, easy only
        //to calc a CP, u need 3 pointers (prev, curr, frd)
        //we need to keep a track on CP locations (CP_position), starting from pos CP_position=1 (curr)
        //we need to update the minDist and maxDist in vector<int> ans;
        //we should stop looking for CP when fwd becomes null

        //base cases
        vector<int> ans = {-1, -1};
        ListNode* prev = head;
        if(!prev) return ans;
        ListNode* curr = prev->next;
        if(!curr) return ans;
        ListNode* fwd = prev->next->next;
        if(!fwd) return ans;

        //initialisation
        int curr_position=1;
        int minDist = INT_MAX;
        int maxDist = 0; //it will keep expanding as we find out new CP
        int first_Position = -1;
        int last_position = -1;
        
        //lets start now
        while(fwd)
        {
            bool isCP = ((curr->val < prev->val && curr->val < fwd->val)||(curr->val > prev->val && curr->val > fwd->val))?1:0;

            //1st CP
            if(isCP == true && first_Position == -1)
            {
                first_Position = curr_position;
                last_position = curr_position;
            }
            else if(isCP) //not 1st CP
            {
                minDist = min(minDist, curr_position-last_position);
                last_position = curr_position;
                maxDist = last_position-first_Position;
            }

            curr_position++;
            prev = prev->next;
            curr = curr->next;
            fwd = fwd->next;
        }

        //found only 1 cp till now
        if(first_Position == curr_position) return ans;
        //0 cp
        else if (minDist == INT_MAX &&  maxDist == 0) return ans;
        else //found multiple CPs
        {
            ans[0] = minDist;
            ans[1] = maxDist;
        }
        return ans;
    }
};