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
//    int diameterOfBinaryTree(TreeNode* root) {
//        // Define a helper function to calculate the diameter recursively
//        int res = 0;
//        diameter(root, res);
//        return res;
//    }
//
//private:
//    int diameter(TreeNode* curr, int& res){
//        // Base case: if the current node is null, return 0
//        if (!curr) return 0;
//        
//        // Recursively calculate the diameter of left and right subtrees
//        int left = diameter(curr->left, res);
//        int right = diameter(curr->right, res);
//
//        // Update the maximum diameter encountered so far
//        res = std::max(res, left + right);
//        
//        // Return the depth of the current node
//        return std::max(left, right) + 1;
//    }
//};
class Solution {
public:
    int diameterOfBinaryTreeHelper(TreeNode* root, int& ans)
    {
        if(!root) return 0;
        //the idea is to find thenode which has the sum of leftNodes and rightNodes the greatest
        //we will go bottoms up
        //for each node we will return the height of that node from the bottom
        //sum the left node and the right node
        //check if the greatest yet found (ans)
        int leftHeight = diameterOfBinaryTreeHelper(root->left, ans);
        int rightHeight = diameterOfBinaryTreeHelper(root->right, ans);
        int currentDiameter = leftHeight + rightHeight;
        ans = max(currentDiameter, ans);
        return max(leftHeight, rightHeight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root)
    {
        int ans = 0;
        diameterOfBinaryTreeHelper(root, ans);
        return ans;
    }
};