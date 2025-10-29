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

    class nodeData{
    public:
        int minVal;
        int maxVal;
        int sum;
        bool isBST;
    };

    nodeData traversal(TreeNode* root, int& validMaxSum){
        //basecase
        if(!root){
            nodeData temp;
            temp.minVal = INT_MAX;
            temp.maxVal = INT_MIN;
            temp.sum = 0;
            temp.isBST = true;
            return temp;
        }

        //Recursion LRN
        nodeData leftSubTree = traversal(root->left, validMaxSum);
        nodeData rightSubTree = traversal(root->right, validMaxSum);
        nodeData currNodeData;
        currNodeData.minVal = min(root->val, leftSubTree.minVal);
        currNodeData.maxVal = min(root->val, rightSubTree.maxVal);
        currNodeData.sum = root->val + leftSubTree.sum + rightSubTree.sum;
        //valid BST or not
        if(root->val > leftSubTree.maxVal && root->val < rightSubTree.minVal && leftSubTree.isBST && rightSubTree.isBST){
            currNodeData.isBST = true;
            //if true then update the validMaxSum
            validMaxSum = max(validMaxSum,  currNodeData.sum);
        }
        else currNodeData.isBST = false;
        return currNodeData;
    }

    int maxSumBST(TreeNode* root) {
        int validMaxSum = 0;
        traversal(root, validMaxSum);
        return validMaxSum;
    }
};