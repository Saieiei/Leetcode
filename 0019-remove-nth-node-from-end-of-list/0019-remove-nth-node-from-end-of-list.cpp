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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // we should use a dummy variable, which will be before head
        // we will use slow and fast pointer
        // the faster moves 1st till nth element
        // then we move slow pointer and fast pointer togteher
        // until the fast point becomes null
        // at this point, the slow pointer is 1 node ehind the nth node to
        // delete adjust the next, delete it and delete the dummy as well,
        // dummy->next is head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* nodeToDelete = slow->next;
        slow->next = nodeToDelete->next;
        delete nodeToDelete;
        // not needed
        head = dummy->next;
        delete dummy;
        return head;
    }
};