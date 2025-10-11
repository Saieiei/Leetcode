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

    int getMaxNode(TreeNode* root)
    {
        if(root == NULL)return -1;

        while(root->right != NULL) root = root->right;
            
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case
        if(root == NULL)return NULL;

        //4 cases in total
        if(root->val == key)
        {
            //4 cases in total
            //1st case: no child
            if(root->left == NULL && root->right == NULL)
            {
            delete root;
            return NULL;
            }

            //2nd case: 1 child(left or right)
            if(root->left != NULL && root->right == NULL)
            {
                TreeNode* temp = root;
                TreeNode* child = temp->left;
                temp->left = NULL;
                delete temp;
                return child;
                
            }
            if(root->left == NULL && root->right != NULL)
            {
                TreeNode* temp = root;
                TreeNode* child = temp->right;
                temp->right = NULL;
                delete temp;
                return child;
            }

            //3rd case both the child exits (root)
                //in this case we have to take the largest element in the LST and put that as root
                //then we have to also delete that largest element in the LST
            if(root->left != NULL && root->right != NULL)
            {
                int largestNodeInLST = getMaxNode(root->left);
                root->val = largestNodeInLST;
                root->left = deleteNode(root->left, largestNodeInLST);
                return root;
            }
            
        }
        else //use BST property
        {
            if(key > root->val) root->right = deleteNode(root->right, key);
            else root->left = deleteNode(root->left, key);
        }
        return root;
    }
};