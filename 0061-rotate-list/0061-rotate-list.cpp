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
    int lengthFinder(ListNode* head)
    {
        int count = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        //we will solve this by finding out how much we r suppose to rotate,
        //for example if the length of the LL is 5 then rotating it 10 times (k) is vasically the same as not rotating at all
        //to find out the actual rotation we can use modulus 

        //base case
        if (head == NULL || head->next == NULL || k == 0) return head;

        int len = lengthFinder(head);
        int actualRotation = k % len;

        //now we will write the base condition
        if(actualRotation == 0) return head; //no need to do rotation

        //if the remainder is not 0, then we have to do rotation
        //1st lets find the last node
        int newLastNodePos = len - actualRotation - 1; //we r doing -1 because we will start the for loop with 0
        ListNode* NewLastNode = head;
        //now lets put LastNode to its proper position
        for(int i=0; i<newLastNodePos; i++)
        {
            NewLastNode = NewLastNode->next;
        }

        //now lets find the correct head, that is the next node of the last node
        ListNode* newHead = NewLastNode->next;
        //after finishing out the head make sure to make the lastNode point to nulll
        NewLastNode->next = NULL;

        //now we will have to travel to the last node of the LL and link the last node of the LL to head for tthe flow
        ListNode* iterator = newHead; //dont put head
        while(iterator->next)
        {
            iterator = iterator->next;
        }
        //now since we r at the end, we will point it to the head
        iterator->next = head;

        return newHead;
        
    }
};