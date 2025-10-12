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
    //step1: create Inorder vector 
    //step2: update the Inorder vector
    //step3: update the BST with the Inorder vector

    void createInorderVector(TreeNode* root, vector<int>& inorderVector)
    {
        //basecase
        if(root == NULL)return;
        //LNR
        createInorderVector(root->left, inorderVector);
        inorderVector.push_back(root->val);
        createInorderVector(root->right, inorderVector);
    }

    void updateBST(TreeNode* root, vector<int>& inorderVector, int& index)
    {
        //basecase
        if(root == NULL)return;
        //LNR
        updateBST(root->left, inorderVector, index);
        root->val = inorderVector[index]; index++;
        updateBST(root->right, inorderVector, index);
    }

    TreeNode* convertBST(TreeNode* root) {

        //basecase
        if(root == NULL)return root;
        if(root->left == NULL && root->right == NULL)return root;

        //step1: create Inorder vector
        vector<int>inorderVector;
        createInorderVector(root, inorderVector);

        int n = inorderVector.size();
        int prevSum = 0;
        //step2: update the Inorder vector
        for(int i=n-1; i>=0; i--)
        {
            int curr = inorderVector[i];
            int sum = curr + prevSum;
            inorderVector[i] = sum;
            prevSum = sum;
        }

        //step3: update the BST with the Inorder vector
        int index = 0;
        updateBST(root, inorderVector, index);
        return root;
    }
};