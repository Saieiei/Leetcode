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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //this uses the logic of balancing the trees
        //1st we will check if they r identical
            //if there r, then we will proceed with the LST and the RST
        
        //base cases
        if(!q && !p) return true;
        else if (!p && q || !q && p) return false;
        else{
            if(p->val != q->val) return false;
            else{
                //recursion
                bool LSTVerify = isSameTree(p->left, q->left);
                bool RSTVerify = isSameTree(p->right, q->right);
                //backtracking
                if(LSTVerify && RSTVerify)return true;
                else return false;
            }

        }
    }
};