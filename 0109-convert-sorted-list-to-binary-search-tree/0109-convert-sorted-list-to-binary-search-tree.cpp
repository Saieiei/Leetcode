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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    ListNode* findMidEleofLL(ListNode* head)
    {
        //basecase
        if(head == NULL)return NULL;

        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        //this is imp step
        if(prev) prev->next = NULL;
        return slow;
    }


//this is similar to this https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/submissions/1802595309/
    //but cant give the range for the LST and RST, so we have to cut it while finding the middle ele
    TreeNode* sortedListToBST(ListNode* head) {
        //base case
        if(head == NULL)return NULL;
        if(head->next == NULL){
            TreeNode* root = new TreeNode(head->val);
            return root;
        }

        ListNode* midLL = findMidEleofLL(head);
        TreeNode* root = new TreeNode(midLL->val);

        //recursion
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(midLL->next);

        return root;
    }
};