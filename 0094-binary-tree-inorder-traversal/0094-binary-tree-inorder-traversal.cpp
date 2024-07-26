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
   //void inorderTraversalHelper(TreeNode* root, vector<int>& ans)
   //{
   //    if(root == NULL) return;
   //    else
   //    {
   //        //L
   //        inorderTraversalHelper(root->left, ans);
   //        //N
   //        ans.push_back(root->val);
   //        //R
   //       inorderTraversalHelper(root->right, ans);
   //    }
   //}
   //vector<int> inorderTraversal(TreeNode* root) {
   //    //inorderTraversal -> LNR
   //    //we will solve this using recurssion
   //    vector<int> ans;
   //    //we will use a helper function
   //    inorderTraversalHelper(root, ans);
   //    return ans;
   //}
   ////O(N) 
    vector<int> inorderTraversal(TreeNode* root)
    {
        //this is rather moris traverasl
        //we will use this as it is done in O(1) space complexity
        //instrad of backtracking and recurssion, this form the path directly
        //the idea is to go left then keep going right and we also have to make ure that the right of the predecessor is not curr
        vector<int> ans;
        TreeNode* curr = root;

        while (curr) 
        {
            // If there is no left child, visit the current node and go right
            if (curr->left == NULL) 
            {
                ans.push_back(curr->val);
                curr = curr->right;
            } 
            else 
            {
                // Find the inorder predecessor of the current node
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) 
                {
                    pred = pred->right;
                }

                // If the predecessor's right is NULL, set it to current
                // and move to the left subtree
                if (pred->right == NULL) 
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                // If the predecessor's right is already set to current,
                // it means we have visited the left subtree, and we should
                // now visit the current node and then go to the right subtree
                else 
                {
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }

        return ans;
    }
};