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
    void inorderTraversal(TreeNode* root, vector<int>& inorderVector){
        //basecase
        if(!root)return;

        //recursion LNR
        inorderTraversal(root->left, inorderVector);
        inorderVector.push_back(root->val);
        inorderTraversal(root->right, inorderVector);
    }
public:
// O(N) time, O(N) space
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorderVector;
        inorderTraversal(root, inorderVector);

        //2 sum hashMap freq
        unordered_map<int, int>freq;
        for(int i: inorderVector){
            int need = k-i;
            auto it = freq.find(need);
            if(it != freq.end()) return true;
            freq[i]++;
        }
        return false;
    }
};