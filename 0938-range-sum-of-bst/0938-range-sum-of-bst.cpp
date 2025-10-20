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


    void inorderTraversal(TreeNode* root, vector<int>& inorderVector){
        //basecase
        if(root == NULL)return;

        //recursion LNR
        inorderTraversal(root->left, inorderVector);
        inorderVector.push_back(root->val);
        inorderTraversal(root->right, inorderVector);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> inorderVector;
        inorderTraversal(root, inorderVector);

        int sum = 0;
        for(int i: inorderVector){
            if(i>=low && i<=high) sum = sum + i;
        }

        return sum;
    }
};