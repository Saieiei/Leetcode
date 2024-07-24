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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        //its obiovous we will be using lever order traversal technique
        //we will be using bool lRDir to know wheter to fll from right to left or left to right
        //1t we will go from left to right and then right to left
        vector<vector<int>> ans;
        bool lRDir = true;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            if(!root) return ans;

            int vecSize = q.size();
            vector<int> oneLevel(vecSize);

            for(int i=0; i<vecSize; i++)
            {
                TreeNode* front = q.front();
                q.pop();

                //how r we gonna fill this in the vector oneLevel?
                int index = lRDir ? i : vecSize-i-1;
                oneLevel[index] = front->val;

                //put int the child nodes in the queue
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }

            //toggle the lRDir
            lRDir = !lRDir;
            ans.push_back(oneLevel);
        }
        return ans;
    }
};