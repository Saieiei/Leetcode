//dfs
//2 colors
//space optimized
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& colors){
        int nodeColor =  colors[node];

        //explore its nbrs
        for(int nbr: graph[node]){
            //explore only if not visited
            if(colors[nbr] == -1){
                //mark it as visited
                colors[nbr] = !nodeColor;
                //CRITICAL
                int ans = dfs(nbr, graph, colors);
                if(ans == false){
                    return false;
                }
            }
            else{ //marked a visited
                if(nodeColor == colors[nbr]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        //no need for adjList
        //given data is sufficeint

        //trackers
        //vector<bool> isVisited(n, false);
        //we will use colors[] as trackers itself
        vector<int> colors(n, -1);
        //-1 indicated no color yet
        //0 is red and 1 is blue
        //!color will change it
        //we will start with red
        int color = 0;

        //since its disconnected graph, we need a for loop
        for(int i=0; i<n; i++){
            //process those only if not visited
            int node = i;
            if(colors[node] == -1){
                //start with dfs
                //mark it as visited
                //give it the color
                colors[node] = color;
                //CRITICAL
                int ans = dfs(node, graph, colors);
                if(ans == false){
                    return false;
                }
            }
        }
        //no cases of false, then return true
        return true;
    }
};