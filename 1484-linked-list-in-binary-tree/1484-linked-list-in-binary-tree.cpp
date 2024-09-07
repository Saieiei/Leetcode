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
    bool checkerPath(ListNode* head, TreeNode* root)
    {
        //what can cause it to pass?
        if(head == NULL) return true;

        //what can cause it to fail?
        if(!root || root->val != head->val) return false;

        //for that node of the BT, we will traverse through the LL to check if it has a path or not (recurssion)
        return ((checkerPath(head->next, root->left)) || (checkerPath(head->next, root->right)));
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        //its super easy code
        //we will be usig recurssion twice
        //will be little difficult at the begining but once understood its a peace of cake

        //we will doing recurssion in this function as well
        //so what can cause it to break
        if(!root) return false;

        //now we will go to the left and right of the node of each node and check (recurssion)
        return (checkerPath(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right));
    }
};