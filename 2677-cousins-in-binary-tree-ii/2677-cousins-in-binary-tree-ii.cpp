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
    TreeNode* replaceValueInTree(TreeNode* root) {
        //its little difficult to understand but if u take pen and paper u will be able to do
        //so 1st we will do is bfs
        //bfs will be done with the help of the queue
        //during bfs, we will have parent and child values
        //the queue will have the pair of node and the parent
        //the 1st pair will be the root and null ptr
        //the parent node will be mapped with its sum (children sum) (this will be used in later stage, to calc the new node values)
        //then we will traverse level wise and get total value
        //in the same process but in the subsequents child values
        //each level we also put the nodes in a vector, cuz we have to chnage their values

        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, nullptr});

        //now we will start the bfs traversal
        while(!q.empty())
        {
            long long total_level_sum = 0;
            vector<pair<TreeNode*, TreeNode*>> current_level_nodes;
            unordered_map<TreeNode*, long long> parent_sum;

            //1 level at a time
            int size = q.size();  //make sure to write it SEPARATELY like this, else ur q.size(); will get updated dynamically and will ruin ur bfs
            for(int i=0; i<size; i++)
            {
                auto node_parent = q.front(); q.pop();
                TreeNode* node = node_parent.first;
                TreeNode* parent = node_parent.second;
                current_level_nodes.push_back({node, parent}); // this will be used later for chnaging the nodes values

                //now we will find out the sum at this level
                if (parent) {
                    parent_sum[parent] += node->val; //this will be used later for chnaging the nodes values
                }
                total_level_sum += node->val;

                //in the process we will push in the next next nodes, for next level traversal in the queue
                if (node->left) {
                    q.push({node->left, node});
                }
                if (node->right) {
                    q.push({node->right, node});
                }
            }
            
            // Update node values based on cousin sums
            for (auto &pair : current_level_nodes) 
            {
                TreeNode* node = pair.first;
                TreeNode* parent = pair.second;
                if (parent) 
                {
                    node->val = total_level_sum - parent_sum[parent]; //this is the main logic
                } 
                else 
                {
                    // Root node has no cousins
                    node->val = 0;
                }
            }

        }

        return root;

    }
};