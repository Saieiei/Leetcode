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

    TreeNode* bstFromPreorderHelper(int start, int end, int& index, vector<int>&preorder){
        //basecase
        if(index>preorder.size()-1)return NULL;
        
        //leftRight
        TreeNode* root = NULL; //we reach the leaf nodes
        if(preorder[index] > start && preorder[index] < end){
            root = new TreeNode(preorder[index]);
            index++;

            //recursion
            root->left = bstFromPreorderHelper(start, root->val, index, preorder);
            root->right = bstFromPreorderHelper(root->val, end, index, preorder);
        }

        //backtrack
        return root;
    }


    //this is method 3 where, u do it with limits
    //as we go we get the indea where its goign to go
    // O(n)
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int start = INT_MIN;
        int end = INT_MAX;  
        int index = 0;

        TreeNode* root =  bstFromPreorderHelper(start, end, index, preorder);

        return root;
    }
};