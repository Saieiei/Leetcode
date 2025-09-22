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

    int getIndex(int& element, vector<int>& inorder)
    {
        for(int i=0; i<inorder.size(); i++)
        {
            if(element == inorder[i])return i;
        }
        return -1; //this will never happen
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int& preorderIndex, int inordereStart, int inorderEnd)
    {
        //basecase (check the preorderIndex and inordereStart)
        if(preorderIndex >= preorder.size()) return NULL;
        if(inordereStart > inorderEnd) return NULL;

        //create the root node
        int element = preorder[preorderIndex];
        preorderIndex++; //int element = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(element);
        
        //find leftSubTree and rightSubTree (recursion)
        //find the preorderIndex in inorder
        int inorderIndex = getIndex(element, inorder);

        root->left = buildTreeHelper(preorder, inorder, preorderIndex, inordereStart, inorderIndex-1);
        root->right = buildTreeHelper(preorder, inorder, preorderIndex, inorderIndex+1, inorderEnd);
        return root;
    }




    //to do this we will create the node based on preorder
    //to decide the potentail left sub tree and right sub tree we will use inorder
    //so we have to keep the track of index of preorder
    //make sure that that inorder doesnt go out of bounds because that is our potentail sub trees
    //so find the element of preorder in inorder
    //create the leftSubTree which will be inordereStart se inorderIndex-1 (recursion)
    //create the rightSubTree which will be inorderIndex+1 till the inorderEnd (recursion)
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inordereStart = 0;
        int inorderEnd = inorder.size()-1;
        int preorderIndex = 0;
        //helper functio (recursion)
        TreeNode* root =  buildTreeHelper(preorder, inorder, preorderIndex, inordereStart, inorderEnd);
        return root;
    }
};