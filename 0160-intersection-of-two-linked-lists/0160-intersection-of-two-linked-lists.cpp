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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //its simple only
        //if the length of the LLs r the same, then Node a == Node b at some point of iterations
        //if they are not the same then, obio some LL is bigger than the other
        //we will have to figure out which LL is bigger than the other and by how much
            //this will help us find out by how much we should keep our Head ahead such that Node a == Node b at some point of iterations
        //there can also be a case where the LL doesnt intersect and they could be of the same length
            //in that case, both the LL will be pointing to NULL and the nodes can never be the same, then return NULL;

        if (!headA || !headB) return nullptr;

        //if the length of the LLs r the same, then Node a == Node b at some point of iterations
        ListNode* a = headA;
        ListNode* b = headB;

        while(a->next && b->next)
        {
            if(a == b)
            {
                return a;
            }
            a= a->next;
            b= b->next;
        }

        //there can also be a case where the LL doesnt intersect and they could be of the same length
            //in that case, both the LL will be pointing to NULL and the nodes can never be the same, then return NULL;
        if(!a->next && !b->next && a!=b) return NULL;

        //if they are not the same then, obio some LL is bigger than the other
        //we will have to figure out which LL is bigger than the other and by how much
            //this will help us find out by how much we should keep our Head ahead such that Node a == Node b at some point of iterations
        int count =0;
        if(b->next == NULL)
        {
            while(a->next)
            {
                a=a->next;
                count++;
            }
            while(count--)
            {
                headA = headA->next;
            }
            while(headA && headB)
            {
                if(headA == headB)
                {
                    return headA;
                }
                headA= headA->next;
                headB= headB->next;
            }
            
        }
        else
        {
            while(b->next)
            {
                b=b->next;
                count++;
            }
            while(count--)
            {
                headB = headB->next;
            }
            while(headA && headB)
            {
                if(headA == headB)
                {
                    return headA;
                }
                headA= headA->next;
                headB= headB->next;
            }
        }
        return nullptr;
    }
};