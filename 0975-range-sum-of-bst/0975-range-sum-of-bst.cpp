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
    //int rangeSumBST(TreeNode* root, int low, int high) {
    //    if (!root) {
    //        return 0;
    //    }
    //    
    //    int currentVal = (root->val >= low && root->val <= high) ? root->val : 0;
    //    
    //    int leftSum = rangeSumBST(root->left, low, high);
    //    int rightSum = rangeSumBST(root->right, low, high);
    //    
    //    return currentVal + leftSum + rightSum;
    //}
    int rangeSumBST(TreeNode* root, int low, int high) {
        //this time we will use the property of the BST Tree
        if(!root) return NULL;
        int ans = 0;
        bool wasInRange = false;
        if(root->val >= low && root->val <= high) 
        {
            wasInRange  = true;
            ans+=root->val;
        }
        if(wasInRange)
        {
            ans += rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        //not in range?
        else if(root->val > high) //go left
        {
            ans+=rangeSumBST(root->left, low, high);
        }
        else if(root->val < low) //go right
        {
            ans+=rangeSumBST(root->right, low, high);
        }
        return ans;
    }
};