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

    void  kthSmallestHelper(TreeNode* root, int k, TreeNode*& ansRoot, int& counter){
        //baseCase
        if(root == NULL)return;

        //recursion LNR
        kthSmallestHelper(root->left, k, ansRoot, counter);
        counter++;
        if(counter == k){ 
            ansRoot = root;
            return;
        }
        kthSmallestHelper(root->right, k, ansRoot, counter);
    }

    int kthSmallest(TreeNode* root, int k) { //we will have a counter that will go up as it covers 1 node
        TreeNode* ansRoot = NULL;
        int counter = 0;
        kthSmallestHelper(root, k, ansRoot, counter);
        return ansRoot->val;
    }
};