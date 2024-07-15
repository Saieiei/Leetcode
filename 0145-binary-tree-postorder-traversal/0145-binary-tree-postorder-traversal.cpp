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
    void postorderTraversalHelper(TreeNode* root, vector<int>& ans)
    {
        if(root == NULL) return;
        else
        {
            //L
            postorderTraversalHelper(root->left, ans);
            //R
            postorderTraversalHelper(root->right, ans);
            //N
            ans.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        //postorderTraversal -> LRN
        //we will solve this using recurssion
        vector<int> ans;
        //we will use a helper function
        postorderTraversalHelper(root, ans);
        return ans;
    }
};