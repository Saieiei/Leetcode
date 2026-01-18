//M1 Recursion
//traverse throught 1->n
//leftside recrision, right side recursion
//n^2 loop to find all the possiblilities
//pushback the ans in the vector
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
    vector<TreeNode*> recursion(int start, int end){
        //bc
        if(start > end) return {0}; //{NULL} or {nullptr}
        if(start == end){ // return {new treenode(start)};
            TreeNode* root = new TreeNode(start);
            return {root};
        }

        vector<TreeNode*> ans;
        for(int i = start; i <= end; i++){
            vector<TreeNode*> left = recursion(start, i - 1);
            vector<TreeNode*> right = recursion(i + 1, end);
            for(int j = 0; j <= left.size() - 1; j++){
                for(int k = 0; k <= right.size() - 1; k++){
                    TreeNode* root = new TreeNode(i);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root); //inside the loops
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        //bc
        if (n == 0) return {}; //empty vector
        int start = 1, end = n;
        return recursion(start, end);
    }
};