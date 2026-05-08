//using DFS better than BFS
//because of ulta adjList and outdegrees -> indegrees
class Solution {
public:
    bool dfs(int node, vector<bool>& isVisited, vector<bool>& isPathVisited, 
    vector<vector<int>>& graph, vector<int>& ans){
        //mark it as visited
        isVisited[node] = true;
        isPathVisited[node] = true;
        //explore the nbrs
        for(int nbr: graph[node]){
            //check if already visited
            if(!isVisited[nbr]){
                //cycle present, DFS
                if(dfs(nbr, isVisited, isPathVisited, graph, ans)){
                    return true;
                }
            }
            else{
                //not visited but check if isPathVisited already
                if(isPathVisited[nbr]){
                    //cycle found
                    return true;
                }

            }
        }
        //backtracking
        isPathVisited[node] = false;
        //this is a safe node
        ans.push_back(node);
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        //dont have to create adjLits here given data is enough
        vector<bool> isVisited(n, false);
        vector<bool> isPathVisited(n, false);
        vector<int> ans;

        //disconnected graph?
        for(int i=0; i<n; i++){
            int node = i;
            if(!isVisited[node]){
                //dont have to worry about the return value
                dfs(node, isVisited, isPathVisited, graph, ans);
            }
        }
        //sort it
        sort(ans.begin(), ans.end());
        return ans;
    }
};