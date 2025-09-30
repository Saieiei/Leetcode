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

    void findMinMaxHD(TreeNode* root, int& minHD, int& maxHD, int HD)
    {
        //basecase
        if(root == nullptr) return;

        minHD = min(minHD, HD);
        maxHD = max(maxHD, HD);

        //recursion
        if(root->left) findMinMaxHD(root->left, minHD, maxHD, HD-1);
        if(root->right) findMinMaxHD(root->right, minHD, maxHD, HD+1);
    }

    void collectNodes(vector<pair<int, int>>& temp, int i, TreeNode* root, int HD, int row)
    {
        //basecase
        if(root == nullptr) return;
        if(HD == i) temp.push_back({row, root->val});

        //recursion
        if(root->left) collectNodes(temp, i, root->left, HD-1, row+1);
        if(root->right) collectNodes(temp, i, root->right, HD+1, row+1);
    }

    //we will use the logic of Horizontal Distance HD, (O(n²))
    //1st we will find the minHD and the maxHD (so that we can get the range)
    //then we will do loop from minHD to maxHD and for each i we will push back the temp vector
    //then after 1 loop is completed, we will push the temp vector into the ans vector
    //since we also have to maintain the order ties inside the column, we will take in the rows and its corresponding val in temp pair<rows, val>
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        int minHD = INT_MAX;
        int maxHD = INT_MIN;

        findMinMaxHD(root, minHD, maxHD, 0);

        for(int i=minHD; i<=maxHD; i++)
        {
            vector<pair<int, int>> temp;
            collectNodes(temp, i, root, 0, 0);

            sort( temp.begin(), temp.end(), 
                [](const auto& a, const auto& b){
                    if(a.first != b.first) return a.first<b.first; //rows asc
                    return a.second<b.second; //val asc
                }
            );

           vector<int>rowNodes;

           for(auto it: temp) rowNodes.push_back(it.second);
           ans.push_back(move(rowNodes));
        }
        return ans;
    }
};