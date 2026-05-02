//dfs
class Solution {
public:
    void dfs(int src, int n, vector<vector<int>>& graph, vector<int>& tempPath, vector<vector<int>>& ans, vector<bool>& isVisited){
        //check if already visited
        if(isVisited[src] == true){
            return;
        }

        //all safe now
        //mark it as visited
        isVisited[src] = true;
        tempPath.push_back(src);

        //check we have reached the end
        if(src == n-1){
            ans.push_back(tempPath);
        }

        //explore its nbrs now
        for(int nbr: graph[src]){
            dfs(nbr, n, graph, tempPath, ans, isVisited);
        }

        //backtracking
        //mark it as unvisited for others paths to visit it
        isVisited[src] = false;
        //pop it
        tempPath.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();

        //no need of adjList
        //the given data is already adjList

        //isVisited is actually not needed
        //because it is a DAG
        vector<bool> isVisited(n, false);

        vector<int> tempPath;
        vector<vector<int>> ans;
        int src = 0;

        //start the process
        dfs(src, n, graph, tempPath, ans, isVisited);
        return ans;
    }
};