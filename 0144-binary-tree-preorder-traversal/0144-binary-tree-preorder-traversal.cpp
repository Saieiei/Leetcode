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
    void preorderTraversalHelper(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL) return;
        else
        {
            ans.push_back(root->val);
            preorderTraversalHelper(root->left, ans);
            preorderTraversalHelper(root->right, ans);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        //preorder -> NLR
        //we will solve this using recurssion
        vector<int> ans;
        //helperfunction
        preorderTraversalHelper(root, ans);
        return ans;
    }
};