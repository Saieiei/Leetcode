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

    void  InorederTraversalVectorHelper(TreeNode* root, vector<int>& InorederTraversalVector){
        //baseCase
        if(root == NULL)return;

        //recursion LNR
        InorederTraversalVectorHelper(root->left, InorederTraversalVector);
        InorederTraversalVector.push_back(root->val);
        InorederTraversalVectorHelper(root->right, InorederTraversalVector);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int>InorederTraversalVector;
        InorederTraversalVectorHelper(root, InorederTraversalVector);
        return InorederTraversalVector[k-1];
    }
};