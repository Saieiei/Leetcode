#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int maze[][4], int row, int col, int x, int y, int newx, int newy, vector<vector<bool>> &visited)
{
    //if the new coordinate is within the maze 
    if(newx>=0 && newx<row && 
    newy>=0 && newy<col && 
    // and the new coordinate is not visited
    visited[newx][newy]==false && 
    // and the new coordinate is not blocked
    maze[newx][newy]==1)
    {
        return true;
    }
    return false;
}

void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, vector<vector<bool>> &visited, string &outputPath)
{
    //base case
    //if we reach the destination, destination coordinate is [row-1][col-1]
    if(srcx==row-1 && srcy==col-1)
    {
        cout<<outputPath<<endl;
        return;
    }

    //calculations
    
    //up
    //dont see it as x and y coordinates, see it as row and col
    int newx=srcx-1;
    int newy=srcy;
    if(isSafe(maze, row, col, srcx, srcy, newx, newy, visited))
    {
        //mark the new coordinate as visited
        visited[newx][newy]=true;
        //add the direction to the output path
        outputPath.push_back('U');
        //recursive call
        printAllPath(maze, row, col, newx, newy, visited, outputPath);
        //backtrack
        //mark the new coordinate as unvisited and remove the direction from the output path
        visited[newx][newy]=false;
        outputPath.pop_back();
    }

    //right
    //dont see it as x and y coordinates, see it as row and col
    newx=srcx;
    newy=srcy+1;
    if(isSafe(maze, row, col, srcx, srcy, newx, newy, visited))
    {
        //mark the new coordinate as visited
        visited[newx][newy]=true;
        //add the direction to the output path
        outputPath.push_back('R');
        //recursive call
        printAllPath(maze, row, col, newx, newy, visited, outputPath);
        //backtrack
        //mark the new coordinate as unvisited and remove the direction from the output path
        visited[newx][newy]=false;
        outputPath.pop_back();
    }
    

    //down
    //dont see it as x and y coordinates, see it as row and col
    newx=srcx+1;
    newy=srcy;
    if(isSafe(maze, row, col, srcx, srcy, newx, newy, visited))
    {
        //mark the new coordinate as visited
        visited[newx][newy]=true;
        //add the direction to the output path
        outputPath.push_back('D');
        //recursive call
        printAllPath(maze, row, col, newx, newy, visited, outputPath);
        //backtrack
        //mark the new coordinate as unvisited and remove the direction from the output path
        visited[newx][newy]=false;
        outputPath.pop_back();
    }
    

    //left
    //dont see it as x and y coordinates, see it as row and col
    newx=srcx;
    newy=srcy-1;
    if(isSafe(maze, row, col, srcx, srcy, newx, newy, visited))
    {
        //mark the new coordinate as visited
        visited[newx][newy]=true;
        //add the direction to the output path
        outputPath.push_back('L');
        //recursive call
        printAllPath(maze, row, col, newx, newy, visited, outputPath);
        //backtrack
        //mark the new coordinate as unvisited and remove the direction from the output path
        visited[newx][newy]=false;
        outputPath.pop_back();
    }
    
}
int main()
{
    int maze[4][4]={
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1}
    };

    int row=4;
    int col=4;

    int srcx=0;
    int srcy=0;

    string outputPath="";
    
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    //corner cases
    if(maze[srcx][srcy]==0)
    {
        cout<<"No path exists";
        return 0;
    }
    else
    {
        //if there is a possible path then we will 1st make the coordinate [0][0] as visted
        visited[srcx][srcy]=true;
        printAllPath(maze, row, col, srcx, srcy, visited, outputPath);
    }

}