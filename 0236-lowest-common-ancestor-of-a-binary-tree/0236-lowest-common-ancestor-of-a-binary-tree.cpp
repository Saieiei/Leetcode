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
        //the logic is simple
        //if the node is p then return , if the node is q then return
        //if the node is null return null
        //recursion, find out the same for the left sub tree and the rigth sub tree
        //backtracking, return p and q if u get any1 of them

        //basecase
        if(root == NULL)return NULL;
        if(root == p)return p;
        if(root == q)return q;

        //recursion
        TreeNode* leftSubTree = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightSubTree = lowestCommonAncestor(root->right, p, q);

        //backtracking
        if(leftSubTree == NULL && rightSubTree == NULL) return NULL;
        if(leftSubTree != NULL && rightSubTree == NULL) return leftSubTree;
        if(leftSubTree == NULL && rightSubTree != NULL) return rightSubTree;
        return root; //both found, from that root
    }
};