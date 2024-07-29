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
    bool sol(TreeNode* root, long long int lowerBound, long long int upperBound)
    {
        //base case (leaf node)
        if(!root) return true;

        bool condition1 = root->val > lowerBound;
        bool condition2 = root->val < upperBound;
        bool leftAns = sol(root->left, lowerBound, root->val);
        bool rightAns = sol(root->right, root->val, upperBound);

        if(condition1 && condition2 && leftAns && rightAns) return true;
        else return false;
    }
    bool isValidBST(TreeNode* root) {
        //for the bst to work out, from the left subtree get the maximum element, check if that maximum element is les than the root
        //for the bst to work out, from  the right suntree get the minimum elemnt, check if that minimum element is greater than the root

        long long int negInf = -2147485647; //a little more than int_MIN
        long long int inf= 2147583647; //a little less than int_MAX
        bool ans = sol(root, negInf, inf);
        return ans;
    }
};