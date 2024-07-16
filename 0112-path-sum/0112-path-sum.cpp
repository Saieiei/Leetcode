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
//week 13
    bool hasPathSumHelper(TreeNode* root, int targetSum, int sum)
    {
        //base case
        if(root == NULL) return false;
        sum = sum + root->val;
        if(root->left == NULL && root->right == NULL) //at the leaf node
        {
            //verify
            if(sum == targetSum) return true;
            else return false;
        }
        bool leftRecursion = hasPathSumHelper(root->left, targetSum, sum);
        bool rightRecursion = hasPathSumHelper(root->right, targetSum, sum);
        return  leftRecursion||rightRecursion;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        //we will solve this using recurssion
        //we will go to the left, then to the right
        //the base case is, if it reaches the leafnode, or there is no root node, or 
        int sum = 0;
        bool ans = hasPathSumHelper(root, targetSum, sum);
        return ans;
    }
};