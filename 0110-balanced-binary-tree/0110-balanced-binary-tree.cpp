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
//for this q we will use the logic to calculate the height(recurssion)(maxdepth)
//then to compute this, at each node we will find it its balanced, then check left , then check right (all use recursion again)
//if node is balanced (abs(!>1)) then return true, else false
//if check if left subtree and right subrtree are balanced

    int maxDepth(TreeNode* root)
    {
        //base case
        if(root == NULL)return 0;

        int op1 = maxDepth(root->left)+1;
        int op2 = maxDepth(root->right)+1;
        return max(op1, op2);
    }
    bool isBalanced(TreeNode* root) {
        //base case
        if(root==NULL)return true;
        //node
        int leftTreeHeight = maxDepth(root->left);
        int rightTreeHeight = maxDepth(root->right);
        int absDiff = abs(leftTreeHeight-rightTreeHeight);
        if(absDiff>1) return false;
        else 
        {
            //left
            bool leftSubTree = isBalanced(root->left);
            //right
            bool rightSubTree = isBalanced(root->right);
                //check if left and right are balanced
                if(leftSubTree && rightSubTree) return true;
                else return false;
        }
    }
};