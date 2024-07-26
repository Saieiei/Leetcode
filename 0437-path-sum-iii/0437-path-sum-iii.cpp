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
    int ans  = 0;
    void pathOfTheNode(TreeNode* root, long long targetSum)
    {
        if(!root) return;
        //Preorder Traversal
        //root
        if(root->val == targetSum) ans++;
        //go left
        pathOfTheNode(root->left, targetSum - root->val);
        //go right
        pathOfTheNode(root->right, targetSum - root->val);
    }
    int pathSum(TreeNode* root, long long targetSum) {
        //for every root we will see if there is a path or not
        //Preorder Traversal
        //root
        if(root)
        {
            pathOfTheNode(root, targetSum);
            //go left
            pathSum(root->left, targetSum);
            //go right
            pathSum(root->right, targetSum);
        }
        return ans;
    }   
};