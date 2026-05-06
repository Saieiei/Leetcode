//ulta q
//DFS
class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>>& adjList, vector<bool>& isVisited, int& ans){
        //dont have to check if its safe
        //just mark it as visited

        //explore nbrs if not visited
        for(const pair<int, int>& nbr: adjList[node]){
            int nbrNode = nbr.first;
            int nbrCost = nbr.second;
            if(!isVisited[nbrNode]){
                //mark it as visited and push it in
                isVisited[nbrNode] = true;
                ans += nbrCost;
                dfs(nbrNode, adjList, isVisited, ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        //create adjList and indegerees
        vector<vector<pair<int, int>>> adjList(n); //{node, cost}

        //before that we will take this Q as, 0 -> to all possibel nodes
        for(const vector<int>& connecton: connections){
            int u = connecton[0];
            int v = connecton[1];
            //u->v is costly for us (ulta)
            //v->u is what we r expecting
            adjList[u].push_back({v, 1});
            adjList[v].push_back({u, 0});
        }

        int ans = 0;
        vector<bool> isVisited(n, false);
        //we wish to move from 0 to all possible nodes
        int startingNode = 0;
        isVisited[startingNode] = true;
        dfs(startingNode, adjList, isVisited, ans);
        return ans;
    }
};