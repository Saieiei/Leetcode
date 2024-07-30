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
    //week14
    int kthSmallest(TreeNode* root, int& k) { //make sure to pass it as int& k, because we will be subtracting the value during recurssion
        //this will be solved using inorder traversal
        //base case (leaf node)
        if(!root) return -1;
        
        //Inorder Treaversal
        //L
        int leftAns = kthSmallest(root->left, k);
        if(leftAns != -1) return leftAns;
        //return leftAns;

        //N
        k--;
        if(k == 0) return root->val;

        //R
        int rightAns = kthSmallest(root->right, k);
        return rightAns;
    }
};