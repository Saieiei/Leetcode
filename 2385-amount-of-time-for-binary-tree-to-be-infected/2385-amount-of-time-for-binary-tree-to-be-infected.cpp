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

    TreeNode* makeNodeToParentMappingAndFindTargetNode(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap, int target){
        //we will do this using level orderTraversal
        queue<TreeNode*> q;
        q.push(root);
        parentMap[root] = nullptr;
        TreeNode* targerNode = nullptr;

        while(!q.empty())
        {
            TreeNode* frontElement = q.front(); q.pop();
            if(frontElement->val == target) targerNode = frontElement;
            if(frontElement->left){
                q.push(frontElement->left);
                parentMap[frontElement->left] = frontElement;
            }
            if(frontElement->right){
                q.push(frontElement->right);
                parentMap[frontElement->right] = frontElement;
            } 
        }
        return targerNode;
    }
    int burnTreeTime(unordered_map<TreeNode*, TreeNode*>& parentMap, TreeNode* targerNode){
        //remember we have to burn the tree simultaneously, so make sure to take in the size of the q, (for loop)
        unordered_map<TreeNode*, bool>isBurnt; //visited 
        queue<TreeNode*> q; q.push(targerNode); isBurnt[targerNode] = 1;
        int time = 0;

        while(!q.empty())
        {
            int size = q.size();
            bool isFireSpredded = 0;
            for(int i=0; i<size; i++)
            {
                TreeNode* front = q.front(); q.pop();
                if(front->left && !isBurnt[front->left]){
                    q.push(front->left);
                    isBurnt[front->left]=1;
                    isFireSpredded =1;
                }
                if(front->right && !isBurnt[front->right]){
                    q.push(front->right);
                    isBurnt[front->right]=1;
                    isFireSpredded =1;
                }
                if(parentMap[front] && !isBurnt[parentMap[front]]){
                    q.push(parentMap[front]);
                    isBurnt[parentMap[front]]=1;
                    isFireSpredded =1;
                }
            }
            if(isFireSpredded) time++;
        }
        return time;

    }

    int amountOfTime(TreeNode* root, int target) {
        unordered_map<TreeNode*, TreeNode*> parentMap;

        TreeNode* targerNode = makeNodeToParentMappingAndFindTargetNode(root, parentMap, target);

        return burnTreeTime(parentMap, targerNode);
    }
};