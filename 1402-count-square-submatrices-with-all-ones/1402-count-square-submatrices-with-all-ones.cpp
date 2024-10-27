class Solution {
public:
//https://www.youtube.com/watch?v=pSDveWPlnPw
    int countSquares(vector<vector<int>>& matrix) {

        //u cant actually call thiss as DP
        //but what u can say is that u will only understand if u have a pen and a paper
        //the basic concept is that u will have to consider the each element of the matrix as a bottom right corner element
        //so if that element is 1 then only it will be considered
        //then u will find the minimum of the possible submatrix 
        //that is the min of the left, top and diagonal values of the submatrix of the vector of vector
        //then after u get the minimum u will add 1 to it and update the position of that element in the submatrix vector of vector
        //and so on u will will be doing this for each element of the  matrix and updating each element in the submatrix vector of vector
        //the sum of the elements in the submatrix of the vecto of vector will be ur answer
        //u will get to know the logic behind all this if u see the video, for now this is the hard logic.

        int row = matrix.size();
        int col = matrix[0].size();

        //lets create the submatrix
        vector<vector<int>> submatrix(row+1, vector<int>(col+1, 0)); //we write this like this cuz we will be starting a little ahead and not from 0,0
        int ans = 0;
        for(int i=1; i<=row; i++)
        {
            for(int j=1; j<=col; j++)
            {
                if(matrix[i-1][j-1]==1) //only if the diagonal is 1, then only we can make a submatrix
                {
                    submatrix[i][j] = 1 + min({submatrix[i-1][j], submatrix[i][j-1], submatrix[i-1][j-1]});
                    ans = ans + submatrix[i][j];
                }
            }
        }

        return ans;
    }
};