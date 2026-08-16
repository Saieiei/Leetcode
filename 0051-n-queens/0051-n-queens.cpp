class Solution {
public:
    void saveBoardinAns(int n, vector<vector<char>>& board, vector<vector<string>>& ans){
        vector<string> tempAns;
        for(int i=0; i<n; i++){
            string rowOutput = "";
            for(int j = 0; j<n; j++){
                rowOutput += board[i][j];
            }
            tempAns.push_back(rowOutput);
        }
        ans.push_back(tempAns);
    }
    bool isSafe(int n, vector<vector<char>>& board, vector<vector<string>>& ans, int i, int j){
        //to check if its safe, we have to explore the 3 directions
        //explore the left horizontal 1st
        int row = i, col = j;
        for(col = j; col>=0; col--){
            if(board[row][col] == 'Q'){
                return false;
            }
        }
        //explore the left top diagonal
        row = i, col = j;
        while(row >= 0 && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row--;
            col--;
        }   
        //explore the left bottom diagonal
        row = i, col = j;
        while(row < n && col >= 0){
            if(board[row][col] == 'Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(int n, vector<vector<char>>& board, vector<vector<string>>& ans, int i, int j){
        //check we have reached the end of the col, if so we can save teh board
        if(j>=n){
            saveBoardinAns(n, board, ans);
            return;
        }
        //traverse through the row and figure out where to place the Q in the row from 0 not i
        for(int row = 0; row<n; row++){
            //1st check if its safe at this position
            if(isSafe(n, board, ans, row, j)){
                //put the quene here, use it
                board[row][j] = 'Q';
                //recurse, move to the next col
                solve(n, board, ans, row, j+1);
                //undo, we have reached the end of the board
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        //we will solve it using recursion
        //create the board of nXn
        vector<vector<char>>board (n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        //ui really dont need i here, but still
        int i=0, j=0; 
        solve(n, board, ans, i, j);
        return ans;
    }
};