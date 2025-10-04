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
//the concept is not intuituve
//use a predecxessor and a current
//make the predecessor to go left then keep on going right
//the right of the predecessor connect to currecnt right
//current left becomes current right
//currect left becomes null
//then move current to currents right

    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while(curr)
        {
            if(curr->left)
            {
                TreeNode* predecessor = curr->left;
                while(predecessor->right) predecessor = predecessor->right;

                predecessor->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr= curr->right;
                
        }
    }
};