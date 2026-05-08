//there is a cycle anyways -> topological sorting
//and per 1 disconnected graph, there might be 1 ctcle
//because it says that there is only atmost 1 outgoing edge
//so we dont have to create adjList because given data is enough
//we need to keep track of the dists, for each noce, so we need dist[]
//DFS
class Solution {
public:
    //in this DFS, we dont have to return anything
    //if we the DFS return bool, then it will stop early
    //because of which we will not be able to get the correct size
    void dfs(int currLen, int& ans, vector<int>& edges, vector<bool>& isVisited, 
    vector<bool>& isPathVisited, int node, vector<int>& dist){
        //1st mark it as visited
        isVisited[node] = true;
        isPathVisited[node] = true;
        currLen++;
        dist[node] = currLen;
        //explore nbrs
        int nbr = edges[node];
        //imp
        if(nbr != -1){
            if(!isVisited[nbr]){
                //check for cycle, but dont stop early
                dfs(currLen, ans, edges, isVisited, isPathVisited, nbr, dist);
            }
            else{
                if(isPathVisited[nbr]){
                    //cycle found
                    int cycleLen = currLen - dist[nbr]  +1;
                    ans = max(ans, cycleLen);
                }
            }
        }
        //backtracking
        isPathVisited[node] = false;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> isVisited(n, false);
        vector<bool> isPathVisited(n, false);
        vector<int> dist(n, 0);
        int ans = -1;
        int currLen = 0;

        //start DFS, disconnected
        for(int i=0; i<n; i++){
            int node = i;
            int currLen = 0;
            if(!isVisited[node]){
                dfs(currLen, ans, edges, isVisited, isPathVisited, node, dist);
            }
        }
        return ans;
    }
};