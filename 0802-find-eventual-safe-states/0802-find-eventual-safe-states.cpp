//DFS
class Solution {
public:

    bool dfs(int node, vector<vector<int>>& adjList, vector<bool>& isVisited, vector<bool>& isPathVisited, vector<bool>& isSafe){
        //mark it as vivisted
        isVisited[node] = true;
        isPathVisited[node] = true;
        //initially we will mark it as unsafe
        isSafe[node] = false;

        //explore its nbrs
        for(const int nbrNode: adjList[node]){
            if(!isVisited[nbrNode]){
                if(dfs(nbrNode, adjList, isVisited, isPathVisited, isSafe)){
                    //cycle found
                    return true;
                }
            }
            //cycle, cuz its in the path
            else if(isPathVisited[nbrNode]){
                return true;
            }
        }
        //else
        isPathVisited[node] = false;
        isSafe[node] = true;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //isVisited, isPathVisited, check
        int n = graph.size();
        //vector<vector<int>> adjList(n);
        //for(vector<int> connection: graph){
        //    int u = connection[0];
        //    int v = connection[1];
        //    //directed
        //    adjList[u].push_back(v);
        //}

        vector<bool> isVisited(n, false);
        vector<bool> isPathVisited(n, false);
        vector<bool> isSafe(n, 0); 

        //dfs
        for(int i=0; i<n; i++){
            //dont worry about the return value from dfs
            int node = i;
            dfs(node, graph, isVisited, isPathVisited, isSafe);
        }

        //process the ans vector in ascending order
        vector<int> safeNodeAns;
        for(int i=0; i<n; i++){
            int node = i;
            if(isSafe[node] == true){
                safeNodeAns.push_back(node);
            }
        }

        return safeNodeAns;
    }
};