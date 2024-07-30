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
//week14
    void StoreInorder(TreeNode* root, vector<int>& inorder)
    {
        //perform inorder
        //base case
        if(!root) return;
        //L
        StoreInorder(root->left, inorder);
        //N
        inorder.push_back(root->val);
        //R
        StoreInorder(root->right, inorder);
    }
    bool findTarget(TreeNode* root, int k) {
        //this can be done using inorder
        //,ake the inorder vector (y inorder? because it will be in ascending order and we can apply 2 pointers on it)
        //then use 2 pointers approach on the inorder vector
        //simple

        vector<int> inorder;
        StoreInorder(root, inorder);
        //2 sum pointers approach
        int start = 0;
        int end = inorder.size() - 1;

        while(start < end)
        {
            int sum = inorder[start] + inorder[end];
            if(sum == k) return true;
            else if(sum > k) end--;
            else if(sum < k) start++;
        }
        return false;
    }
};