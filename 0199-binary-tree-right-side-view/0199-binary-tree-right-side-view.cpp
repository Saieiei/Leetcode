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
  //we will basically do level order traversal with NULL
  //then simply return the 1st of every vector
    vector<int> rightSideView(TreeNode *root) {
        vector<vector<int>> LOT;
        vector<int> temp;
        vector<int> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        if(root == NULL) return ans;
        
        while(!q.empty())
        {
            TreeNode* elementNode = q.front();
            q.pop();
            if(elementNode)
            {
                temp.push_back(elementNode->val);
                if(elementNode->right) q.push(elementNode->right);
                if(elementNode->left) q.push(elementNode->left);
            }
            else
            {
                LOT.push_back(move(temp));
                temp.clear();
                if(!q.empty()) q.push(NULL);
            }
        }
        
        for(int i=0; i<LOT.size(); i++)
        {
            ans.push_back(LOT[i][0]);
        }
        return ans;
        
    }
};