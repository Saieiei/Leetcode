//u should know tarjans algo
//without thats its impossible
class Solution {
public:
    void dfs(int parent, int child, vector<vector<int>>& adjList, vector<int>& tin, vector<int>& low, vector<bool>& isVisited, int& time, vector<vector<int>>& bridgesAns){
        //we dont have to check if its safe or not cuz we have adjListy with is
        //1st mark it as visited
        isVisited[child] = true;
        //update the trackers
        tin[child] = time;
        low[child] = time;
        time++;

        //explore the nbrs
        //child->parent, child->nbr
        for(int nbr: adjList[child]){
            //if nbr is parent then skip
            if(nbr == parent){
                continue;
            }
            //dfs
            if(!isVisited[nbr]){
                dfs(child, nbr, adjList, tin, low, isVisited, time, bridgesAns);

                low[child] = min(low[child], low[nbr]);

                //brige condition
                if(low[nbr]>tin[child]){
                    bridgesAns.push_back({nbr, child});
                }
            }
            else{
                low[child] = min(low[child], tin[nbr]);
            }

        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //create adjList
        vector<vector<int>>adjList(n);
        //traverse through the connections given data
        for(vector<int> connection: connections){
            int u = connection[0];
            int v = connection[1];
            //bidirectional
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        //create the necessary trackers
        vector<int> tin(n, -1);
        vector<int> low(n, -1);
        vector<bool> isVisited(n, false);
        int time = 0;
        vector<vector<int>> bridgesAns;
        //if disconnected graph
        for(int i=0; i<n; i++){
            //process the ones that r not visited
            if(!isVisited[i]){
                int parent = -1;
                int child = i;
                dfs(parent, child, adjList, tin, low, isVisited, time, bridgesAns);
            }
        }
        return bridgesAns;
    }
};