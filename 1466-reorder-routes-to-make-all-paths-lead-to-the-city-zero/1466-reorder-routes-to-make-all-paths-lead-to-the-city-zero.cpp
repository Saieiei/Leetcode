//BFS
class Solution {
public:

    int minReorder(int n, vector<vector<int>>& connections) {
        //creste adjList
        vector<vector<pair<int, int>>> adjList(n); //u->{v, cost}
        //in the Q
        //u->v cost is 0 (n-1 nodes to 0)
        //but for us we go from v->u (from 0 to n-1 nodes)
        //so u->v cost is 1 for us, the rest 0
        for(vector<int> connection: connections){
            int u = connection[0];
            int v = connection[1];
            //u->v is ulta for us
            adjList[u].push_back({v, 1});
            //v->u is correct for us
            adjList[v].push_back({u, 0});
        }
        vector<bool> isVisited(n, false);
        int countAns = 0;

        //bfs
        queue<int> q;
        int startingNode = 0;
        q.push(startingNode);
        isVisited[startingNode] = true;
        //no need of a for loop, not discconected graph
        while(!q.empty()){
            int node = q.front();
            q.pop();
            //process its nbrs
            for(const pair<int, int> nbr: adjList[node]){
                int nbrNode = nbr.first;
                int cost = nbr.second;

                if(!isVisited[nbrNode]){
                    q.push(nbrNode);
                    isVisited[nbrNode] = true;
                    countAns += cost;
                }
            }
        }
        return countAns;

    }
};