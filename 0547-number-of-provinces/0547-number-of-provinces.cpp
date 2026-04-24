//we will work with adjList here
//u can traverse through the matrix it self,
//and not use adjList
//the rest is simple DFS
class Solution {
public:
    void dfs(int i, vector<bool>& isVisited, vector<vector<int>>& isConnected, vector<vector<int>>& adjList){
        //1st mark it as visited
        isVisited[i] = true;
        //explore its nbrs
        for(int nbr: adjList[i]){
            if(!isVisited[nbr]){
                dfs(nbr, isVisited, isConnected, adjList);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);
        //traverse through the data
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                //get the the node
                //not using nodeID
                if(i != j && isConnected[i][j] == 1){
                    adjList[i].push_back(j);
                }
            }
        }

        //dfs
        int countAns = 0;
        vector<bool> isVisited(n, false);
        for(int i=0; i<n; i++){
            if(!isVisited[i]){
                dfs(i, isVisited, isConnected, adjList);
                countAns++;
            }
        }
        return countAns;
    }
};