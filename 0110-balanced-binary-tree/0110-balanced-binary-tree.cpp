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
//class Solution {
//public:
////week 13
//    int height(TreeNode* root)
//    {
//        if(root == NULL) return 0;
//        else
//        {
//            int leftHeight = height(root->left);
//            int rightHeight = height(root->right);
//            int finalAns = max(leftHeight, rightHeight) +1; //because of the root node
//            return finalAns;
//        }
//    }
//    bool isBalanced(TreeNode* root) {
//        //for this to work, u should know how to find the height of a node
//        //for a node to be balanced, its right height and left height should not differ more tham 1
//        //for the rest of the nodes, we will do recursion
//        //this is very bad approach but
//        //base case
//        if(root == NULL) return true;
//
//        //for the currentNode
//        int leftHeight = height(root->left);
//        int rightHeight = height(root->right);
//        int diff = abs(leftHeight - rightHeight);
//        bool currentNode = diff<=1;
//
//        //now we will for the rest of the nodes
//        bool left = isBalanced(root->left);
//        bool right = isBalanced(root->right);
//
//        //check condition 
//        if(currentNode && left && right) return true;
//        else return false;
//    }
//};

class Solution {
public:
//week13
    bool ans = true;
    int height(TreeNode* root)
    {
        if(!root) return 0;
        //the height fucntion will go to each and everynode and return its height
        //it works on bottom up approach
        //do for the 1st node
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        //check if balanced
        int balanced = abs(leftHeight - rightHeight);
        if( ans && balanced>1) ans = false;

        //calculate its height
        return (max(leftHeight, rightHeight) + 1);
    }
    bool isBalanced(TreeNode* root)
    {
        //for this u have to know the concept of height
        //the height fucntion will go to each and everynode and return its height
        height(root);
        return ans;
    }
};