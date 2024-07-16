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
    void pathSumHelper(TreeNode* root, int targetSum, vector<int> temp, vector<vector<int>>& ans, int sum)
    {
        //base case
        if(root == NULL) return;

        //solve 1 case
        sum = sum + root->val;
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL)
        {
            if(targetSum == sum) ans.push_back(temp);
            else return;
        }

        //recurssion
        pathSumHelper(root->left, targetSum, temp, ans , sum);
        pathSumHelper(root->right, targetSum, temp, ans , sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        //we  will solve this using recurssion
        vector<int> temp;
        vector<vector<int>> ans;
        int sum = 0;
        pathSumHelper(root, targetSum, temp, ans , sum);
        //ans will be passed as call bby reference, hence no need of any return data type
        return ans;
        
    }
};