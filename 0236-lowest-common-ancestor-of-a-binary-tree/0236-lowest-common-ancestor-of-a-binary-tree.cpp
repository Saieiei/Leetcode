/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//week 13
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //we will solve this problem using recurssion only

        //base case
        if(root == NULL) return NULL;
        if(root->val == p->val) return p;
        if(root->val == q->val) return q;

        //now we will do recurssion
        TreeNode* leftAns= lowestCommonAncestor(root->left, p, q);
        TreeNode* rightAns= lowestCommonAncestor(root->right, p, q);

        //backtracking
        if(leftAns == NULL && rightAns == NULL) return NULL;
        if(leftAns != NULL && rightAns == NULL) return leftAns;
        if(rightAns != NULL && leftAns == NULL) return rightAns;
        else return root; //both found, from that root
    }
};