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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        //this 1 is simple only
        //we have to use bfs thats all
        //for every row calc sum and keep it in a vectoir
        //in the end just sort it and print the kth sum

        //u have teh bin tree ready with u
        //traverse the tree
        long long current_sum = 0;
        vector<long long> level_sums;

        //we will be using a queue for bfs
        queue<TreeNode*> q;
        //the 1st element in the q will be the root
        q.push(root);

        //now we will traverse the q
        while(!q.empty())
        {
            current_sum = 0;
            int current_q_size = q.size();
            for(int i=0; i< current_q_size; i++) //this wil help us maintain BFS
            {
                TreeNode* node = q.front();
                q.pop();
                current_sum = current_sum + node->val;

                //now we will add the left node and the right node to the queue
                if(node->left != NULL)
                {
                    q.push(node->left);
                }
                if(node->right != NULL)
                {
                    q.push(node->right);
                }
            }
            
            //insert the sum of that row in the vector
            level_sums.push_back(current_sum);
        }

        //now we will sort it to find the kth sum in decending order
        sort(level_sums.begin(), level_sums.end(), greater<long long>());

        //return the kth element
        if(level_sums.size()>=k)
            return level_sums[k-1];
        else return -1;

    }
};