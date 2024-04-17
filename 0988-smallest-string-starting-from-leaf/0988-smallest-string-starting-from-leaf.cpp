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
 //https://www.youtube.com/watch?v=TwytdtyoLVo
class Solution {
public:
    string ans="~"; //ascii value = 127 (1 greater than z)
    void recc(TreeNode* root, string s)
    {
        //base conditions    
        if(!root) return;
        //leaf node or just 1 root node
        if(!root->left && !root->right)
        {
            //lexicographically sorting (smallest)
            ans=min(ans, char('a'+root->val)+s);
        }
        recc(root->left, char('a'+root->val)+s);
        recc(root->right, char('a'+root->val)+s);
    }
    string smallestFromLeaf(TreeNode* root) {
        //we will use recursion (DFS)
        recc(root, "");
        return ans;
    }
};