class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int startRow = 0;
        int endRow = m-1;
        int startCol = 0;
        int endCol = n-1;

        vector<int> ans;

        //start the process
        while((startRow<=endRow) && (startCol<=endCol)){
            //1st move right, explore cols, increase startRow
            for(int i=startCol; i<=endCol; i++){
                ans.push_back(matrix[startRow][i]);
            }
            startRow++;
            //2nd move down, explore rows, decrease endCol
            for(int i=startRow; i<=endRow; i++){
                ans.push_back(matrix[i][endCol]);
            }
            endCol--;
            //3rd move left, explore cols, decrease endRow
            //but safety check, for 1x3 matrix
            //require more rows
            if(startRow<=endRow){
                for(int i=endCol; i>=startCol; i--){
                    ans.push_back(matrix[endRow][i]);
                }
            }
            endRow--;
            //4th move up, explore rows, increase startCol
            //but safetly check, for 3x1 matrix
            //require more cols
            if(startCol<=endCol){
                for(int i=endRow; i>=startRow; i--){
                    ans.push_back(matrix[i][startCol]);
                }
            }
            startCol++;
        }
        return ans;
    }
};