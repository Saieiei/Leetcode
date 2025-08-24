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
//this is simple only
//u have to reverse, add, reverse
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy;
        int carry = 0;

        // Reverse the list to facilitate doubling from least significant to most
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        head = prev;  // head now points to the reversed list

        while (head) {
            int doubled = head->val * 2 + carry;
            carry = doubled / 10;
            current->next = new ListNode(doubled % 10);
            current = current->next;
            head = head->next;
        }

        // If there is any carry left
        if (carry) {
            current->next = new ListNode(carry);
        }

        // Reverse the list back to its original order
        ListNode* doubledList = dummy->next;
        prev = nullptr;
        while (doubledList) {
            ListNode* nextNode = doubledList->next;
            doubledList->next = prev;
            prev = doubledList;
            doubledList = nextNode;
        }
        return prev;
    }
};