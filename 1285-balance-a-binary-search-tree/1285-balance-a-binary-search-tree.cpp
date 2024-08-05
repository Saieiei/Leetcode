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
    void inorder(TreeNode* root, vector<int>& inorderVec)
    {
        //base case
        if(!root) return;
        //inorder
        //L
        inorder(root->left, inorderVec);
        //N
        inorderVec.push_back(root->val);
        //R
        inorder(root->right, inorderVec);
    }
    TreeNode* balanceBSTHelper(vector<int>& inorderVec, int start, int end)
    {
        if(start > end) return NULL;
        int mid  = (start + end) >> 1;

        TreeNode* root = new TreeNode(inorderVec[mid]); 
        root->left = balanceBSTHelper(inorderVec, start, mid -1);
        root->right = balanceBSTHelper(inorderVec, mid +1, end);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        //to balce the tree we have to do inorder traversal
        //store the inorder traversal elements in an array
        //next we will do bianrry search on that inorder vec, and put the elemnts accordingly to its left, then right
        vector<int> inorderVec;
        inorder(root, inorderVec);

        return balanceBSTHelper(inorderVec, 0, inorderVec.size()-1);
    }
};