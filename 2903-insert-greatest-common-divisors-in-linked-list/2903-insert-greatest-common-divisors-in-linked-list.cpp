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
    int GCD(int a, int b)
    {
        return b == 0?a:gcd(b, a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        //1st create a gcd funtion
        int a=0, b =0;
        int gcd  = GCD(a, b);

        //now just traverse through the list
        ListNode* curr = head;
        while(curr->next)
        {
            int ele1 = curr->val;
            ListNode* nextNode  = curr->next;
            int ele2 = nextNode->val;
            gcd = GCD(ele1, ele2);
            ListNode* temp = new ListNode(gcd);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
            
        }
        return head;
    }
};