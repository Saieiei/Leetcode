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
    void inorderTraversalHelper(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL) return;
        else
        {
            //L
            inorderTraversalHelper(root->left, ans);
            //N
            ans.push_back(root->val);
            //R
           inorderTraversalHelper(root->right, ans);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        //inorderTraversal -> LNR
        //we will solve this using recurssion
        vector<int> ans;
        //we will use a helper function
        inorderTraversalHelper(root, ans);
        return ans;
    }
};