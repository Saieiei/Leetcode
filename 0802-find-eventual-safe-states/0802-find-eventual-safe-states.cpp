//any node which can cause cycle is not a safe node
//topological sorting
//but safe node is a node which has no outgoing edges
//so its better if we built an adjList in ulta with indegrees
//or use the same data but with outdegrees, which can be challenging
//BFS
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        //bc
        if(n == 1){
            return graph[0];
        }
        //we dont need ulta adjList becase we have to track outdegrees
        //but with indegrees
        //but we have to create indegrees
        vector<vector<int>> adjList(n);
        vector<int> indegrees(n, 0);
        vector<bool> isVisited(n, false);
        for(int i=0; i<n; i++){
            int u = i;
            //explore the nbrs
            for(int nbr: graph[u]){
                adjList[nbr].push_back(u);
                indegrees[u]++;
            } 
        }

        vector<int> ans;
        //BFS
        queue<int>q;
        //push all with indegree 0
        for(int i=0; i<n; i++){
            if(indegrees[i] == 0){
                q.push(i);
                isVisited[i] = true;
            }
        }

        //start the process
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            //this is a safe node, push it in the ans
            ans.push_back(frontNode);
            //explore its nbrs, if not visited
            for(int nbr: adjList[frontNode]){
                //check if already visited
                if(isVisited[nbr] == false){
                    indegrees[nbr]--;
                    if(indegrees[nbr] == 0){
                        q.push(nbr);
                        isVisited[nbr] = true;
                    }
                }
            }
        }

        //we need it in ascending order
        sort(ans.begin(), ans.end());
        return ans;
    }
};