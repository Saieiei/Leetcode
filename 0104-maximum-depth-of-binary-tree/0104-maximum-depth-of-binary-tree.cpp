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
    int maxDepth(TreeNode* root) {
        //idk how this works but it works

        if(root == NULL) return 0;
        else
        {
            int leftHeight = maxDepth(root->left);
            int rightHeight = maxDepth(root->right);
            return max(leftHeight+1, rightHeight+1);
        }
    }
};