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

    int getIndex(vector<int>& inorder, int element)
    {
        for(int i=0; i<inorder.size(); i++)
        {
            if(inorder[i] == element) return i;
        }
        return -1;
    }
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int& postordernIndex, int inorderStart, int inorderEnd)
    {
        //basecase
        if(postordernIndex < 0)return NULL; //(right to left)
        if(inorderStart > inorderEnd)return NULL;

        //create the node
        int element = postorder[postordernIndex--];
        TreeNode* root = new TreeNode(element);

        int inorderIndex = getIndex(inorder, element);

        //1st right then left sub trees
        root->right = buildTreeHelper(inorder, postorder, postordernIndex, inorderIndex+1, inorderEnd);
        root->left = buildTreeHelper(inorder, postorder, postordernIndex, inorderStart, inorderIndex-1);
        return root;

    }

//this is same as the (https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/)
//just that we have make sure of 2 things
    //1st is the we will go from right to left in the postorder index and find that element in the inorder
    //2nd is that we have 1st find the rightSubTree then the leftSubTree (postorder LRN (right to left))
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorderIndex = postorder.size()-1; //right to left
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;

        TreeNode* root = buildTreeHelper(inorder, postorder, postorderIndex, inorderStart, inorderEnd);
        return root;
    }
};