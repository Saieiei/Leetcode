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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //the main thing is that the result needs to be in sorted order
        //hence we can use map and multiset
        //multiset has a property that will allow duplicates to stay in it and also it will be in sorted order
        //1st we  will create a pair <root, pair<<row, col>>> 
        //2nd we will create a map <col, <map<row,multiset>>>

        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;//<root, <row, col>>
        map<int, map<int, multiset<int>>> mp;//<col->, row->, [a,b,c,...]>
        //lets push in the 1st value in the queue
        q.push({root, {0,0}});
        while(!q.empty()) //BFS
        {
            auto front = q.front(); //<root, <row, col>>
            q.pop();
            TreeNode* node = front.first; 
            auto coordinate = front.second;
            int row = coordinate.first;
            int col = coordinate.second;
            mp[col][row].insert(node->val); //since this is a multiset, we have to use insert and not push
            //now do it for the rest
            if(node->left) q.push({node->left, {row+1, col-1}});
            if(node->right) q.push({node->right, {row+1, col+1}});
        }

        //ok now transfer the values into ans, by iterating through the mp
        for(auto it: mp)
        {
            auto colMp = it.second;
            vector<int> vLine;
            for(auto colMpIt: colMp)
            {
                auto sett = colMpIt.second;
                vLine.insert(vLine.end(), sett.begin(), sett.end());
            }
            ans.push_back(vLine);
        }
        return ans;
    }
};