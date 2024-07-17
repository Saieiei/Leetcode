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
    TreeNode* delNodesHelper(TreeNode* root, unordered_set<int> to_delete_set, vector<TreeNode*>& forests)
    {
        //if the node is not valid, just return 
        if(root == NULL) return NULL;

        //postorder traversal
        root->left= delNodesHelper(root->left, to_delete_set, forests);
        root->right= delNodesHelper(root->right, to_delete_set, forests);

        //checker
        if(to_delete_set.count(root->val))
        {
            //if we have reached the node to be deleted, we have to return NULL to break it from the tree, but before that we have to add the children into the forests
            //just make sure that if its leafnode, or normal node
            if(root->left) forests.push_back(root->left);
            if(root->right) forests.push_back(root->right);

            return NULL;
        }
        //in the end return the root node
        return root;

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        //for this we have to use DFS and PostOrder traversal (LRN) where the children r executed 1st
        //if the node is a leafnode to be deleted, then do nothing, just return null
        //if the node to be deleted is not a leafnode, then put its chhildren in the vector<TreeNode*>(forest), and then return NULL, for the node to be deleted
        //in the end if the rootnode is not deleted of the orgignal tree, then simply insert the root in the ector<TreeNode*>(forest)

        //we will push all to_delete, in a set, u can also do in vector cuz there is no dups, yet we will do in sets
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        //we will also create the ector<TreeNode*>, which will be returned in the end, like the final ans
        vector<TreeNode*> forests;

        //now we will start the DFS/recurssion, and return a new tree, where the deleted nodes r removed from teh tree
        TreeNode* newRoot = delNodesHelper(root, to_delete_set, forests);

        //now we will check if the old root is still attached, if so push it in the forests vector<TreeNode*
        if(newRoot) forests.push_back(newRoot);

        return forests;
    }
};