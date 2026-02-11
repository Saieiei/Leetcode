//its simple only
//we will use dfs
//dfs will travel where ever it gets path to go
//when its unreachable then return (backtracking) so that count increases by 1
//use a loop to get through all the nodes, so nothing is left out, incase unreachable
class Solution {
public:
    void dfs(int src, vector<vector<int>>& isConnected, vector<bool>& visited, int& col){
        //1st mark it as visited
        visited[src] = true;
        //figure out its neighbours and see if reachable (iterate through col)
        for(int j=0; j<col; j++){
            if(!visited[j] && isConnected[src][j] == 1){
                dfs(j, isConnected, visited, col);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int countAns = 0;
        int row = isConnected.size();
        int col = isConnected[0].size();
        vector<bool>visited(row, false);
        //iterate through all the nodes
        for(int i=0; i < col; i++){
            if(!visited[i]){
                dfs(i, isConnected, visited, col);
                countAns++;
            }
        }
        return countAns;
    }
};