//BFS
//reverse topologocal sorting
//any nodes whos indegree is 0 is a safe node
//finaly sort it
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n);
        //reversed adjList
        vector<vector<int>> adjList(n);
        for(int node = 0; node<n; node++){
            for(const int nbr: graph[node]){
                //nbr->node
                adjList[nbr].push_back(node);
                indegree[node]++;
            }
        }
        queue<int> q;
        for(int node=0; node<n; node++){
            if(indegree[node] == 0){
                q.push(node);
            }
        }
        vector<int> safeNodes;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            safeNodes.push_back(frontNode);
            //explore nbrs
            for(const int nbrNode: adjList[frontNode]){
                indegree[nbrNode]--;
                if(indegree[nbrNode] == 0){
                    q.push(nbrNode);
                }
            }

        }
        //sort it
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;

        


    }
};