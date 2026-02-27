//DFS
//we will have a tempPath vector and a path vector<vector>
//tempPath will be pushed in path
//it will be pushed when src = dest
//for backtracking we will pop inside the loop
//the loop will traverse through the graph[node]
class Solution {
public:
    void dfs(int src, int dest, vector<int>& tempPath, vector<vector<int>>& path, vector<vector<int>>& graph){
        //1st just puth in the node in the tempPath
        tempPath.push_back(src);
        //u will return when src = dest
        if(src == dest){
            path.push_back(tempPath);
            return;
        }
        for(int nbr: graph[src]){
            dfs(nbr, dest, tempPath, path, graph);
            //backtracking
            tempPath.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> tempPath;
        vector<vector<int>> path;
        int src = 0;
        int dest = graph.size()-1;
        dfs(src, dest, tempPath, path, graph);
        return path;
    }
};