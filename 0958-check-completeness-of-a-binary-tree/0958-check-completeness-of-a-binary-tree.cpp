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
//we can make sure of the inorder traversal for this
//so during the inorder Traversal, if we find out a nullptr and then other nodes, then simply return false
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool nullstatus = false;

        while(!q.empty()){
            TreeNode* firstElement = q.front(); q.pop();
            if(firstElement == NULL) nullstatus = true;
            else{
                if(nullstatus) return false;
                q.push(firstElement->left);
                q.push(firstElement->right);
            }
        }
        return true;
    }
};