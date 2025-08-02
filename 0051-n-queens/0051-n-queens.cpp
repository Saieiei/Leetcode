class Solution {
public:
    unordered_map<int, bool> leftHorizontalCheck;
    unordered_map<int, bool> upperDiagonalCheck;
    unordered_map<int, bool> lowerDiagonalCheck;
    void storeSolution(vector<vector<char>> &board, vector<vector<string>> &ans, int n)
    {
        //1st we need to create the string
        vector<string> temp;
        for(int row=0; row<n; row++)
        {
            string output = "";
            for(int col=0; col<n; col++)
            {
                char ch = board[row][col];
                output.push_back(ch);
            }
            //1 string is ready
            temp.push_back(output);
        }
        ans.push_back(temp);
    }
    bool isSafe(vector<vector<char>> &board, int row, int col)
    {
        //int n = board.size();
        ////i need to check 3 directions only, not all 8
        ////left horizontal
        //for(int i=0; i<=col; i++)
        //{
        //    if(board[row][i] == 'Q') return false;
        //}
        ////left upper dia
        //int i = row - 1;
        //int j = col - 1;
        //while(i>=0 && j>=0)
        //{
        //    if(board[i][j] == 'Q') return false;
        //    i--;
        //    j--;
        //}
        ////left lower dia
        //int x = row +1;
        //int y = col -1;
        //while(x<n && y>=0)
        //{
        //    if(board[x][y] == 'Q') return false;
        //    x++;
        //    y--;
        //}

        //leftHorizontal
        if(leftHorizontalCheck[row] == true) return false;
        //upperDiagonal
        if(upperDiagonalCheck[row-col] == true) return false;
        //lowerDiagonal
        if(lowerDiagonalCheck[row+col] == true) return false;
        //there is no attack
        return true;
    } 
    void solve(vector<vector<char>> &board, vector<vector<string>> &ans, int n, int col)
    {
        //base case
        if(col >=n)
        {
            //this means 1 case is ready and we will store it
            storeSolution(board, ans, n);
            return;
        }

        //1 case we will solve, the rest recurssion will see
        for(int row=0; row<n; row++)
        {
            if(isSafe(board, row, col))
            {
                board[row][col] = 'Q';
                leftHorizontalCheck[row]=true;
                upperDiagonalCheck[row-col]=true;
                lowerDiagonalCheck[row+col]=true;
                //the rest recurssion will take care
                solve(board, ans, n, col+1);
                //backtracking
                board[row][col] = '.';
                leftHorizontalCheck[row]=false;
                upperDiagonalCheck[row-col]=false;
                lowerDiagonalCheck[row+col]=false;
            }
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        //n*n board
        vector<vector<string>> ans;
        vector<vector<char>> board (n, vector<char>(n, '.'));
        solve(board, ans, n, 0);
        return ans;
    }
};