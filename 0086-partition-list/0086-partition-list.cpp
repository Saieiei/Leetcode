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
    ListNode* partition(ListNode* head, int x) {
        // Create two dummy nodes
        ListNode* smallDummy = new ListNode(0);
        ListNode* largeDummy = new ListNode(0);

        // Pointers to build the two lists
        ListNode* smallTail = smallDummy;
        ListNode* largeTail = largeDummy;

        ListNode* curr = head;

        while (curr != NULL) {
            if (curr->val < x) {
                smallTail->next = curr;
                smallTail = smallTail->next;
            }
            else {
                largeTail->next = curr;
                largeTail = largeTail->next;
            }

            curr = curr->next;
        }

        // Terminate the large list
        largeTail->next = NULL;

        // Connect the two lists
        ListNode* largeHead = largeDummy->next;
        smallTail->next = largeHead;
        ListNode* smallHead = smallDummy->next;

        return smallHead;
    }
};
