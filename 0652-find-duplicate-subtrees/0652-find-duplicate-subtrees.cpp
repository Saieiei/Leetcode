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
//week13
    vector<TreeNode*> ans;
    unordered_map<string, int> subStringMp; //<roots string representation, freq>
    string preorder(TreeNode* root)
    {
        //1st we will go till the end
        if(!root) return "N";

        //preorder
        //curreent
        string curr = to_string(root->val);
        //left
        string l = preorder(root->left);
        string r = preorder(root->right);
        string s = curr + "," + l + "," + r;

        //now after we have made teh string, we will check if it esxits in the map or not, if not then we will simply add it and put its frequency at 1, if it already exists in the map (frequency == 1), then push the root in the ans vector, and increase the frequency, else we will keep on adding the same thing again and againm we need to add it only once
        if(subStringMp.find(s) != subStringMp.end()) //found it
        {
            if(subStringMp[s] == 1) //came only once till now
                ans.push_back(root);
            subStringMp[s]++;
        }
        else //coudt find
        {
            subStringMp[s] = 1;
        }
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        //we will use map, to check if we have that subtree already or not
        //we will convert that tree into a string, whoch we will put it in the map anc check if we can find it again
        //if we found a subtree which is already present in the map, then we should aonly insert it once
        preorder(root);
        return ans;

    }
};