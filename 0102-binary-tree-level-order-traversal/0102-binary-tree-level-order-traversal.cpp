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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int>> ans;
        if (!root) return ans;

        
        vector<int>temp;
        while(!q.empty())
        {
            TreeNode* element = q.front();
            q.pop();
            if(element)
            {
                temp.push_back(element->val);

                if(element->left != NULL){
                    q.push(element->left);
                }
                if(element->right != NULL){
                    q.push(element->right);
                }
            }
            else
            {
                ans.push_back(move(temp));
                temp.clear();  
                if(!q.empty()) q.push(NULL);
            }
        }
        return ans;
    }
};