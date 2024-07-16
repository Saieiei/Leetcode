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
//week 13
    int maxDepth(TreeNode* root) {
        ////idk how this works but it works
        ////we will solve this using recurssion
        //if(root == NULL) return 0;
        //else
        //{
        //    int leftHeight = maxDepth(root->left);
        //    int rightHeight = maxDepth(root->right);
        //    return max(leftHeight+1, rightHeight+1); //+1 because of the root
        //}

        //we will solve this with the NULL pointer approach

        //base case
        if(root == NULL) return 0;
        int count = 0;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        count++;

        while(!q.empty())
        {
            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode == NULL) //finished 1 row
            {
                if(!q.empty()) //this is imp, dont forget this
                {
                    q.push(NULL);
                    count++;
                }
            }
            else
            {
                if(frontNode->left != NULL) q.push(frontNode->left);
                if(frontNode->right != NULL) q.push(frontNode->right);
            }
        }
        return count;
    }
};