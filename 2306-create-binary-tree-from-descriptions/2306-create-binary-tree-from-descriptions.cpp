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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        //1st we will create a binary tree and link them properly
        //each child node will be pushed into a set
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> childNodes;
        //next we will again iterate through the descriptions of the parent, and check if its present in the child list or not
            //if its not present, ,then return that node ans the root of the ans
            //else just return null
        
        //1st lets, cretae a node, whether its child or parent
        //lets iterate through descriptions (multidimentional vector)
        for(const auto& dec: descriptions)
        {
            int parentVal = dec[0];
            int childVal = dec[1];
            bool isLeft = dec[2];

            // If the parent nodes does not exist, create it
            if(nodes.find(parentVal) == nodes.end()) //could not find
            {
                //hece, create it
                nodes[parentVal] = new TreeNode(parentVal);
            }   

            // If the child nodes does not exist, create it
            if(nodes.find(childVal) == nodes.end()) //could not find
            {
                //hece, create it
                nodes[childVal] = new TreeNode(childVal);
            }

            // Link the child to the parent
            if(isLeft)
            {
                //link, the child to the left of the parent
                nodes[parentVal]->left = nodes[childVal];
            }
            else
            {
                //link, the child to the right of the parent
                nodes[parentVal]->right = nodes[childVal];
            }
            // Add the child to the set of children, so that we can keep the track of the root node, as root node can never be the child node
            childNodes.insert(childVal);
        }
        //after we have created the tree successfulyy, and pushed all the childnodes, in the set
        //we will now find the root node
        //again we will traverse through the descriptions
        for(const auto& dec: descriptions)
        {
            int parentVal = dec[0];
            //we will try to find the parentVal in the set of the childNodes
            if(childNodes.find(parentVal) == childNodes.end()) //if we coudnt find
            {
                //then return the root node
                return nodes[parentVal];
            }
        }
        return nullptr; // Should never reach here if input is valid
    }
};