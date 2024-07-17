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
//week13
    // Helper function to construct the binary tree
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& inorderMap) {
        // Base case: if there are no elements to construct the tree
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }

        // The first element in preorder is the root of the current subtree
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of the root in inorder traversal
        int rootIndex = inorderMap[rootVal];

        // Calculate the number of elements in the left subtree
        int leftTreeSize = rootIndex - inStart;

        // Recursively construct the left subtree
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + leftTreeSize, 
                                     inorder, inStart, rootIndex - 1, inorderMap);

        // Recursively construct the right subtree
        root->right = buildTreeHelper(preorder, preStart + leftTreeSize + 1, preEnd, 
                                      inorder, rootIndex + 1, inEnd, inorderMap);

        return root;
    }

    // Main function to build the tree from preorder and inorder traversals
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store the index of each value in inorder traversal for quick lookup
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        // Call the helper function to construct the binary tree
        return buildTreeHelper(preorder, 0, preorder.size() - 1, 
                               inorder, 0, inorder.size() - 1, inorderMap);
    }
};
