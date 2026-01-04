//M2 Memoization
//this is same as https://leetcode.com/problems/house-robber/submissions/1860275516/
//we will use include exclude principle
//return the max of it
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

    int recursionMemo(TreeNode* root, unordered_map<TreeNode*, int>& dp){
        //bc
        if(!root) return 0; //if no root(house), no money
        if(dp.find(root) != dp.end()) return dp[root];

        int include = 0, exclude = 0;

        //1st simply rob the root house
        if(root) include  = include + root->val;

        if(root->left) //if left root exists then let recursion solve the rest + we need to add up left and right values
            include = include + recursionMemo(root->left->left, dp) + recursionMemo(root->left->right, dp);
        if(root->right)
            include = include + recursionMemo(root->right->left, dp) + recursionMemo(root->right->right, dp);
        
        exclude = 0 + recursionMemo(root->left, dp) + recursionMemo(root->right, dp);

        dp[root] = max(include, exclude);
        return dp[root];

    }

    int rob(TreeNode* root) {
        //since this is a tree, we cannot use vectors, so we will use map
        unordered_map<TreeNode*, int>dp;
        return recursionMemo(root, dp);
    }
};