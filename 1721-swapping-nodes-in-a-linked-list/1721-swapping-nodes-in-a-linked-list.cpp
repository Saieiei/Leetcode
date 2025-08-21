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
    ListNode* swapNodes(ListNode* head, int k) {

        // 1) Find k-th node from the beginning
        ListNode* first = head;
        for (int i = 1; i < k && first; ++i) first = first->next;

        // 2) Find k-th node from the end:
        //    Start a runner at 'first' and a chaser at head.
        //    When runner hits the end, chaser will be k-th from end.
        //    u can take this as a sliding window type
        ListNode* runner = first;
        ListNode* chaser = head;
        while (runner->next) {
            runner = runner->next;
            chaser = chaser->next;
        }

        // 3) Swap values
        swap(first->val, chaser->val);
        return head;
    }
};