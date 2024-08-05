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
    TreeNode* build(int& i, int min, int max, vector<int>& preorder)
    {
        TreeNode* root = NULL;
        if(i>=preorder.size()) return NULL;

        if(preorder[i]>min && preorder[i]<max)
        {
            root = new TreeNode(preorder[i]);
            i++;
            root->left = build(i, min, root->val, preorder);
            root->right = build(i, root->val, max, preorder);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //we will solve this using recurssion
        //the main idea is to maintain a min and max values for every node and move accordingly
        int min = INT_MIN;
        int max = INT_MAX;
        int i = 0;
        return build(i, min, max, preorder);
    }
};