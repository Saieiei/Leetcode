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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;

        //case1: if both p and q are on the left side of the root node
        if(p->val < root->val && q->val < root->val) 
        {
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }
        
        //case2: if both p and q are on the right side of the root node
        if(p->val > root->val && q->val > root->val) 
        {
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }

        //case3: if p is on the left side and q is on the right side of the root
        if(p->val < root->val && q->val > root->val)
        {
            return root;
        }

        //case4: if q is on the left side and p is on the right side of the root
        if(q->val < root->val && p->val > root->val)
        {
            return root;
        }
        return root; //this wont happen mostly
    }
};