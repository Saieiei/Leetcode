//simple dfs traversal
//without creating adjList
class Solution {
public:
    void dfs(int i, int& n, vector<vector<int>>& isConnected, vector<bool>& isVisited){
        //ASAP, mark is visited
        isVisited[i] = true;
        //explore its nbrs
        for(int j=0; j<n; j++){
            if(!isVisited[j] && isConnected[i][j] == 1){
                dfs(j, n, isConnected, isVisited);                                               
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int countAns = 0;
        //its a dfs, so we need isVisited
        //nxn matrix
        int n = isConnected.size();
        vector<bool> isVisited(n, false);
        //traverse though each node
        for(int i=0; i<n; i++){
            if(!isVisited[i]){
                dfs(i, n, isConnected, isVisited);
                countAns++;
            }
        }
        return countAns;
    }
};