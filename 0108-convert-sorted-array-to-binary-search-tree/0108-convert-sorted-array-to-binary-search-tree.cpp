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

    TreeNode* sortedArrayToBSTHelper(vector<int> nums, int start, int end)
    {
        //basecase
        if(start>end)return NULL;

        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        //recursion
        root->left = sortedArrayToBSTHelper(nums, start, mid-1);
        root->right = sortedArrayToBSTHelper(nums, mid+1, end);

        //backtrack
        return root;
    }

    //the intuition comes when u take the middle ele of the vector it makes sense
    //the left of the middle ele is gonna be the LST
    //and the right if the middle ele is gonna be the RST
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int start = 0; int end = nums.size()-1;
        TreeNode* root = sortedArrayToBSTHelper(nums, start, end);
        return root;
    }
};