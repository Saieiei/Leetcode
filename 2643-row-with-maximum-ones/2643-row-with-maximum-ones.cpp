class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        //matrix cannot be squed
        int m = mat.size();
        int n = mat[0].size();
        //this is simple matrix traversal
        //O(MN)
        int maxOnes = 0;
        int maxRow = 0;
        //traverse through the matrix
        for(int i=0; i<m; i++){
            //traverse through the cols
            int count = 0;
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1){
                    count++;
                }
            }
            if(maxOnes < count){
                //update
                maxOnes = count;
                maxRow = i;
            }
        }
        return {maxRow, maxOnes};
    }
};